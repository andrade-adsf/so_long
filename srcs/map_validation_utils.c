/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:11:53 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 00:53:43 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_next_path(t_game *game, int y, int x)
{
    if (game->map.array[y][x] != '1' && game->map.array[y][x] != 'X')
        return (1);
    return (0);
}

int player_position(t_game *game, int count_p, int x, int y)
{
    game->map.p_x = x;
    game->map.p_y = y;
    count_p++;
    return (count_p);
}