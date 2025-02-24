NAME = fdf
CC = gcc
CFLAGS = -I/usr/include -Imlx_linux -O3
MLX_DIR = mlx_linux
MLX_LIB = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
SRC = main.c \
	read_file.c \
	read_utils.c \
	draw.c \
	bresenham.c \
	libft1/libft/get_next_line/get_next_line.c \
	libft1/libft/get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft1/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./libft1/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a


all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)


$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LIB) -o $(NAME) $(LIBFT) $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
