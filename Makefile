all:
	gcc -Wall -Wextra -Werror ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c ./srcs/so_long.c ./srcs/validation.c -I ./libs/libft -I ./headers/ -I ./libs/get_next_line/ ./libs/libft/libft.a 