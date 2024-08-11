NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCEFILES = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putptr.c\
				ft_puthex.c ft_putunsigned.c \

OBJ = $(SOURCEFILES:.c=.o)

$(NAME) : $(OBJ)
	ar -rcs $@ $(OBJ)

%.o : %.c
	$(CC) -c $(CFLAGS) $?

re : fclean all

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

.PHONY : all clean fclean re