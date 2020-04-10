/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:07:47 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/01 22:59:01 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(long n)
{
	int		size;
	int		znak;

	znak = 0;
	size = 1;
	if (n < 0)
	{
		znak = 1;
		n *= -1;
	}
	while (n >= 10)
	{
		n /= 10;
		size += 1;
	}
	size = size + znak;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		i;
	long	nb;

	nb = n;
	size = ft_size(nb);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	i = size - 1;
	while (nb >= 10)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
		i--;
	}
	str[i] = nb % 10 + '0';
	str[size] = '\0';
	return (str);
}
