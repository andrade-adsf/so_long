NAME = so_long

all:
	gcc -Wall -Wextra -Werror -g ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c ./srcs/so_long.c ./srcs/input_validation.c ./srcs/map_validation.c  ./srcs/so_long_utils.c -I ./libs/libft -I ./headers/ -I ./libs/get_next_line/ ./libs/libft/libft.a -o $(NAME)

val: $(NAME)
	-valgrind -q ./$(NAME)
	-valgrind -q ./$(NAME) NDSJKANDSJA fhoajdoasda
	-valgrind -q ./$(NAME) ./resources/maps/test.ter
	-valgrind -q ./$(NAME) ./resources/maps/test.ber
	valgrind --leak-check=full -q ./$(NAME) ./resources/maps/first_map.ber

$(NAME): all
