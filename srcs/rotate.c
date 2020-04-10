/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:04:27 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 17:33:42 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_x(int *y, int *z, double alpha)
{
	int		old_y;

	old_y = *y;
	*y = old_y * cos(alpha) + *z * sin(alpha);
	*z = -old_y * sin(alpha) + *z * cos(alpha);
}

static void	ft_rotate_y(int *x, int *z, double beta)
{
	int		old_x;

	old_x = *x;
	*x = old_x * cos(beta) + *z * sin(beta);
	*z = -old_x * sin(beta) + *z * cos(beta);
}

static void	ft_rotate_z(int *x, int *y, double jamma)
{
	int		old_x;
	int		old_y;

	old_y = *y;
	old_x = *x;
	*x = old_x * cos(jamma) - old_y * sin(jamma);
	*y = old_x * sin(jamma) + old_y * cos(jamma);
}

t_point		ft_project(t_point p, t_height *height)
{
	p.x *= height->camera->zoom;
	p.y *= height->camera->zoom;
	p.z *= height->camera->zoom;
	p.x -= (height->map->width * height->camera->zoom) / 2;
	p.y -= (height->map->height * height->camera->zoom) / 2;
	ft_rotate_x(&p.y, &p.z, height->camera->alpha);
	ft_rotate_y(&p.x, &p.z, height->camera->beta);
	ft_rotate_z(&p.x, &p.y, height->camera->jamma);
	p.x += OPEN_WIDTH / 2;
	p.y += (OPEN_HEIGHT / 2);
	return (p);
}

void		ft_error(char *s)
{
	if (s)
		write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	exit(1);
}
