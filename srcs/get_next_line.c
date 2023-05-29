/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:13:53 by coder             #+#    #+#             */
/*   Updated: 2023/05/29 04:11:46 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = aux;
	if (!aux)
		aux = (char *) ft_calloc(1, 1);
	if (read_file(&aux, &line, fd))
		return (line);
	if (!*aux)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	line = aux;
	aux = NULL;
	return (line);
}

int	read_file(char **aux_p, char **line_p, int fd)
{
	char		*buffer;
	ssize_t		i;
	ssize_t		chars_read;

	i = 0;
	chars_read = BUFFER_SIZE;
	while (chars_read > 0)
	{
		while ((*aux_p)[i] != '\n' && (*aux_p)[i])
			i++;
		if ((*aux_p)[i] == '\n')
		{
			*line_p = *aux_p;
			*aux_p = ft_substr(*line_p, i + 1, ft_strlen(*line_p + i + 1));
			ft_bzero(*line_p + i + 1, ft_strlen(*line_p + i + 1));
			return (1);
		}
		buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		chars_read = read(fd, buffer, BUFFER_SIZE);
		*line_p = ft_strjoin(*aux_p, buffer);
		free(*aux_p);
		*aux_p = *line_p;
		free(buffer);
	}
	return (0);
}
