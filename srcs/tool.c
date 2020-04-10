/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:05:19 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 18:43:36 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_free_strsplit(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

static char	*ft_char_line(void)
{
	char	*mas;
	int		i;
	char	c;
	char	*fre;

	i = 0;
	if (!(mas = (char *)malloc(sizeof(char) * 17)))
		ft_error("Error malloc new line");
	fre = mas;
	while (i < 10)
	{
		mas[i] = '0' + i;
		i++;
	}
	c = 'A';
	while (c <= 'F')
	{
		mas[i++] = c;
		c++;
	}
	mas[i] = '\0';
	free(fre);
	return (mas);
}

int			ft_digate(char str, int base)
{
	char	*digit;
	int		i;

	digit = ft_char_line();
	i = 0;
	while (i < base)
	{
		if (digit[i] == ft_toupper(str))
			return (i);
		i++;
	}
	return (-1);
}

int			ft_prefix(char *str, int base)
{
	int		i;

	i = 0;
	if (base == 16)
	{
		if (str[i++] != '0')
			return (0);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (1);
	}
	return (0);
}

int			ft_is_number(char *str, int base)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\r')
		i++;
	if (base != 10 && (ft_prefix(&str[i], base) == 0))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_digate(str[i], base) >= 0)
	{
		i++;
		num++;
	}
	return (((str[i] == '\0') && num) ? 1 : 0);
}
