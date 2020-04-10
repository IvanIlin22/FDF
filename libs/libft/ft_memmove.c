/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:29:15 by whumfrey          #+#    #+#             */
/*   Updated: 2018/11/26 20:49:24 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*n_dst;
	const char	*n_src;

	i = -1;
	n_dst = (char*)dst;
	n_src = (const char*)src;
	if (n_src < n_dst)
	{
		while (len)
		{
			n_dst[len - 1] = n_src[len - 1];
			len--;
		}
	}
	else
	{
		while (++i < len)
			n_dst[i] = n_src[i];
	}
	return (dst);
}
