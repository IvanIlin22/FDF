/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:04:15 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 16:57:49 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_precent(int start, int end, int cur)
{
	double		distance;
	double		placement;

	distance = end - start;
	placement = end - cur;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		ft_get_lignt(int start, int end, double precant)
{
	return ((1 - precant) * start + precant * end);
}

int				ft_get_color(t_point start, t_point end, t_point cur, t_point d)
{
	int			red;
	int			green;
	int			blue;
	double		precent;

	if (end.color == cur.color)
		return (cur.color);
	if (d.x > d.y)
		precent = ft_precent(start.x, end.x, cur.x);
	else
		precent = ft_precent(start.y, end.y, cur.y);
	red = ft_get_lignt((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, precent);
	green = ft_get_lignt((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, precent);
	blue = ft_get_lignt(start.color & 0xFF, end.color & 0xFF, precent);
	return (red << 16 | green << 8 | blue);
}

int				ft_color(int z, t_map *fdf)
{
	double percentage;

	percentage = ft_precent(0, 15, z);
	if (percentage < 0.2)
		return (0x9A1F6A);
	else if (percentage < 0.4)
		return (0xC2294E);
	else if (percentage < 0.6)
		return (0xEC4B27);
	else if (percentage < 0.8)
		return (0xEF8633);
	else
		return (0xF3AF3D);
}

t_point			ft_new_point(int x, int y, t_map *map)
{
	t_point		p;
	int			i;

	i = y * map->width + x;
	p.x = x;
	p.y = y;
	p.z = map->coords_arr[i];
	if (map->colors_arr[i] == -1)
		p.color = ft_color(p.z, map);
	else
		p.color = map->colors_arr[i];
	return (p);
}
