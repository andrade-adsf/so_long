/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:24:42 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/24 19:36:16 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

int input_validation (int argc, char **argv, int* fd);
int char_validation(char **map, int map_size);
void    free_map(char **map, int map_size);
int line_size_validation(char **map, int map_size, int line_size);
int len_line(char **map);
int walls_validation(char **map, int map_size, int line_size);

#endif