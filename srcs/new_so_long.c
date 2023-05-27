/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:56:00 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/27 01:16:25 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game  game;
    
    mem_allocation(&game);
    // initialize_values(&game);
    input_validation(argc, argv, &game);
    map_validation(&game);
    // free_map;
    // reload_map;
    // open_window;
    // game_start;
    // game_end;
    // free_map;
}