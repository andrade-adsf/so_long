# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 14:57:50 by feandrad          #+#    #+#              #
#    Updated: 2023/03/18 18:35:06 by feandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# path
SRCS = ./srcs/
HEADER = ./headers/
OBJS = ./objs/
BINS = ./bin/
TESTSDIR = tests/

# compilation
CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(HEADERS_PATH)
VALGRIND = valgrind --leak-check=fulll --show-leak-kinds=all --track-origins=yes -q --tool=memcheck

# bash
RM = rm -fr
MKDIR = mkdir -p

# files
NAME = $(BINS)so_long
SRCS_FILES = $(SRCS)so_long.c
SOURCES = $(addprefix $(SRCS), $(SRCS_FILES))
OBJS_FILES = $(patsubst %.c, %.o, $(SRCS_FILES))
OBJECTS = $(addprefix $(OBJS), $(OBJS_FILES))
TESTS_FILES = $(wildcard $(TESTSDIR)%.c)
TESTS = $(addprefix $(TESTSDIR), $(TESTS_FILES))
# revisar se precisa de uma variavel pra caminho e outra pra file
# possivelmente subtituir por apenas uma variavel
# adicionar variavel de test file e test objects

# targets
all: make_dir $(NAME)

# create bin directory
make_dir:
		$(MKDIR) $(BINS)

# create executable so_long inside ./bin/
$(NAME): $(OBJECTS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -lmlx -lXext -lX11 -lft

# create object files for so_long
$(OBJS)%.o : $(SRCS)%.c
		$(MKDIR) $(OBJS_PATH)
		$(CC) $(FLAGS) -c $< -o $@

valgrind: $(NAME)
		@$(VALGRIND) $(NAME)

# clean .o files
clean: 
		@$(RM) $(OBJECTS)

# clean .o, static library and executable
fclean: clean
	$(RM) (NAME)

# clean and compiles again
re: fclean all

# run unit tests
test: 


.PHONY: all run clean fclean re valgrind make_dir test