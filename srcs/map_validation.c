/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:34 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 02:47:41 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_validation(t_game *game)
{
	int		i;
	int		j;
	int		count_e;
	int		count_p;
	char	check_char;

	i = 0;
	count_e = 0;
	count_p = 0;
	while (i < game->map.map_size)
	{
		j = 0;
		while (game->map.array[i][j] != '\0')
		{
			check_char = game->map.array[i][j];
			if (ft_strchr("01CEP", check_char) == NULL)
				close_free(game, "Error\nChar on map not permited!\n", 0);
			else
				j++;
			if (check_char == 'E')
				count_e++;
			else if (check_char == 'P')
				count_p = player_position(game, count_p, j - 1, i);
			else if (check_char == 'C')
				game->map.coins++;
		}
		i++;
	}
	if (count_e != 1 || count_p != 1 || game->map.coins < 1)
		close_free (game, "Error\nWrong number of elements!\n", 0);
	return (0);
}

int	line_size_validation(t_game *game)
{
	int	i;
	int	j;
	int	line_size;

	i = 0;
	line_size = len_line(game->map.array);
	while (i < game->map.map_size)
	{
		j = 0;
		while ((game->map.array[i][j] != '\0') && (j < line_size))
			j++;
		if (j != line_size)
			close_free(game, "Error\nGame is not a rectangle!\n", 0);
		else
			i++;
	}
	return (0);
}

int	walls_validation(t_game *game)
{
	int	i;
	int	j;
	int	line_size;

	i = 0;
	line_size = len_line(game->map.array);
	while (i < game->map.map_size)
	{
		if (game->map.array[i][0] != '1'
		|| game->map.array[i][line_size - 1] != '1')
			close_free(game, "Error\nMap not surrounded by walls!\n", 0);
		i++;
	}
	j = 0;
	while (j < line_size)
	{
		if (game->map.array[0][j] != '1'
		|| game->map.array[game->map.map_size - 1][j] != '1')
			close_free(game, "Error\nMap not surrounded by walls!\n", 0);
		j++;
	}
	return (0);
}

int	check_path(t_game *game, int x, int y)
{
	char	temp;

	temp = game->map.array[y][x];
	if (game->map.array[y][x] == 'C' || game->map.array[y][x] == 'E')
		game->map.coins--;
	game->map.array[y][x] = 'X';
	if (temp == 'E')
		return (game->map.coins);
	if (get_next_path(game, y - 1, x) && game->map.coins > -1)
		check_path(game, x, y - 1);
	if (get_next_path(game, y + 1, x) && game->map.coins > -1)
		check_path(game, x, y + 1);
	if (get_next_path(game, y, x - 1) && game->map.coins > -1)
		check_path(game, x - 1, y);
	if (get_next_path(game, y, x + 1) && game->map.coins > -1)
		check_path(game, x + 1, y);
	return (game->map.coins);
}

void	map_validation(t_game *game)
{
	char_validation(game);
	line_size_validation(game);
	walls_validation(game);
	if (check_path(game, game->map.p_x, game->map.p_y) > -1)
		close_free(game, "Error\nMap not valid!", 0);
}
