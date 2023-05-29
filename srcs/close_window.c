/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:25:21 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 02:23:57 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_free(t_game *game, char *error_message, int game_start)
{
    ft_printf("%s", error_message);
    free_map(game);
    if (game_start == 1)
    {
        if (game->sprites.s_exit != NULL)
            mlx_destroy_image(game->data.mlx, game->sprites.s_exit);
        if (game->sprites.s_coin != NULL)
            mlx_destroy_image(game->data.mlx, game->sprites.s_coin);
        if (game->sprites.s_wall != NULL)
            mlx_destroy_image(game->data.mlx, game->sprites.s_wall);
        if (game->sprites.s_floor != NULL)
            mlx_destroy_image(game->data.mlx, game->sprites.s_floor);
        if (game->sprites.s_player != NULL)
            mlx_destroy_image(game->data.mlx, game->sprites.s_player);
        mlx_destroy_window(game->data.mlx, game->data.win);
        mlx_destroy_display(game->data.mlx);
        free(game->data.mlx);
    }
    exit(0);
}

void    key_esc(int key, t_game *game)
{
    if (key == KEY_ESC)
        close_free(game, "Game closed!", 1);
}
