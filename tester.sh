#!/usr/bin/env bash
# ============================================================================
#  push_swap evaluation tester
#
#  Usage:   ./tester.sh [-r RUNS] [-v] [-b]
#     -r RUNS   random runs per benchmark size (default 10)
#     -v        also run valgrind memory checks
#     -b        also test the bonus ./checker
#
#  Put this file in the project folder (next to push_swap and checker_linux),
#  run `make` (and `make bonus` for -b), then: chmod +x tester.sh checker_linux
#  Paths can be overridden: PS=../push_swap CHECKER=./checker_linux ./tester.sh
#
#  Lines marked [OK]/[KO] are graded automatically.
#  Lines marked [..] are for YOU to read and judge.
#  Any input that fails a benchmark is saved to failed_inputs.txt.
# ============================================================================

PS="${PS:-./push_swap}"
CHECKER="${CHECKER:-./checker_linux}"
BONUS="${BONUS:-./checker}"
RUNS=10
DO_VG=0
DO_BONUS=0

while getopts "r:vb" opt; do
	case $opt in
		r) RUNS=$OPTARG ;;
		v) DO_VG=1 ;;
		b) DO_BONUS=1 ;;
		*) echo "usage: $0 [-r runs] [-v] [-b]"; exit 1 ;;
	esac
done

G=$'\e[32m'; R=$'\e[31m'; Y=$'\e[33m'; BOLD=$'\e[1m'; N=$'\e[0m'
PASS=0; FAIL=0
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT
VALID='^(sa|sb|ss|pa|pb|ra|rb|rr|rra|rrb|rrr)$'

ok()      { PASS=$((PASS + 1)); printf "  %s[OK]%s %s\n" "$G" "$N" "$1"; }
ko()      { FAIL=$((FAIL + 1)); printf "  %s[KO]%s %s\n" "$R" "$N" "$1"
            [ -n "$2" ] && printf "       %s\n" "$2"; }
info()    { printf "  %s[..]%s %s\n" "$Y" "$N" "$1"; }
section() { printf "\n%s== %s ==%s\n" "$BOLD" "$1" "$N"; }

command -v timeout >/dev/null || timeout() { shift; "$@"; }

# Random list of N distinct integers (negatives included)
gen() {
	if command -v shuf >/dev/null; then
		seq -100000 100000 | shuf -n "$1" | tr '\n' ' '
	else
		seq -100000 100000 | sort -R | head -n "$1" | tr '\n' ' '
	fi
}

# check_sort FLAG NUMBERS...
# Runs push_swap, verifies every output line is a real operation, then feeds
# the output to the official checker. Sets COUNT and STATUS. Returns 0 on OK.
check_sort() {
	local flag="$1"; shift
	COUNT=0; STATUS=""
	# shellcheck disable=SC2086
	timeout 30 "$PS" $flag "$@" > "$TMP/out" 2> "$TMP/err"
	if [ $? -eq 124 ]; then STATUS="TIMEOUT (>30s)"; return 1; fi
	COUNT=$(wc -l < "$TMP/out" | tr -d ' ')
	if grep -qvE "$VALID" "$TMP/out"; then
		STATUS="invalid output line: '$(grep -vE "$VALID" "$TMP/out" | head -1)'"
		return 1
	fi
	STATUS=$("$CHECKER" "$@" < "$TMP/out" 2>&1)
	[ "$STATUS" = "OK" ]
}

# expect_error DESCRIPTION ARGS...  -> stdout must be empty, stderr exactly "Error"
expect_error() {
	local desc="$1"; shift
	timeout 10 "$PS" "$@" > "$TMP/out" 2> "$TMP/err"
	if [ ! -s "$TMP/out" ] && [ "$(cat "$TMP/err")" = "Error" ]; then
		ok "$desc"
	else
		ko "$desc" "stdout='$(head -c 60 "$TMP/out" | tr '\n' ' ')' stderr='$(head -c 60 "$TMP/err" | tr '\n' ' ')'"
	fi
}

# ---------------------------------------------------------------------------
[ -x "$PS" ]      || { echo "push_swap not found/executable at $PS (run make?)"; exit 1; }
[ -x "$CHECKER" ] || { echo "checker not found/executable at $CHECKER (chmod +x?)"; exit 1; }

# ---------------------------------------------------------------------------
section "1. Error handling (must print Error on stderr, nothing on stdout)"
expect_error "word in list"            0 one 2 3
expect_error "letters after digits"    1 2a 3
expect_error "lone minus"              1 - 3
expect_error "lone plus"               1 + 3
expect_error "double sign"             1 +-5 3
expect_error "empty string"            "" 1
expect_error "INT_MAX + 1"             1 2147483648
expect_error "INT_MIN - 1"             1 -2147483649
expect_error "huge number"             1 99999999999999999999
expect_error "duplicate"               3 2 3
expect_error "duplicate 1 / +1"        1 +1
expect_error "duplicate 1 / 01"        1 01
expect_error "duplicate 0 / -0"        0 -0
expect_error "duplicate with flag"     --simple 3 2 3

