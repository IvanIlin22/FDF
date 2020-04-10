/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:03:58 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 17:15:54 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_pixel(t_height *height, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < OPEN_WIDTH && y > 0 && y < OPEN_HEIGHT)
	{
		if (height->map->color == 15)
		{
			i = (x * height->bits_per_pixel / 8) + (y * height->size_line);
			height->data_addr[i] = color;
			height->data_addr[++i] = color >> 8;
			height->data_addr[++i] = color >> 16;
		}
		else if (height->map->color == 5)
		{
			i = (x * height->bits_per_pixel / 8) + (y * height->size_line);
			height->data_addr[i] = color >> 8;
			height->data_addr[++i] = color >> 16;
			height->data_addr[++i] = color >> 24;
		}
		else if (height->map->color == 11)
		{
			i = (x * height->bits_per_pixel / 8) + (y * height->size_line);
			height->data_addr[i] = color >> 16;
			height->data_addr[++i] = color >> 16;
		}
	}
}

static void	ft_window(t_height *height)
{
	int		i;
	int		*point;

	point = (int *)(height->data_addr);
	i = 0;
	while (i < OPEN_HEIGHT * OPEN_WIDTH)
	{
		point[i] = 0x222222;
		i++;
	}
}

static void	ft_draw_line(t_point p1, t_point p2, t_height *str)
{
	t_point	d;
	t_point	sign;
	t_point	cur;
	double	err[2];

	d.x = abs(p2.x - p1.x);
	d.y = abs(p2.y - p1.y);
	sign.x = (p1.x < p2.x) ? 1 : -1;
	sign.y = (p1.y < p2.y) ? 1 : -1;
	err[0] = d.x - d.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		ft_put_pixel(str, cur.x, cur.y, ft_get_color(p1, p2, cur, d));
		if ((err[1] = err[0] * 2) > -d.y)
		{
			err[0] -= d.y;
			cur.x += sign.x;
		}
		if (err[1] < d.x)
		{
			err[0] += d.x;
			cur.y += sign.y;
		}
	}
}

static void	ft_menu(t_height *height)
{
	int		y;

	y = 0;
	mlx_string_put(height->mlx, height->win, 120, y += 20,
			0x9A1F6A, "How to Use");
	mlx_string_put(height->mlx, height->win, 60, y += 15, 0x9A1F6A,
			"Zoom: Scroll or +/-");
	mlx_string_put(height->mlx, height->win, 60, y += 15,
			0x9A1F6A, "Rotate around the X-Axis - 2/8");
	mlx_string_put(height->mlx, height->win, 60, y += 15,
			0x9A1F6A, "Rotate around the Y-Axis - 4/6");
	mlx_string_put(height->mlx, height->win, 60, y += 15,
			0x9A1F6A, "Rotate around the Z-Axis - 1/9");
	mlx_string_put(height->mlx, height->win, 60, y += 15,
			0x9A1F6A, "R - change color");
	mlx_string_put(height->mlx, height->win, 60, y += 15,
			0x9A1F6A, "G - change color");
	mlx_string_put(height->mlx, height->win, 60, y += 15,
			0x9A1F6A, "B - change color");
}

void		ft_draw(t_height *height, t_map *map)
{
	int		x;
	int		y;

	ft_window(height);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != height->map->width - 1)
				ft_draw_line(ft_project(ft_new_point(x, y, map), height),
						ft_project(ft_new_point(x + 1, y, map),
							height), height);
			if (y != height->map->height - 1)
				ft_draw_line(ft_project(ft_new_point(x, y, map), height),
						ft_project(ft_new_point(x, y + 1, map),
							height), height);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(height->mlx, height->win, height->img, 0, 0);
	ft_menu(height);
}
