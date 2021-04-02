/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 13:57:20 by atable            #+#    #+#             */
/*   Updated: 2020/05/22 13:13:56 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	fl;
	int	indx;

	i = 0;
	fl = 0;
	indx = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (const char)c)
		{
			indx = i;
			fl = 1;
		}
		i++;
	}
	if (str[i] == (const char)c)
	{
		indx = i;
		fl = 1;
	}
	if (fl == 0)
		return (NULL);
	return ((char *)&str[indx]);
}
