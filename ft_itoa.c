/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 10:52:11 by atable            #+#    #+#             */
/*   Updated: 2020/05/20 13:16:16 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative(int *n, int func)
{
	int	fl;

	fl = 0;
	if (*n < 0)
	{
		if (func == 1)
			fl = 1;
		if (*n == -2147483648)
		{
			if (func == 2)
				fl = 1;
			*n += 1;
		}
		*n = *n * (-1);
	}
	return (fl);
}

static int	len_num(int n, int *ten)
{
	int	len;
	int	tmp;
	int	fl;

	fl = negative(&n, 1);
	tmp = n;
	if (n == 0)
		return (2);
	len = 0;
	while (tmp > 0)
	{
		tmp = n / *ten;
		if (*ten == 1000000000)
		{
			len++;
			break ;
		}
		*ten *= 10;
		len++;
	}
	if (*ten != 1000000000)
		*ten /= 100;
	if (fl == 1)
		len++;
	return (len);
}

static void	*make_str(int ten, char *str, int n, int fl)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (ten != 1)
	{
		str[i++] = '0' + (n / ten);
		n = n % ten;
		ten /= 10;
	}
	if (fl == 1)
		n++;
	str[i] = '0' + n;
	str[++i] = '\0';
	return (0);
}

char		*ft_itoa(int n)
{
	int		fl;
	int		ten;
	char	*result;

	ten = 1;
	result = (char*)malloc(len_num(n, &ten) * sizeof(char));
	if (result)
	{
		fl = 0;
		if (n < 0)
		{
			fl = negative(&n, 2);
			result[0] = '-';
		}
		make_str(ten, result, n, fl);
	}
	return (result);
}
