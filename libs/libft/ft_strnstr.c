/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:37:12 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/04 19:53:38 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*n_haystack;

	i = 0;
	n_haystack = (char*)haystack;
	if (!*needle)
		return (n_haystack);
	while (n_haystack[i] && i < len)
	{
		if (n_haystack[i] == needle[0])
		{
			j = 0;
			while (n_haystack[i + j] == needle[j] && i + j < len && needle[j])
				j++;
			if (needle[j] == '\0')
				return (&n_haystack[i]);
		}
		i++;
	}
	return (NULL);
}
