/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:37:21 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 18:31:23 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_probel(char const *s)
{
	int		size;
	int		i;
	int		probel;

	i = 0;
	size = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	probel = i;
	if (s[i] != '\0')
	{
		i = size - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i--;
			probel++;
		}
	}
	return (size - probel);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		k;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	len = ft_probel(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (k < len)
	{
		str[k] = s[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
