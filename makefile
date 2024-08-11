NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g3 -fsanitize=address,undefined

SRCS    = $(addprefix mandatory/, so_long.c parsing1.c parsing2.c \
			parsing3.c rendering.c game_stuff.c \
			)

OBJ     = $(SRCS:.c=.o)

PRINTF  = ft_printf_copy/libftprintf.a
LIBFT   = libft_copy/libft.a
MLX     = MLX/libmlx.a

MLXFLAG = -L mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(LIBFT):
	make -C libft_copy
	
$(PRINTF):
	make -C ft_printf_copy

$(MLX):
	make -C MLX

$(NAME): $(OBJ) $(LIBFT) $(PRINTF) $(MLX) 
	@echo objs:${OBJ}
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAG) -o $@ $(LIBFT) $(PRINTF) $(MLX)
# $(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBFT) $(PRINTF)

clean: 
	rm -f $(OBJ)
	make -C libft_copy clean
	make -C ft_printf_copy clean

fclean: clean
	@make -C MLX clean
	make -C libft_copy fclean
	make -C ft_printf_copy fclean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re