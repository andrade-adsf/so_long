/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 05:30:02 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 06:06:43 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_imgs(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(i < game->map.map_size)
        {
            j = 0;
            while(game->map.array[i][j] != '\0')
            {
                if (game->map.array[i][j] == '0')
                    mlx_put_image_to_window(game->data.mlx, game->data.win, game->sprites.s_floor, j*16, i*16);
                if (game->map.array[i][j] == '1')
                    mlx_put_image_to_window(game->data.mlx, game->data.win, game->sprites.s_wall, j*16, i*16);
                if (game->map.array[i][j] == 'C')
                    mlx_put_image_to_window(game->data.mlx, game->data.win, game->sprites.s_coin, j*16, i*16);
                if (game->map.array[i][j] == 'P')
                    mlx_put_image_to_window(game->data.mlx, game->data.win, game->sprites.s_player, j*16, i*16);
                if (game->map.array[i][j] == 'E')
                    mlx_put_image_to_window(game->data.mlx, game->data.win, game->sprites.s_exit, j*16, i*16);
                j++;
            }
            i++;
        }
}
