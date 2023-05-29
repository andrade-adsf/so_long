/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:24:42 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 02:02:00 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR 1
# define PFLOOR "./resources/sprites/floor_sprite.xpm"
# define PWALL "./resources/sprites/wall_sprite.xpm"
# define PPLAYER "./resources/sprites/player_sprite.xpm"
# define PEXIT "./resources/sprites/exit_sprite.xpm"
# define PCOIN "./resources/sprites/coin_sprite.xpm"

# define KEY_W				119
# define KEY_S				115
# define KEY_A				97
# define KEY_D				100

# define KEY_UP  			65362
# define KEY_DOWN  			65364
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363

# define KEY_ESC  			65307

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"
// minilibx
# include <mlx.h>
// Xlib keycode - keysymbol mapping + events and masks
# include <X11/keysym.h>
# include <X11/X.h>
// includes da função open()
# include <sys/types.h>
# include <sys/stat.h>

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
}	t_data;

typedef struct s_map
{
	char	**array;
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
	int		steps;
}	t_game;

// validations
int input_validation (int argc, char **argv, t_game *game);
int char_validation(t_game *game);
int line_size_validation(t_game *game);
int walls_validation(t_game *game);
int    check_path(t_game *game, int x, int y);
void    map_validation(t_game *game);

// game related
void	read_map(int fd, t_game *game);
int player_position(t_game *game, int count_p, int x, int y);
void reload_map(char **argv, t_game *game);
void    open_window(t_game *game);
void    load_sprites(t_game *game);
void    put_imgs(t_game *game);
int	pressed_key(int key,t_game *game);
void    key_up(int key, t_game *game);
void    key_down(int key, t_game *game);
void    key_left(int key, t_game *game);
void    key_right(int key, t_game *game);
int check_movement(t_game *game, int x, int y);

// utils
void    free_map(t_game *game);
int len_line(char **map);
int get_next_path(t_game *game, int y, int x);
void    get_pos(t_game *game);
int close_free(t_game *game, char *error_message, int game_start);
void    key_esc(int key, t_game *game);
int	game_rows(t_game *game);

#endif