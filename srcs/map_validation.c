/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:34 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/25 18:51:27 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_validation(char **map, int map_size)
{
    int i;
    int j;
    int count_e;
    int count_p;
    char    check_char;
    
	i = 0;
	count_e = 0;
	count_p = 0;
    while(i < map_size)
    {
        j = 0;
        while(map[i][j] != '\0')
        {
            check_char = map[i][j];
            if(ft_strchr("01CEP", check_char) == NULL)
                return(-1);
            else
                j++;
            if(check_char != 'E')
                count_e++;
            else if(check_char != 'P')
                count_p++;
        }
        i++;
    }
    if(count_e != 1 || count_p != 1)
        return(-1);
    return(0);
}

int line_size_validation(char **map, int map_size, int line_size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < map_size)
    {
        while((map[i][j] != '\0') | (j < line_size))
            j++;
        if(j != line_size)
            return(-1);
        else
            i++;
    }
    return(0);
}

int walls_validation(char **map, int map_size, int line_size)
{
    int i;
    int j;

    i = 0;
    while(i < map_size)
    {
        if(map[i][0] != '1' || map[i][line_size - 1] != '1')
            return (-1);
        i++;
    }
    j = 0;
    while(j < line_size)
    {
        if(map[0][j] != '1' || map[map_size - 1][j] != '1')
            return (-1);
        j++;
    }
    return (0);
}

int    get_next_path(t_map *mp, int x, int y)
{
    if (mp->array[y][x] != '1' && mp->array[y][x] != 'X'
        && mp->array[y][x] != 'N')
        return (1);
    return (0);
}

int    check_path(t_map *map, int x, int y)
{
    if (map->array[y][x] == 'C' || map->array[y][x] == 'E')
        map->coins--;
    map->array[y][x] = 'X';
    if (get_next_path(map, x, y - 1) && map->coins > -1)
        check_path(map, x, y - 1);
    if (get_next_path(map, x, y + 1) && map->coins > -1)
        check_path(map, x, y + 1);
    if (get_next_path(map, x - 1, y) && map->coins > -1)
        check_path(map, x - 1, y);
    if (get_next_path(map, x + 1, y) && map->coins > -1)
        check_path(map, x + 1, y);
    return (map->coins);
}
