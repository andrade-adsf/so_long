NAME = so_long

VALGRIND = valgrind --leak-check=full \
 --show-leak-kinds=all --track-origins=yes \
 --show-reachable=yes --show-possibly-lost=yes -q

all:
	gcc -Wall -Wextra -Werror -g ./libs/get_next_line/get_next_line.c \
	./libs/get_next_line/get_next_line_utils.c ./srcs/so_long.c \
	./srcs/game_init.c ./srcs/open_window.c ./srcs/load_sprites.c \
	./srcs/put_imgs.c ./srcs/pressed_key.c ./srcs/close_window.c \
	./srcs/input_validation.c ./srcs/map_validation_utils.c \
	./srcs/map_validation.c  ./srcs/so_long_utils.c \
	./libs/ft_printf/libftprintf.a \
	-I ./libs/get_next_line/ -I ./libs/ft_printf -I ./headers/ \
	-o $(NAME) -lmlx -lXext -lX11

val: $(NAME)
	@printf "\n\nTeste somente com ./so_long\n"
	-$(VALGRIND) ./$(NAME)
	@printf "\n\nTeste somente com ./so_long invalid args\n"
	-$(VALGRIND) ./$(NAME) /resources/maps/first_map.ber fhoajdoasda
	@printf "\n\nTeste somente com ./so_long invalid args\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/test.ter
	@printf "\n\nTeste somente com ./so_long invalid args\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/test.ber

	@printf "\n\nTeste somente com ./so_long invalid maps\n"
	@printf "\nAbism\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/abism.ber

	@printf "\n\n\n\nInvalid Number of players\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/invalid_numer_of_players.ber
	
	@printf "\n\n\n\nInvalid Walls\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/invalid_walls.ber
	
	@printf "\n\n\n\nNo collectables\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/no_collectables.ber

	@printf "\n\n\n\nNo Players\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/no_players.ber
	
	@printf "\n\n\n\nNo Exits\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/no_exits.ber
	
	@printf "\n\n\n\nInvalid Map\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/wrong_map.ber

	@printf "\n\n\n\nInvalid Character\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/invalid_character.ber
	
	@printf "\n\n\n\nImpossible Map\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/impossible.ber

	@printf "\n\n\n\nEmpty Map\n"
	-$(VALGRIND) ./$(NAME) ./resources/maps/empty.ber

	@printf "\n\nTeste correto\n"
	$(VALGRIND) ./$(NAME) ./resources/maps/first_map.ber

$(NAME): all
