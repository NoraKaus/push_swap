NAME = libftprintf.a

SRC = ft_printf.c helpers.c printings.c ft_putptr.c

OBJ = $(SRC:.c=.o)

HDR = ft_printf.h

LIB = lib/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cp $(LIB) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HDR)
	cc $(CFLAGS) -c $< -o $@

$(LIB):
	$(MAKE) -C lib

clean:
	rm -f $(OBJ)
	$(MAKE) -C lib clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C lib fclean

re: fclean
	$(MAKE)