/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:39:58 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/08 19:27:02 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libs/get_next_line/get_next_line.h"

int main(void)
{
	int fd;
	char *path;
	char *line;

	path = "./resources/maps/first_map.ber";
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while(line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
}
