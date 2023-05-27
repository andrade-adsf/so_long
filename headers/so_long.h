/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:24:42 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/27 03:08:03 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR 1
# define PFLOOR "resources/sprites/floor.xpm"
# define PWALL "resources/sprites/wall.xpm"
# define PPLAYER "resources/sprites/knight.xpm"
# define PEXIT "resources/sprites/door.xpm"
# define PCOIN "resources/sprites/key.xpm"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
// minilibx
# include <mlx.h>
// Xlib keycode - keysymbol mapping + events and masks
# include <X11/keysym.h>
# include <X11/X.h>
// includes da função open()
# include <sys/types.h>
# include <sys/stat.h>

// structs
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_sprites
{
	void	*s_floor;
	void	*s_wall;
	void	*s_coin;
	void	*s_player;
	void	*s_exit;
}	t_sprites;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_data;

typedef struct s_map
{
	char	**array;
	char	*name;
	int		width;
	int		height;
	int		coins;
	int		p_x;
	int		p_y;
	int		map_size;
}	t_map;

typedef struct s_game
{
	t_map		map;
	t_data		data;
	t_sprites	sprites;
	size_t		steps;
	char		status;
}	t_game;

// validations
int input_validation (int argc, char **argv, int* fd);
int char_validation(char **map, int map_size);
int line_size_validation(char **map, int map_size, int line_size);
int walls_validation(char **map, int map_size, int line_size);

// utils
void    free_map(char **map, int map_size);
int len_line(char **map);

#endif