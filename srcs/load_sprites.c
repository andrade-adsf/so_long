/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:59:49 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/29 02:28:18 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	load_sprites(t_game *game)
{
	int	size;

	size = 16;
	game->sprites.s_floor = mlx_xpm_file_to_image (game->data.mlx, PFLOOR, \
	&size, &size);
	game->sprites.s_wall = mlx_xpm_file_to_image (game->data.mlx, PWALL, \
	&size, &size);
	game->sprites.s_coin = mlx_xpm_file_to_image (game->data.mlx, PCOIN, \
	&size, &size);
	game->sprites.s_player = mlx_xpm_file_to_image (game->data.mlx, PPLAYER, \
	&size, &size);
	game->sprites.s_exit = mlx_xpm_file_to_image (game->data.mlx, PEXIT, \
	&size, &size);
	if (game->sprites.s_floor == NULL || game->sprites.s_wall == NULL
		|| game->sprites.s_coin == NULL || game->sprites.s_player == NULL
		|| game->sprites.s_exit == NULL)
		close_free (game, "Error\nSprites not found!\n", 1);
}
