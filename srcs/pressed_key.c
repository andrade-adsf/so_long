/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pressed_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:17:15 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 23:10:18 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int pressed_key(int key, t_game *game)
{
    key_up(key, game);
    key_down(key, game);
    key_left(key, game);
    key_right(key, game);
    key_esc(key, game);

    return (0);
}

void    key_up(int key, t_game *game)
{
    if (key == KEY_W || key == KEY_UP)
    {
        if (check_movement(game, game->map.p_x, game->map.p_y - 1))
        {
            game->map.array[game->map.p_y][game->map.p_x] = '0';
            game->map.p_y -= 1;
            game->map.array[game->map.p_y][game->map.p_x] = 'P';
            put_imgs(game);
        }
    }
}

void    key_down(int key, t_game *game)
{
    if (key == KEY_S || key == KEY_DOWN)
    {
        if (check_movement(game, game->map.p_x, game->map.p_y + 1))
        {
            game->map.array[game->map.p_y][game->map.p_x] = '0';
            game->map.p_y += 1;
            game->map.array[game->map.p_y][game->map.p_x] = 'P';
            put_imgs(game);
        }
    }
}

void    key_left(int key, t_game *game)
{
    if (key == KEY_A || key == KEY_LEFT)
    {
        if (check_movement(game, game->map.p_x - 1, game->map.p_y))
        {
            game->map.array[game->map.p_y][game->map.p_x] = '0';
            game->map.p_x -= 1;
            game->map.array[game->map.p_y][game->map.p_x] = 'P';
            put_imgs(game);
        }
    }
}

void    key_right(int key, t_game *game)
{
    if (key == KEY_D || key == KEY_RIGHT)
    {
        if (check_movement(game, game->map.p_x + 1, game->map.p_y))
        {
            game->map.array[game->map.p_y][game->map.p_x] = '0';
            game->map.p_x += 1;
            game->map.array[game->map.p_y][game->map.p_x] = 'P';
            put_imgs(game);
        }
    }
}
