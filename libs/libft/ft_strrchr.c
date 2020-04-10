/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:14:34 by whumfrey          #+#    #+#             */
/*   Updated: 2018/11/25 15:44:58 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*n_s;
	int		i;

	i = 0;
	n_s = (char*)s;
	while (s[i])
		i++;
	while (n_s[i] != c)
	{
		if (n_s[i] == s[0])
			return (NULL);
		i--;
	}
	return (&n_s[i]);
}
