/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:48:48 by whumfrey          #+#    #+#             */
/*   Updated: 2018/12/08 15:15:33 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	p = *alst;
	while (p != NULL)
	{
		(*del)(p->content, p->content_size);
		free(p);
		p = p->next;
	}
	*alst = NULL;
}
