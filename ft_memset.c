/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 14:41:28 by atable            #+#    #+#             */
/*   Updated: 2020/05/20 11:57:35 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *array, int symb, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)array;
	while (i < n)
	{
		str[i] = (char)symb;
		i++;
	}
	return (array);
}
