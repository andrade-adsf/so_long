/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:56:00 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/25 23:14:39 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    int fd;

    if (input_validation(argc, argv, &fd) == -1)
        return (-1)
    
}