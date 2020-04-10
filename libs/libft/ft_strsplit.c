/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:39:03 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/01 21:51:43 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_row(char const *s, char c)
{
	int		str;
	int		i;
	int		count;

	str = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && str == 1)
			str = 0;
		if (s[i] != c && str == 0)
		{
			str = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	len_row(char const *s, char c)
{
	int		size;

	size = 0;
	while (*s != '\0' && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static char	*fillrow(char const *s, int start, int len)
{
	int		i;
	char	*row;

	i = 0;
	row = (char*)malloc(sizeof(char) * (len + 1));
	if (row == NULL)
		return (NULL);
	while (i < len)
	{
		row[i] = s[i + start];
		i++;
	}
	row[i] = '\0';
	return (row);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		index;

	if (!s || !c)
		return (NULL);
	size = count_row(s, c);
	str = (char**)malloc(sizeof(char*) * (size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (size--)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		str[index] = fillrow(s, i, len_row(&s[i], c));
		i += len_row(&s[i], c);
		index++;
	}
	str[index] = NULL;
	return (str);
}
