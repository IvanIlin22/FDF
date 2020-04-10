/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:56:21 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/11 18:35:33 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	p = (*f)(lst);
	if (!p)
	{
		free(p);
		return (NULL);
	}
	new = p;
	while (lst->next)
	{
		lst = lst->next;
		p->next = (*f)(lst);
		if (!p)
		{
			free(p->next);
			return (NULL);
		}
		p = p->next;
	}
	return (new);
}
