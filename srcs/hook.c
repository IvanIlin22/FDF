/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:29:33 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 17:21:48 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_zoom(int keycode, t_height *str)
{
	if (keycode == PLUS || keycode == SCROLLUP)
		str->camera->zoom++;
	else if (keycode == MINUS || keycode == SCROLLDOWN)
		str->camera->zoom--;
	if (str->camera->zoom < 1)
		str->camera->zoom = 1;
	ft_draw(str, str->map);
}

static void		ft_rotate(int keycode, t_height *str)
{
	if (keycode == NUM2 || keycode == MAIN2)
		str->camera->alpha += 0.05;
	if (keycode == NUM8 || keycode == MAIN8)
		str->camera->alpha -= 0.05;
	if (keycode == NUM4 || keycode == MAIN4)
		str->camera->beta -= 0.05;
	if (keycode == NUM6 || keycode == MAIN6)
		str->camera->beta += 0.05;
	if (keycode == NUM1 || keycode == MAIN1)
		str->camera->jamma -= 0.05;
	if (keycode == NUM9 || keycode == MAIN9)
		str->camera->jamma += 0.05;
	if (keycode == 82)
	{
		str->camera->jamma = 0;
		str->camera->beta = 0;
		str->camera->alpha = 0;
	}
	ft_draw(str, str->map);
}

static int		key_press(int keycode, void *param)
{
	t_height	*str;

	str = (t_height *)(param);
	if (keycode == ESC)
		ft_exit();
	if (keycode == NUM1 || keycode == NUM2 || keycode == NUM4 ||
			keycode == NUM6 || keycode == NUM8 || keycode == NUM9 ||
		keycode == MAIN1 || keycode == MAIN2 || keycode == MAIN4 ||
		keycode == MAIN6 || keycode == MAIN8 || keycode == MAIN9 ||
		keycode == 82)
		ft_rotate(keycode, str);
	else if (keycode == PLUS || keycode == MINUS)
		ft_zoom(keycode, str);
	else if (keycode == 5 || keycode == 11 || keycode == 15)
	{
		str->map->color = keycode;
		ft_draw(str, str->map);
	}
	return (0);
}

static int		mouse_press(int buttom, int x, int y, void *param)
{
	t_height	*str;

	(void)x;
	(void)y;
	str = (t_height *)(param);
	if (buttom == SCROLLUP || buttom == SCROLLDOWN)
		ft_zoom(buttom, str);
	return (0);
}

void			ft_controls(t_height *str)
{
	mlx_hook(str->win, 2, 0, key_press, str);
	mlx_hook(str->win, 4, 0, mouse_press, str);
	mlx_hook(str->win, 17, 1L << 17, ft_exit, str);
}
