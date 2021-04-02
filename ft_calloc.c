/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:22:32 by atable            #+#    #+#             */
/*   Updated: 2020/05/12 21:40:32 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	array = (char*)malloc(nmemb * size);
	if (array)
		ft_memset(array, 0, nmemb * size);
	return ((void *)array);
}
