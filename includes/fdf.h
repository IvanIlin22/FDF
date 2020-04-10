/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whumfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:11:11 by whumfrey          #+#    #+#             */
/*   Updated: 2019/04/23 14:58:26 by whumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define OPEN_HEIGHT    1080
# define OPEN_WIDTH     1920
# define NUM8			91
# define MAIN8			28
# define NUM2			84
# define MAIN2			19
# define NUM4			86
# define MAIN4			21
# define NUM6			88
# define MAIN6			22
# define NUM1			83
# define MAIN1			18
# define NUM9			92
# define MAIN9			25
# define PLUS			69
# define MINUS			78
# define ESC			53
# define SCROLLUP		4
# define SCROLLDOWN		5

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

typedef struct			s_cor_color
{
	int					z;
	int					color;
	struct s_cor_color	*next;
}						t_cor_color;

typedef struct			s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
	int					color;
}						t_map;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_camera
{
	int					zoom;
	double				alpha;
	double				beta;
	double				jamma;
}						t_camera;

typedef struct			s_height
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_camera			*camera;
	t_map				*map;
}						t_height;

int						ft_read(const int fd, t_cor_color **str, t_map *map);
int						ft_get_color(t_point start, t_point end,
		t_point cur, t_point d);
t_point					ft_new_point(int x, int y, t_map *map);
t_map					*ft_map(void);
t_height				*ft_height(t_map *map);
t_camera				*ft_camera(t_height *str);
t_cor_color				*ft_movement_list(t_cor_color **tmp);
void					ft_add(t_cor_color **ptr, t_map *map);
void					ft_draw(t_height *height, t_map *map);
void					ft_controls(t_height *str);
t_point					ft_project(t_point p, t_height *height);
void					ft_error(char *s);
void					ft_free_strsplit(char **str);
int						ft_digate(char str, int base);
int						ft_prefix(char *str, int base);
int						ft_is_number(char *str, int base);
void					ft_add_unit(t_cor_color **ptr, t_cor_color *new);
int						ft_exit(void);

#endif
