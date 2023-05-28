NAME = so_long

all:
	gcc -Wall -Wextra -Werror -g ./libs/get_next_line/get_next_line.c \
	./libs/get_next_line/get_next_line_utils.c ./srcs/so_long.c \
	./srcs/game_init.c \
	./srcs/input_validation.c ./srcs/map_validation_utils.c \
	./srcs/map_validation.c  ./srcs/so_long_utils.c \
	./libs/libft/libft.a \
	-I ./libs/libft -I ./libs/get_next_line/ -I ./headers/ \
	-o $(NAME)

val: $(NAME)
	@printf "\n\nTeste somente com ./so_long\n"
	-valgrind -q ./$(NAME)
	@printf "\n\nTeste somente com ./so_long invalid args\n"
	-valgrind -q ./$(NAME) NDSJKANDSJA fhoajdoasda
	@printf "\n\nTeste somente com ./so_long invalid args\n"
	-valgrind -q ./$(NAME) ./resources/maps/test.ter
	@printf "\n\nTeste somente com ./so_long invalid args\n"
	-valgrind -q ./$(NAME) ./resources/maps/test.ber
	@printf "\n\nTeste correto\n"
	valgrind --leak-check=full -q ./$(NAME) ./resources/maps/first_map.ber

$(NAME): all
