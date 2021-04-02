/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:32:50 by atable            #+#    #+#             */
/*   Updated: 2020/05/20 11:28:50 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	dst = (char *)dest;
	src = (char *)source;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == (char)c)
			return (&dst[++i]);
		i++;
	}
	return (NULL);
}
