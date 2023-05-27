/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:11:53 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/27 03:01:26 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    get_next_path(t_map *mp, int x, int y)
{
    if (mp->array[y][x] != '1' && mp->array[y][x] != 'X')
        return (1);
    return (0);
}
