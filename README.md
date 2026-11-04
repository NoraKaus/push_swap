_This project has been created as part of the 42 curriculum by ezaimaki, ekausiny_

## push_swap 

## Description

The goal of this project was to sort a list of integers in ascending order in **stack a**, using only **stack a**, **stack b** and a limited set of operations.
The program analyses the input, chooses a sorting strategy, depending on the user's input, and prints the sequence of operations that sorts the stack, one per line.

#### Available operations

`sa (swap a)` Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.

`sb (swap b)`: Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.

`ss` : sa and sb at the same time.

`pa (push a)`: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

`pb (push b)`: Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

`ra (rotate a)`: Shift up all elements of stack a by one.
The first element becomes the last one.

`rb (rotate b)`: Shift up all elements of stack b by one.
The first element becomes the last one.

`rr` : ra and rb at the same time.

`rra (reverse rotate a)`: Shift down all elements of stack a by one.
The last element becomes the first one.

`rrb (reverse rotate b)`: Shift down all elements of stack b by one.
The last element becomes the first one.

`rrr` : rra and rrb at the same time

### Disorder metric 

Disorder was measured with a number between 0 (sorted) and 1 (reverse sorted, furthest away from being sorted). It is calculated as the ratio of out-of-order pairs to the total number of pairs in the input. It is computed once, before any operation is made, and is used by the adaptive mode to pick a strategy.

### Algorithm selection

Four strategies were implemented: three sorting algorithms and an adaptive mode that chooses between them.
Very small inputs (up to 5 numbers) are handled by a dedicated short sort that uses a minimal, hard-coded set of moves.

#### Simple

`Min extraction` 
_Time complexity - O(n2)_
_Space complexity - O(1)_
It operates by finding smallest int and moving it to stack b, till stack a is empty, then moving all values back to stack a.   
It is very effective on small or nearly sorted lists, but becomes inefficient on large lists.

#### Medium 

`K-Distribution sort` 
_Time complexity - O(n√n)_  
_Space complexity - O(1)_
It operates by iteratively pushing elements from stack A to stack B, using a growing threshold to decide which elements to transfer and how to place them within B. The technique is particularly known for shaping stack B into a "K-like" structure when visualized—hence the name.
Best suited for n = [50, 500] elements in push_swap projects, though it remains effective and reliable for a broader range from around 10 to 1000 elements.

#### Complex

`Radix sort` - (binary, LSD) 
_Time complexity - O(n · k), where k is the number of bits. Since values are first replaced by their index (0 to n-1), k = log₂ n, giving O(n log n)_  
_Space complexity - O(n) for the indexing_   
It operates by sorting numbers bit by bit, starting from the least significant bit (rightmost) to the most significant bit(leftmost).  
For each bit, numbers with a 0 are pushed to stack b and numbers with a 1 are rotated, then everything is pushed back to a.
It is predictable and efficient for large sets of numbers. 

#### Adaptive (default)

Chooses the strategy based on the disorder of the input:
- low disorder (< 0.2) → simple
- medium disorder (0.2 – 0.5) → medium
- high disorder (≥ 0.5) → complex

## Instructions 
```bash
make          # compiles the push_swap
make clean    # removes the .o files
make fclean   # removes the .o files and push_swap
make re       # recompiles everything from scratch

```
#### Run
```bash
./push_swap 2 1 3                              # prints the operations
./push_swap --medium 5 2 9 1                   # forces a specific strategy
```

#### Test with random numbers
```bash
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')     # 100 random unique numbers
./push_swap $ARG | ./checker_linux $ARG         # check the result
./push_swap $ARG | wc -l                        # count the operations
./push_swap --bench $ARG > /dev/null            # show only the benchmark
```

#### Error handling
The program prints `Error` to stderr for non-integer input, values outside the int range, or duplicates. With no arguments, it prints nothing.
```bash
./push_swap 1 2 2       # Error (duplicate)
./push_swap 1 two 3     # Error (not a number)
```

## Flags

Flags are placed before the numbers. Only one strategy flag can be used at a time.

| Flag | Description |
|------|-------------|
| `--simple` | Forces min extraction, O(n²) |
| `--medium` | Forces K-distribution sort, O(n√n) |
| `--complex` | Forces radix sort, O(n log n) |
| `--adaptive` | Picks a strategy based on the disorder metric (default when no flag is given) |
| `--bench` | Prints to stderr the disorder, the strategy used, the total number of operations and the count of each operation. Can be combined with a strategy flag |

## Work distribution

We started by discussing the project and outlining the steps we'll need to take to solve it. We've split the project into smaller funtions that will be needed to run it and split them between each other.

ekausiny
- Error handling
- Input validation
- flag processing
- input conversion to int
- medium sort
- short sort
- picking of alorithms
- bonus checker
- makefile

ezaimaki
- disorder measure
- duplicate checker
- push / swap / rotates build and definition
- list build and processing
- simple sort
- complex sort
- bench
- bonus checker
- makefile

Throughout the project we've reached out to each other if we needed any help with writing functions, or to further clarify the layout of the project

## Resources
[DeepWiki graphs](https://deepwiki.com/tdanielsousa/42School/4.3.5-push_swap-utilities-and-build-system) to visualise the structure of the project
[K-sort](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376) algorithm resources
[Radix sort](https://medium.com/@drwasimahmadkhan/radix-sort-8f203467c642) [Radix GeekForGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/) algorithm resources

**AI usage:** AI was used for to build some of the test functions, to visualise and explain some of the sorting alorithms. 
All code was written and understood by the authors.

