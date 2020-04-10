/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:56:20 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 16:32:31 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	int					i;
	int					znak;
	unsigned long long	res;

	i = 0;
	res = 0;
	znak = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
	str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		znak = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	if (res > 9223372036854775807 && znak == 1)
		return (-1);
	if (res > 9223372036854775807 && znak == -1)
		return (0);
	return (res * znak);
}
