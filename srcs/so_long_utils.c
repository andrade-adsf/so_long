/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 06:18:14 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/24 19:33:13 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(char **map, int map_size)
{
    int i;

    i = 0;
    while (i < map_size)
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int len_line(char **map)
{
    int j;
    int line_size;
    
    j = 0;
    line_size = 0;
    while(map[0][j] != '\0')
    {
        line_size++;
        j++;
    }
    return(line_size);
}