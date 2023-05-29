/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 06:18:14 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 02:43:24 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.map_size)
	{
		free(game->map.array[i]);
		i++;
	}
	free(game->map.array);
}

int	len_line(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0')
		j++;
	return (j);
}

void	reload_map(char **argv, t_game *game)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	read_map(fd, game);
	get_pos(game);
}

int	check_movement(t_game *game, int x, int y)
{
	if (game->map.array[y][x] != '1')
	{
		if (game->map.array[y][x] == 'C')
			game->map.coins--;
		else if (!game->map.coins && game->map.array[y][x] == 'E')
		{
			ft_printf("MOVES: %d\n", ++(game->steps));
			close_free(game, "YOU WIN!!!\n", 1);
		}
		if (game->map.array[y][x] == 'E')
			return (0);
		ft_printf("MOVES: %d\n", ++(game->steps));
		return (1);
	}
	return (0);
}

void	get_pos(t_game *game)
{
	int		i;
	int		j;
	char	check_char;

	i = 0;
	game->map.coins = 0;
	while (i < game->map.map_size)
	{
		j = 0;
		while (game->map.array[i][j] != '\0')
		{
			check_char = game->map.array[i][j];
			if (check_char == 'P')
			{
				game->map.p_x = j;
				game->map.p_y = i;
			}
			if (check_char == 'C')
				game->map.coins++;
			j++;
		}
		i++;
	}
}
