/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:33:06 by whumfrey          #+#    #+#             */
/*   Updated: 2018/11/26 19:41:37 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*n_dst;
	const char	*n_src;

	i = 0;
	n_dst = (char*)dst;
	n_src = (const char*)src;
	while (i < n)
	{
		n_dst[i] = n_src[i];
		i++;
	}
	return (dst);
}
