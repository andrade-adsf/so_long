/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:59:49 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 05:55:32 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void    load_sprites(t_game *game)
{
    int size;

    size = 16;
    game->sprites.s_floor = mlx_xpm_file_to_image(game->data.mlx, "./resources/sprites/floor_sprite.xpm", &size, &size);
    game->sprites.s_wall = mlx_xpm_file_to_image(game->data.mlx, "./resources/sprites/wall_sprite.xpm", &size, &size);
    game->sprites.s_coin = mlx_xpm_file_to_image(game->data.mlx, "./resources/sprites/coin_sprite.xpm", &size, &size);
    game->sprites.s_player = mlx_xpm_file_to_image(game->data.mlx, "./resources/sprites/player_sprite.xpm", &size, &size);
    game->sprites.s_exit = mlx_xpm_file_to_image(game->data.mlx, "./resources/sprites/exit_sprite.xpm", &size, &size);
    if (game->sprites.s_floor == NULL |
        game->sprites.s_wall == NULL |
        game->sprites.s_coin == NULL |
        game->sprites.s_player == NULL |
        game->sprites.s_exit == NULL)
        {
        printf("deu ruim, rei\n");
        exit(0);
        }
}