"$PS" > "$TMP/out" 2> "$TMP/err"
if [ ! -s "$TMP/out" ] && [ ! -s "$TMP/err" ]; then ok "no arguments -> prints nothing"
else ko "no arguments -> prints nothing"; fi

"$PS" --fast 3 2 1 > "$TMP/out" 2> "$TMP/err"
info "unknown flag '--fast 3 2 1' -> stdout: '$(head -c 40 "$TMP/out" | tr '\n' ' ')' stderr: '$(cat "$TMP/err")'  (judge: Error is expected)"

if check_sort "" 2147483647 -2147483648 0; then ok "INT_MAX and INT_MIN accepted and sorted"
else ko "INT_MAX and INT_MIN accepted and sorted" "$STATUS"; fi

# ---------------------------------------------------------------------------
section "2. Trivial cases (already sorted -> 0 operations)"
for flag in "" --simple --medium --complex --adaptive; do
	check_sort "$flag" 1 2 3 4 5
	if [ "$STATUS" = "OK" ] && [ "$COUNT" -eq 0 ]; then ok "sorted list ${flag:-(default)} -> 0 ops"
	else ko "sorted list ${flag:-(default)} -> 0 ops" "got $COUNT ops, checker: $STATUS"; fi
done
check_sort "" 42
if [ "$STATUS" = "OK" ] && [ "$COUNT" -eq 0 ]; then ok "single number -> 0 ops"
else ko "single number -> 0 ops" "got $COUNT ops"; fi
if check_sort "" 2 1; then ok "two numbers (2 1) -> $COUNT ops"; else ko "two numbers" "$STATUS"; fi

# ---------------------------------------------------------------------------
section "3. Small inputs (correctness graded, op counts for you to judge)"
for flag in "" --simple --medium --complex; do
	max=0; bad=0
	for p in "1 2 3" "1 3 2" "2 1 3" "2 3 1" "3 1 2" "3 2 1"; do
		# shellcheck disable=SC2086
		if check_sort "$flag" $p; then [ "$COUNT" -gt "$max" ] && max=$COUNT
		else bad=$((bad + 1)); fi
	done
	if [ $bad -eq 0 ]; then ok "all 6 permutations of 3 ${flag:-(default)}  (max $max ops)"
	else ko "permutations of 3 ${flag:-(default)}" "$bad failed"; fi
done
max=0; bad=0
for ((i = 0; i < 20; i++)); do
	# shellcheck disable=SC2046
	if check_sort "" $(gen 5); then [ "$COUNT" -gt "$max" ] && max=$COUNT; else bad=$((bad + 1)); fi
done
if [ $bad -eq 0 ]; then ok "20 random lists of 5 (max $max ops)"; else ko "random lists of 5" "$bad failed"; fi

# ---------------------------------------------------------------------------
section "4. Every strategy flag sorts every size"
for flag in --simple --medium --complex --adaptive; do
	bad=0; msg=""
	for n in 2 3 5 10 50 100 500; do
		ARG=$(gen "$n")
		# shellcheck disable=SC2086
		if ! check_sort "$flag" $ARG; then bad=$((bad + 1)); msg="n=$n: $STATUS"; echo "$flag $ARG" >> failed_inputs.txt; fi
	done
	if [ $bad -eq 0 ]; then ok "$flag sorts n = 2,3,5,10,50,100,500"; else ko "$flag" "$bad sizes failed (last: $msg)"; fi
done

# ---------------------------------------------------------------------------
bench_size() {  # size pass good excellent
	local n=$1 lim_pass=$2 lim_good=$3 lim_exc=$4
	local min=999999 max=0 sum=0 bad=0 done_runs=0 i grade ARG
	for ((i = 1; i <= RUNS; i++)); do
		ARG=$(gen "$n")
		# shellcheck disable=SC2086
		if check_sort "" $ARG; then
			sum=$((sum + COUNT)); done_runs=$((done_runs + 1))
			[ "$COUNT" -lt "$min" ] && min=$COUNT
			[ "$COUNT" -gt "$max" ] && max=$COUNT
			[ "$COUNT" -ge "$lim_pass" ] && echo "$ARG" >> failed_inputs.txt
		else
			bad=$((bad + 1)); echo "$ARG" >> failed_inputs.txt
		fi
	done
	if [ $bad -gt 0 ]; then ko "$n numbers: $bad/$RUNS runs NOT sorted" "last status: $STATUS"; return; fi
	if   [ $max -lt "$lim_exc" ];  then grade="excellent (<$lim_exc)"
	elif [ $max -lt "$lim_good" ]; then grade="good (<$lim_good)"
	elif [ $max -lt "$lim_pass" ]; then grade="pass (<$lim_pass)"
	else grade="FAIL (>= $lim_pass)"; fi
	local line="$n numbers x$RUNS: min $min / avg $((sum / done_runs)) / max $max  -> $grade"
	if [ $max -lt "$lim_pass" ]; then ok "$line"; else ko "$line"; fi
}
section "5. Benchmarks (default strategy, worst run counts)"
bench_size 100 2000 1500 700
bench_size 500 12000 8000 5500

