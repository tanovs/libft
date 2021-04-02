/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 20:12:38 by atable            #+#    #+#             */
/*   Updated: 2020/05/19 21:14:02 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	lend;
	size_t	lens;

	if (!dst && !src)
		return (0);
	j = 0;
	while (dst[j] && size != 0)
	{
		j++;
		size--;
	}
	lens = ft_strlen(src);
	lend = j;
	if (j < size + lend)
	{
		while (*src && (j < (size + lend - 1)))
		{
			dst[j] = *src;
			j++;
			src++;
		}
		dst[j] = '\0';
	}
	return (lens + lend);
}
