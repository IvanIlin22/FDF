/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:03:45 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 17:30:21 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_atoi_base(char *str, int base)
{
	int				res;
	int				i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\r')
		str[i]++;
	if (base != 10 && !ft_prefix(&str[i], base))
		ft_error("ERROR MAP");
	if (base == 16 || base == 2)
		i += 2;
	while (ft_digate(str[i], base) >= 0)
	{
		res = res * base + ft_digate(str[i], base);
		i++;
	}
	return (res);
}

void				ft_add_unit(t_cor_color **alst, t_cor_color *new)
{
	if (alst)
	{
		if (new)
			new->next = *alst;
		*alst = new;
	}
}

static t_cor_color	*ft_new_elem(char *s)
{
	t_cor_color		*str;
	char			**arr;

	if (!(str = (t_cor_color *)ft_memalloc(sizeof(t_cor_color))))
		ft_error("ERROR  malloc t_cor_color");
	if (!(arr = ft_strsplit(s, ',')))
		ft_error("ERROR  ft_strsplit");
	if (!(ft_is_number(arr[0], 10)))
		ft_error("ERROR MAP1");
	if (arr[1] && !(ft_is_number(arr[1], 16)))
		ft_error("ERROR color");
	str->z = ft_atoi(arr[0]);
	str->color = arr[1] ? ft_atoi_base(arr[1], 16) : -1;
	str->next = NULL;
	ft_free_strsplit(arr);
	return (str);
}

static void			ft_new_line(char **line, t_cor_color **str, t_map *map)
{
	int				width;

	width = 0;
	while (*line)
	{
		ft_add_unit(str, ft_new_elem(*(line++)));
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		ft_error("ERROR map");
}

int					ft_read(const int fd, t_cor_color **str, t_map *map)
{
	char			*line;
	char			**tmp;
	int				res;

	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (!(tmp = ft_strsplit(line, ' ')))
			ft_error("ERROR ft_strsplit");
		ft_new_line(tmp, str, map);
		ft_free_strsplit(tmp);
		ft_strdel(&line);
		map->height++;
	}
	return (res);
}
