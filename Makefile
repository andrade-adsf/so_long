NAME = so_long

SRCS_PATH = ./srcs/

SRCS_FILES = close_window.c game_init.c input_validation.c \
			load_sprites.c map_validation_utils.c map_validation.c \
			open_window.c pressed_key.c put_imgs.c so_long_utils.c \
			so_long.c get_next_line.c

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_FILES))

OBJECTS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror 

LMX_FLAGS = -lmlx -lXext -lX11

INCLUDES = -I ./headers

VALGRIND = valgrind --leak-check=full \
 --show-leak-kinds=all --track-origins=yes \
 --show-reachable=yes --show-possibly-lost=yes -q

all: lib $(NAME)

$(NAME): $(OBJECTS)
	cc $(FLAGS) $(INCLUDES) $^ ./libs/ft_printf/libftprintf.a -o $@ $(LMX_FLAGS)

%.o: %.c
	cc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -fr $(OBJECTS)
	make clean -C libs/ft_printf --no-print-directory

fclean: clean
	rm -fr $(NAME) ./libs/ft_printf/libftprintf.a

re: fclean all

lib:
	make -C libs/ft_printf --no-print-directory

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

.PHONY: all clean fclean re lib