/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:46:59 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 05:44:48 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    open_window(t_game *game)
{
    int line_size;
    
    line_size = len_line(game->map.array);
    game->data.mlx = mlx_init();
    game->map.width = 16 * line_size;
    game->map.height = 16 * game->map.map_size;
    game->data.win = mlx_new_window(game->data.mlx, game->map.width, game->map.height, "so_long");
}