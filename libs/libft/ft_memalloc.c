/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:57:22 by whumfrey          #+#    #+#             */
/*   Updated: 2018/11/28 18:40:08 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*num;

	num = malloc(size);
	if (num == NULL)
		return (NULL);
	ft_bzero(num, size);
	return (num);
}
