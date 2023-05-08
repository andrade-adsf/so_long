/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:39:58 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/08 19:07:22 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int BUFFER_SIZE = 100;
	int fd;
	char buffer[BUFFER_SIZE];
	char *path;

	path = "../resources/maps/first_map.ber";
	fd = open(path, O_RDONLY);
	read(fd, buffer, BUFFER_SIZE);
	printf("%s", buffer);
}
