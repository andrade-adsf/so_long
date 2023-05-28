/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:26:34 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/28 00:53:27 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int char_validation(t_game *game)
{
    int i;
    int j;
    int count_e;
    int count_p;
    char    check_char;
    
	i = 0;
	count_e = 0;
	count_p = 0;
    while(i < game->map.map_size)
    {
        j = 0;
        while(game->map.array[i][j] != '\0')
        {
            check_char = game->map.array[i][j];
            if(ft_strchr("01CEP", check_char) == NULL)
                exit(0);
            else
                j++;
            if(check_char == 'E')
                count_e++;
            else if(check_char == 'P')
                count_p = player_position(game, count_p, j - 1, i);
            else if(check_char == 'C')
                game->map.coins++;
        }
        i++;
    }
    if(count_e != 1 || count_p != 1 || game->map.coins < 1)
    {
        exit(0);
    }
    return(0);
}

int line_size_validation(t_game *game)
{
    int i;
    int j;
    int line_size;

    i = 0;
    j = 0;
    line_size = len_line(game->map.array);
    while(i < game->map.map_size)
    {
        while((game->map.array[i][j] != '\0') | (j < line_size))
            j++;
        if(j != line_size)
            exit(0);
        else
            i++;
    }
    return(0);
}

int walls_validation(t_game *game)
{
    int i;
    int j;
    int line_size;

    i = 0;
    line_size = len_line(game->map.array);
    while(i < game->map.map_size)
    {
        if(game->map.array[i][0] != '1' || game->map.array[i][line_size - 1] != '1')
            exit(0);
        i++;
    }
    j = 0;
    while(j < line_size)
    {
        if(game->map.array[0][j] != '1' || game->map.array[game->map.map_size - 1][j] != '1')
            exit(0);
        j++;
    }
    return (0);
}

int    check_path(t_game *game)
{
    if (game->map.array[game->map.p_y][game->map.p_x] == 'C' || game->map.array[game->map.p_y][game->map.p_x] == 'E')
        game->map.coins--;
    game->map.array[game->map.p_y][game->map.p_x] = 'X';
    if (get_next_path(game, game->map.p_y - 1, game->map.p_x) && game->map.coins > -1)
    {
        game->map.p_y--;
        check_path(game);
    }
    if (get_next_path(game, game->map.p_y + 1, game->map.p_x) && game->map.coins > -1)
    {
        game->map.p_y++;
        check_path(game);
    }
    if (get_next_path(game, game->map.p_y, game->map.p_x - 1) && game->map.coins > -1)
    {
        game->map.p_x--;
        check_path(game);
    }
    if (get_next_path(game, game->map.p_y, game->map.p_x + 1) && game->map.coins > -1)
    {
        game->map.p_x++;
        check_path(game);
    }
    return (game->map.coins);
}

//game map coins if return != -1 exit

void    map_validation(t_game *game)
{
    char_validation(game);
    line_size_validation(game);
    walls_validation(game);
    check_path(game);
}
