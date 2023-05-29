/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:56:00 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 02:35:21 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		i;

	i = 0;
	ft_bzero(&game, sizeof(t_game));
	input_validation(argc, argv, &game);
	map_validation(&game);
	free_map(&game);
	reload_map(argv, &game);
	open_window(&game);
	load_sprites(&game);
	put_imgs(&game);
	mlx_hook(game.data.win, 2, 1L << 0, pressed_key, &game);
	mlx_hook(game.data.win, 17, 1L << 2, close_free, &game);
	mlx_loop(game.data.mlx);
}
