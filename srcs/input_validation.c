/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:18:32 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/23 06:22:00 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int input_validation (int argc, char **argv, int* fd)
{
    char* path;
    
    if (argc != 2)
	{
		printf("Error\nWrong number of parameters!");
		return (-1);
	}
    path = argv[1];
    *fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		printf("Error\nPath not valid!");
		return (-1);
	}
	if (ft_strncmp(&path[ft_strlen(path)-4], ".ber", 5) != 0)
	{
		printf("Error\nExtension not valid!");
		return (-1);
	}
    return (0);
}

