/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:34 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/11 20:07:57 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_validation(char **map, int map_size)
{
    int i;
    int j;
    int valid_i;
    int unique_i;
    int exit_qt;
    int player_qt;
    char    *valid_chars;
    char    *valid_unique;

    i = 0;
    j = 0;
    exit_qt = 0;
    player_qt = 0;
    valid_chars = "01C";
    valid_unique = "EP";
    while(i < map_size)
    {
        while(map[i][j] != '\0')
        {
            valid_i = 0;
            while(valid_chars[valid_i] != '\0')
            {
                if(map[i][j] == valid_chars[valid_i])
                    valid_i++;
                else
                {
                    unique_i = 0;
                    while(valid_unique[unique_i] != '\0')
                    {
                        if(map[i][j] == valid_unique[unique_i])
                            {
                                if(valid_unique[unique_i] == 'E')
                                {
                                    exit_qt++;
                                    if(exit_qt > 1)
                                    {
                                        printf("Error\nMore than one exit found!");
                                        return (-1);
                                    }
                                    unique_i++;
                                }
                                else if(valid_unique[unique_i] == 'P')
                                {
                                    player_qt++;
                                    if(exit_qt > 1)
                                    {
                                        printf("Error\nMore than one player found!");
                                        return (-1);
                                    }
                                    unique_i++;
                                }
                            }
                        else
                            {
                                printf("I = %d, J=%d", i, j);
                                printf("Error\nNot valid character on map");
                                return (-1);
                            }
                    }
                }
            }
            j++;
        }
        i++;
    }
    return (0);
}