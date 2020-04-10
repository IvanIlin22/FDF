/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 20:44:48 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/03 21:52:46 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*n_dst;
	unsigned char	*n_src;

	i = 0;
	n_dst = (unsigned char*)dst;
	n_src = (unsigned char*)src;
	while (i < n)
	{
		n_dst[i] = n_src[i];
		if (n_src[i] == (unsigned char)c)
			return (n_dst + i + 1);
		i++;
	}
	return (NULL);
}
