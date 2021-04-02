/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:28:40 by atable            #+#    #+#             */
/*   Updated: 2020/05/20 12:31:13 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		indx1;
	int		indx2;

	if (!s1 || !set)
		return (NULL);
	indx1 = 0;
	while (s1 && ft_strchr((char *)set, s1[indx1]))
		indx1++;
	indx2 = ft_strlen(s1);
	while (indx2 && ft_strchr((char *)set, s1[indx2]))
		indx2--;
	if (indx2 < indx1)
		return (ft_strdup(""));
	result = ft_substr(s1, indx1, indx2 - indx1 + 1);
	return (result);
}
