/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:39:58 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/08 20:04:13 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libs/get_next_line/get_next_line.h"

int main(int argc, char** argv)
{
	int	fd;
	char	*path;
	char	*line;

	if (argc != 2)
	{
		printf("Error\nWrong number of parameters!");
		return (-1);
	}
	path = argv[1];
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nPath not valid!");
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}
