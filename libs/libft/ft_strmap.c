/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:21:21 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/06 19:10:42 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*n_s;

	if (!s || !f)
		return (NULL);
	n_s = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (n_s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n_s[i] = (*f)(s[i]);
		i++;
	}
	n_s[i] = '\0';
	return (n_s);
}
