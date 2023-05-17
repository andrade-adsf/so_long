/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:34 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/17 07:55:09 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_validation(char **map, int map_size)
{
    int i;
    int j;
    int count_e;
    int count_p;
    char    valid_e;
    char    valid_p;
    char    *valid_multiple;
    
	i = 0;
	j = 0;
	count_e = 0;
	count_p = 0;
	valid_e = 'E';
	valid_p = 'P';
	valid_multiple = "01C";
    while(map[i] < map_size)
    {
        while(map[i][j] != '\0')
        {
			// write new logic using ft_strnstr if null -1, if e e++, if p p++, if 0 | 1 | c j++ else -1
            if(map[i][j] found on valid_multiple)
            {
				j++;
			}
            else if(map[i][j] found on valid_e)
            {
				count_e++;
                if(count_e > 1)
                    return(-1);
                j++;
			}
            else if(map[i][j] found on valid_p)
            {
				count_p++;
                if(count_p > 1)
                    return(-1);
                j++;
			}
            else
			{
                return(-1);
			}
        }
        i++;
    }
    return(0);
}

