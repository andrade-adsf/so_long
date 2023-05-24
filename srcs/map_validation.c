/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:34 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/24 07:20:04 by feandrad         ###   ########.fr       */
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
            if(check_char == 'E')
            {
                count_e++;
                if(count_e > 1)
                    return(-1);
            }
            else if(check_char == 'P')
            {
                count_p++;
                if(count_p > 1)
                    return(-1);
            }
        }
        i++;
    }
    return(0);
}

int line_size_validation(char **map, int map_size)
{
    int i;
    int j;
    int line_size;

    i = 0;
    j = 0;
    line_size = len_line(map);
    
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
