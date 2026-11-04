NAME = push_swap

NAMEBONUS = checker

SRC = bench.c error_handling.c list_utils.c \
medium.c rev_rotates.c simple.c utils.c complex.c \
extract_numbers.c main.c pick_algo.c rotates.c swaps.c \
dup_error.c pushes.c short_sort.c to_list.c

OBJ = $(SRC:.c=.o)

BONUS = bench.c error_handling.c list_utils.c \
medium.c rev_rotates.c simple.c utils.c complex.c \
extract_numbers.c pick_algo.c rotates.c swaps.c \
dup_error.c pushes.c short_sort.c to_list.c \
checker_bonus.c errors_bonus.c read_exec_bonus.c

OBJBNS = $(BONUS:.c=.o)

HDR = push_swap.h checker_bonus.h

LIB = libft/libftprintf.a

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

$(NAMEBONUS): $(OBJBNS) $(LIB)
	cc $(CFLAGS) $(OBJBNS) $(LIB) -o $(NAMEBONUS)

%.o: %.c $(HDR)
	cc $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C libft

bonus: $(NAMEBONUS)

clean:
	rm -f $(OBJ) $(OBJBNS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)
	$(MAKE) -C libft fclean

re: fclean
	$(MAKE)

.PHONY : all clean fclean re bonus