/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:25:16 by atable            #+#    #+#             */
/*   Updated: 2020/05/20 11:50:39 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	size_t	i;
	char	*dst;
	char	*src;

	i = 0;
	dst = (char *)dest;
	src = (char *)source;
	if (dst || src)
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dest);
}
