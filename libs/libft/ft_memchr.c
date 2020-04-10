/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:10:22 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/03 19:13:14 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*n_s;
	size_t			i;

	i = 0;
	n_s = (unsigned char*)s;
	while (i < n)
	{
		if (n_s[i] == (unsigned char)c)
			return ((void*)&n_s[i]);
		i++;
	}
	return (NULL);
}
