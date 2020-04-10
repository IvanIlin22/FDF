/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:46:23 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/04 19:30:28 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*n_haystack;

	i = 0;
	n_haystack = (char*)haystack;
	if (needle[0] == '\0')
		return (n_haystack);
	while (n_haystack[i])
	{
		if (n_haystack[i] == needle[0])
		{
			j = 1;
			while (n_haystack[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return (&n_haystack[i]);
		}
		i++;
	}
	return (NULL);
}
