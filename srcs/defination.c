/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defination.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:22:47 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/20 17:03:27 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*ft_map(void)
{
	t_map		*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_error("Error map malloc");
	map->width = 0;
	map->height = 0;
	map->colors_arr = NULL;
	map->coords_arr = NULL;
	map->color = 15;
	return (map);
}

t_height		*ft_height(t_map *map)
{
	t_height	*str;

	if (!(str = (t_height *)ft_memalloc(sizeof(t_height))))
		ft_error("Error mallopc t_height");
	str->mlx = mlx_init();
	str->win = mlx_new_window(str->mlx, OPEN_WIDTH, OPEN_HEIGHT, "FDF");
	str->img = mlx_new_image(str->mlx, OPEN_WIDTH, OPEN_HEIGHT);
	str->data_addr = mlx_get_data_addr(str->img, &(str->bits_per_pixel),
			&(str->size_line), &(str->endian));
	str->map = map;
	return (str);
}

t_camera		*ft_camera(t_height *str)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		ft_error("Error camera malloc");
	camera->alpha = 0;
	camera->beta = 0;
	camera->jamma = 0;
	camera->zoom = fmin((OPEN_WIDTH / str->map->width / 2),
			OPEN_HEIGHT / str->map->height / 2);
	return (camera);
}

t_cor_color		*ft_movement_list(t_cor_color **tmp)
{
	t_cor_color	*new;

	new = NULL;
	if (tmp && *tmp)
	{
		new = *tmp;
		*tmp = (*tmp)->next;
	}
	return (new);
}

void			ft_add(t_cor_color **ptr, t_map *map)
{
	int			i;
	int			index;
	t_cor_color	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_cor_color))))
		ft_error("Error malloc add");
	i = map->width * map->height;
	if (!(map->coords_arr = ft_memalloc(sizeof(int) * i)))
		ft_error("Error malloc map_coords_arr");
	if (!(map->colors_arr = ft_memalloc(sizeof(int) * i)))
		ft_error("Error malloc map_colors_arr");
	index = map->width * map->height - 1;
	while (index >= 0 && (tmp = ft_movement_list(ptr)))
	{
		map->coords_arr[index] = tmp->z;
		map->colors_arr[index] = tmp->color;
		index--;
		free(tmp);
	}
}