# ---------------------------------------------------------------------------
section "6. --bench mode"
ARG=$(gen 100)
# shellcheck disable=SC2086
"$PS" --bench $ARG > "$TMP/bout" 2> "$TMP/berr"
if ! grep -qvE "$VALID" "$TMP/bout" && [ "$("$CHECKER" $ARG < "$TMP/bout")" = "OK" ]; then
	ok "stdout stays clean with --bench (checker OK)"
else ko "stdout stays clean with --bench" "bench text probably leaked into stdout"; fi
missing=""
for op in disorder strategy sa sb ss pa pb ra rb rr rra rrb rrr; do
	grep -qw "$op" "$TMP/berr" || missing="$missing $op"
done
if [ -z "$missing" ]; then ok "stderr contains disorder, strategy and all 11 op counts"
else ko "bench output incomplete" "missing:$missing"; fi
# shellcheck disable=SC2086
"$PS" $ARG > /dev/null 2> "$TMP/err"
if [ ! -s "$TMP/err" ]; then ok "no bench output without --bench"; else ko "stderr not empty without --bench"; fi
info "bench output for a random 100:"; sed 's/^/         /' "$TMP/berr"

disorder_test() {  # expected numbers...
	local exp=$1; shift
	"$PS" --bench "$@" 2>&1 >/dev/null | grep -i disorder > "$TMP/d"
	if grep -q "$exp" "$TMP/d"; then ok "disorder of '$*' = $exp%"
	else ko "disorder of '$*' should be $exp%" "got: $(cat "$TMP/d")"; fi
}
disorder_test "40.00"  4 67 3 87 23
disorder_test "100.00" 5 4 3 2 1
disorder_test "0.00"   1 2 3 4 5
disorder_test "33.33"  2 1 4 3        # 2 inversions out of 6 pairs

# ---------------------------------------------------------------------------
section "7. Adaptive regime selection (judge: strategy should match disorder)"
show_regime() {  # label numbers...
	local label=$1; shift
	"$PS" --bench --adaptive "$@" 2>&1 >/dev/null | grep -iE "disorder|strategy" | tr '\n' ' ' > "$TMP/r"
	info "$label: $(cat "$TMP/r")"
}
NEAR=$(seq 1 100 | awk 'NR==50{t=$0;next} NR==51{print;print t;next} {print}' | tr '\n' ' ')
# shellcheck disable=SC2086
show_regime "near-sorted (1 swap)   expect <0.2 " $NEAR
# Medium disorder: shuffle inside 2 blocks of 50 -> usually lands around 0.25,
# so the value is printed for you to check against the thresholds.
MED=$(seq 1 100 | awk '{b=int((NR-1)/50); print b*1000 + int(rand()*1000) "." NR}' \
      | sort -n | awk -F. '{print $2}' | tr '\n' ' ')
# shellcheck disable=SC2086
show_regime "block-shuffled         expect ~0.25" $MED
# shellcheck disable=SC2046
show_regime "random                 ~0.5       " $(gen 100)
# shellcheck disable=SC2046
show_regime "reversed               expect 1.0 " $(seq 100 -1 1)

# ---------------------------------------------------------------------------
section "8. Complexity scaling, n=100 -> n=500 (judge against claimed class)"
info "expected growth: O(n^2) ~25x   O(n*sqrt n) ~11x   O(n log n) ~6.7x"
avg_ops() {  # flag size runs
	local s=0 i
	for ((i = 0; i < $3; i++)); do
		# shellcheck disable=SC2046
		check_sort "$1" $(gen "$2"); s=$((s + COUNT))
	done
	echo $((s / $3))
}
for flag in --simple --medium --complex --adaptive; do
	a=$(avg_ops "$flag" 100 3); b=$(avg_ops "$flag" 500 3)
	ratio=$(awk -v a="$a" -v b="$b" 'BEGIN{ if (a>0) printf "%.1f", b/a; else print "n/a" }')
	info "$(printf '%-11s avg@100: %-6s avg@500: %-7s growth: %sx' "$flag" "$a" "$b" "$ratio")"
