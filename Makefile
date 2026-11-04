NAME = push_swap

SRC = bench.c error_handling.c list_utils.c medium.c rev_rotates.c simple.c utils.c complex.c extract_numbers.c main.c pick_algo.c rotates.c swaps.c dup_error.c pushes.c short_sort.c to_list.c

OBJ = $(SRC:.c=.o)

HDR = push_swap.h

LIB = libft/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	cc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o: %.c $(HDR)
	cc $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean
	$(MAKE)