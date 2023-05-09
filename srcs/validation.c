/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:18:32 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/09 18:32:50 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int validation (int argc, char* path, int fd)
{
    if (argc != 2)
	{
		printf("Error\nWrong number of parameters!");
		return (-1);
	}
	if (fd == -1)
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