/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:42:38 by atable            #+#    #+#             */
/*   Updated: 2020/05/22 12:58:26 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		num_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
		i++;
	return (i);
}

static char			*find_sign(char *str, char *sign)
{
	if (*str == '-' || *str == '+')
	{
		*sign = *str;
		return (++str);
	}
	*sign = '+';
	return (str);
}

static int			make_num(char *str)
{
	size_t			i;
	char			sign;
	long long int	num;

	str = find_sign(str, &sign);
	i = 0;
	num = 0;
	while (i < num_len(str))
	{
		num = num * 10;
		if (sign != '-')
		{
			if ((9223372036854775807 - num) < (str[i] - '0'))
				return (-1);
			num += str[i] - '0';
		}
		else
		{
			if ((-9223372036854775807 - 1 - num) > (str[i] + 0))
				return (0);
			num -= str[i] - '0';
		}
		i++;
	}
	return (num);
}

int					ft_atoi(const char *str)
{
	while ((*str == ' ') || (*str == '\t') || (*str == '\n') ||
			(*str == '\r') || (*str == '\v') || (*str == '\f'))
		str++;
	if (str)
	{
		if ((str[0] <= 47 || str[0] >= 58) &&
				str[0] != '+' && str[0] != '-')
			return (0);
		if (str[0] == '+' || str[0] == '-')
		{
			if (str[1] <= 47 || str[1] >= 58)
				return (0);
		}
		return (make_num((char *)str));
	}
	return (0);
}
