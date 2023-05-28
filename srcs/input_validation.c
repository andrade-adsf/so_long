/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:18:32 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/27 22:27:02 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input_validation (int argc, char **argv, t_game *game)
{
	int	fd;
    char* path;
    
    if (argc != 2)
	{
		printf("Error\nWrong number of parameters!\n");
		exit();
	}
    path = argv[1];
    fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nPath not valid!");
		exit();
	}
	if (ft_strncmp(&path[ft_strlen(path)-4], ".ber", 5) != 0)
	{
		printf("Error\nExtension not valid!");
		exit();
	}
	// ler mapa e salvar na struct
	read_map(fd, game);
    return (0);
}

void	read_map(int fd, t_game *game)
{
	int	map_size;
	char	*line;
	char	*linear_map;
	char	*aux;
	
	
	line = get_next_line(fd);
	map_size = 0;
	aux = ft_strdup("");
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
	ft_putstr_fd("Read map: ", 1);
	ft_putendl_fd(game->map.array[0], 1);
	game->map.map_size = map_size;
	free(linear_map);
	return;
}
