/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:07:13 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/27 01:12:35 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    mem_allocation(t_game game)
{
    // game->map = ft_calloc(1, sizeof(t_map));
    // game->data = ft_calloc(1, sizeof(t_data));
    // game->sprites = ft_calloc(1, sizeof(t_sprites));
    // game->data->img = ft_calloc(1, sizeof(t_img));
    game->map->grid = ft_calloc(1, sizeof(char **));
}