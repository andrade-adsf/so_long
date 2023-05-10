/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:39:58 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/10 19:44:22 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char** argv)
{
	int	fd;
	int	map_size;
	int i;
	char	*line;
	char	*aux;
	char	*linear_map;
	char	**map;

	if (input_validation(argc, argv, &fd) == -1)
		return (-1);
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
	map = ft_split(linear_map, '\n');
	free(linear_map);
	i = 0;
	while(i < map_size)
		{
			printf("%s", map[i]);
			if(i < map_size - 1)
				printf("\n");
			free(map[i]);
			i++;
		}
	free(map);
	return (0);
}
