/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:51:23 by atable            #+#    #+#             */
/*   Updated: 2020/05/20 11:54:34 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char	*dst;
	char	*src;
	size_t	i;

	if (!source && !dest)
		return (NULL);
	dst = (char *)dest;
	src = (char *)source;
	if (n == 0)
		return (dst);
	if (src < dst)
	{
		while (n--)
			dst[n] = src[n];
		return (dst);
	}
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
