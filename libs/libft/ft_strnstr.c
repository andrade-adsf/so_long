/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feandrad <feandrad@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 02:20:19 by feandrad          #+#    #+#             */
/*   Updated: 2023/05/20 16:47:54 by feandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!haystack)
		return (NULL);
	if (!*needle)
		return (haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && (len - i) > 0)
		{
			i++;
			if (!needle[i])
				return (haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
