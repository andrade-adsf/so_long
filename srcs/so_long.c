/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:39:58 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/09 18:30:34 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int main(int argc, char** argv)
{
	int	fd;
	char	*path;
	char	*line;

	path = argv[1];
	fd = open(path, O_RDONLY);
	if (validation(argc, path, fd) == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	return (0);
}
