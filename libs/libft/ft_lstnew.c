/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:14:16 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/10 18:30:59 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy(void const *content, size_t size)
{
	size_t	i;
	char	*p;
	char	*con;

	i = 0;
	p = (char*)malloc(sizeof(size));
	con = (char*)content;
	if (p == NULL)
		return (NULL);
	while (con[i])
	{
		p[i] = con[i];
		i++;
	}
	return ((void*)p);
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	p = (t_list*)malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		if ((p->content = copy(content, content_size)) == NULL)
			return (NULL);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}
