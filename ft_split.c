/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atable <atable@student.school-21.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:46:36 by atable            #+#    #+#             */
/*   Updated: 2020/05/24 13:33:41 by atable           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	len_word(const char *s, char c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != c))
		i++;
	return (i);
}

static char	*make_str(char const *s, char c)
{
	int		j;
	int		len;
	char	*str;

	j = 0;
	len = len_word(s, c);
	if (!(str = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[j] && (s[j] != c))
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	**free_array(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = (char**)malloc((count_words(s, c) + 1) * sizeof(*str))))
		return (NULL);
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			if (!(str[i] = make_str(s, c)))
				return (free_array(str));
			i++;
			while (*s && (*s != c))
				s++;
		}
	}
	str[i] = NULL;
	return (str);
}
