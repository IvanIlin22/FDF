/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:01:48 by whumfrey          #+#    #+#             */
/*   Updated: 2018/11/26 19:14:42 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *mas, int c, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)mas;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
