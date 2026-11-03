NAME = push_swap

SRC = $(wildcard *.c)

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