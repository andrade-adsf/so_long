/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 06:18:14 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 01:18:39 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.map_size)
    {
        free(game->map.array[i]);
        i++;
    }
    free(game->map.array);
}

int len_line(char **map)
{
    int j;
    
    j = 0;
    while(map[0][j] != '\0')
        j++;
    return(j);
}

void reload_map(char **argv, t_game *game)
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);
    read_map(fd, game);
}