done

# ---------------------------------------------------------------------------
if [ $DO_VG -eq 1 ]; then
	section "9. Valgrind (leaks + invalid reads/writes, normal AND error paths)"
	if ! command -v valgrind >/dev/null; then
		ko "valgrind is not installed on this machine"
	else
		vg() {  # description args...
			local desc="$1"; shift
			valgrind --leak-check=full --show-leak-kinds=all \
				--errors-for-leak-kinds=definite,indirect,possible \
				--error-exitcode=42 --log-file="$TMP/vg" \
				"$PS" "$@" > /dev/null 2>&1
			if [ $? -eq 42 ]; then
				ko "$desc"
				grep -E "definitely|indirectly|possibly|Invalid|uninitialised|ERROR SUMMARY" "$TMP/vg" \
					| sed 's/^==[0-9]*== /         /' | head -8
			else
				ok "$desc"
				grep -q "still reachable: [1-9]" "$TMP/vg" && info "  (has 'still reachable' memory, check if that matters to you)"
			fi
		}
		R100=$(gen 100)
		# shellcheck disable=SC2086
		vg "random 100 (default)"     $R100
		# shellcheck disable=SC2086
		vg "random 100 --simple"      --simple $R100
		# shellcheck disable=SC2086
		vg "random 100 --medium"      --medium $R100
		# shellcheck disable=SC2086
		vg "random 100 --complex"     --complex $R100
		# shellcheck disable=SC2086
		vg "random 100 --bench"       --bench $R100
		vg "already sorted"           1 2 3 4 5
		vg "single number"            42
		vg "no arguments"
		vg "error: non-numeric"       1 two 3
		vg "error: duplicate"         1 2 1
		vg "error: overflow"          1 2147483648
		vg "error: duplicate at end"  --medium 5 4 3 2 1 5
	fi
fi

# ---------------------------------------------------------------------------
if [ $DO_BONUS -eq 1 ]; then
	section "10. Bonus checker"
	if [ ! -x "$BONUS" ]; then
		ko "bonus checker not found at $BONUS (run make bonus?)"
	else
		bonus_case() {  # description expected_stdout expected_stderr instructions numbers...
			local desc=$1 eout=$2 eerr=$3 ins=$4; shift 4
			printf "%b" "$ins" | timeout 10 "$BONUS" "$@" > "$TMP/out" 2> "$TMP/err"
			if [ "$(cat "$TMP/out")" = "$eout" ] && [ "$(cat "$TMP/err")" = "$eerr" ]; then ok "$desc"
			else ko "$desc" "stdout='$(cat "$TMP/out")' stderr='$(cat "$TMP/err")' (expected '$eout' / '$eerr')"; fi
		}
		bonus_case "subject example -> OK"      "OK" "" "rra\npb\nsa\nrra\npa\n" 3 2 1 0
		bonus_case "subject example -> KO"      "KO" "" "sa\nrra\npb\n"          3 2 1 0
		bonus_case "no instructions, sorted"    "OK" "" ""                       1 2 3
		bonus_case "no instructions, unsorted"  "KO" "" ""                       2 1 3
		bonus_case "a sorted but b not empty"   "KO" "" "pb\n"                   1 2 3
		bonus_case "unknown instruction"        ""   "Error" "foo\n"             2 1 3
		bonus_case "uppercase instruction"      ""   "Error" "SA\n"              2 1 3
		bonus_case "trailing space"             ""   "Error" "sa \n"             2 1 3
		bonus_case "non-numeric argument"       ""   "Error" ""                  3 2 one 0
		bonus_case "duplicate argument"         ""   "Error" ""                  1 2 1
		"$BONUS" < /dev/null > "$TMP/out" 2> "$TMP/err"
		if [ ! -s "$TMP/out" ] && [ ! -s "$TMP/err" ]; then ok "no arguments -> prints nothing"
		else ko "no arguments -> prints nothing"; fi
		ARG=$(gen 100)
		# shellcheck disable=SC2086
		res=$("$PS" $ARG | "$BONUS" $ARG 2>&1)
		if [ "$res" = "OK" ]; then ok "their checker agrees with their push_swap on 100 random"
		else ko "their checker vs push_swap on 100 random" "got '$res'"; fi
	fi
fi

# ---------------------------------------------------------------------------
section "Summary"
printf "  %s%d passed%s, %s%d failed%s\n" "$G" "$PASS" "$N" "$R" "$FAIL" "$N"
[ -s failed_inputs.txt ] && printf "  failing inputs saved in failed_inputs.txt\n"
printf "  Not covered here (check by hand): norminette, Makefile relink, README, globals, defense.\n"
[ $FAIL -eq 0 ]
