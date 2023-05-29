/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:18:32 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 03:20:34 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_validation(int argc, char **argv, t_game *game)
{
	int		fd;
	char	*path;

	if (argc != 2)
		close_free(game, "Error\nWrong number of parameters!\n", 0);
	path = argv[1];
	fd = open(path, O_RDONLY);
	if (fd == -1)
		close_free(game, "Error\nPath not valid!\n", 0);
	if (ft_strncmp(&path[ft_strlen(path)-4], ".ber", 5) != 0)
		close_free(game, "Error\nExtension not valid!\n", 0);
	read_map(fd, game);
	return (0);
}

void	read_map(int fd, t_game *game)
{
	int		map_size;
	char	*line;
	char	*linear_map;
	char	*aux;

	line = get_next_line(fd);
	map_size = 0;
	if (line != NULL)
		aux = ft_strdup("");
	linear_map = NULL;
	while (line != NULL)
	{
		linear_map = ft_strjoin(aux, line);
		free(line);
		free(aux);
		aux = linear_map;
		line = get_next_line(fd);
		map_size++;
	}
	game->map.array = ft_split(linear_map, '\n');
	if (game->map.array == NULL)
		close_free(game, "Error\nNull map!", 0);
	game->map.map_size = map_size;
	if (map_size != game_rows(game))
	{
		free(linear_map);
		close_free(game, \
		"Error\nMap size different from number of rows on file!", 0);
	}
	free(linear_map);
	return ;
}

int	game_rows(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.array[i] != NULL)
		i++;
	return (i);
}
