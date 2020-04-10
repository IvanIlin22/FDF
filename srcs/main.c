/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:03:37 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/21 15:34:05 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_exit(void)
{
	exit(1);
}

int				main(int argv, char **argc)
{
	int			fd;
	t_cor_color	*cor;
	t_map		*map;
	t_height	*str;

	if (argv == 2)
	{
		map = ft_map();
		fd = open(argc[1], O_RDONLY);
		if (fd < 0)
			ft_error("OPEN Error");
		if (ft_read(fd, &cor, map) < 0)
			ft_error("ERROR map reading");
		str = ft_height(map);
		ft_add(&cor, map);
		str->camera = ft_camera(str);
		ft_draw(str, str->map);
		ft_controls(str);
		mlx_loop(str->mlx);
	}
	else
		ft_error("error many argumets");
}
