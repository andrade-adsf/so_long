/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:56:00 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 05:45:58 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;
    int i;

    i = 0;
    ft_bzero(&game, sizeof(t_game));
    // mem_allocation(&game);
    // initialize_values(&game);
    input_validation(argc, argv, &game);
    map_validation(&game);
    free_map(&game);
    reload_map(argv, &game);
    open_window(&game);
    load_sprites(&game);
    put_imgs(&game);
    mlx_loop(game.data.mlx);
    // game_end;
    // free_map;
}