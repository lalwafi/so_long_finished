NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCEFILES = ft_isalnum.c ft_isdigit.c ft_strlen.c  ft_tolower.c \
				ft_isalpha.c ft_isprint.c ft_strncmp.c ft_toupper.c \
				ft_memmove.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c \
				ft_atoi.c ft_isascii.c ft_strchr.c  ft_strrchr.c ft_memset.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
				ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_memchr.c get_next_line_bonus.c \
				get_next_line_utils_bonus.c \

BON_SOURCEFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
					ft_lstmap.c

OBJ = $(SOURCEFILES:.c=.o)

BON_OBJ = $(BON_SOURCEFILES:.c=.o)

# ar is archive, -rcs are separate flags combined (-r -c -s) (do man ar for explanation).
# $@ is the target, here its $(NAME).
$(NAME) : $(OBJ)
	ar -rcs $@ $(OBJ)

# $? is the dependency list, in this case the .c files.
%.o : %.c
	$(CC) -c $(CFLAGS) $?

# re is recompile
re : fclean all

all : $(NAME)

clean :
	rm -f $(OBJ) $(BON_OBJ)

fclean : clean
		rm -f $(NAME)

bonus: $(BON_OBJ)
	ar -rcs $(NAME) $(BON_OBJ)

.PHONY : all clean fclean re all bonus