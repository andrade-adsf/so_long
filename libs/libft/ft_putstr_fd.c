/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 03:08:07 by feandrad          #+#    #+#             */
/*   Updated: 2022/12/07 18:03:29 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	str_size;

	i = 0;
	str_size = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		str_size += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (str_size);
}
