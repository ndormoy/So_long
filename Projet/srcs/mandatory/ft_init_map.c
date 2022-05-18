/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:17:00 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 16:46:42 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_img(t_mlx **mlx)
{
	int			img_width;
	int			img_height;
	const char	path[10][20] = {"./Xpm/dofus.xpm", "./Xpm/face.xpm",
		"./Xpm/grass.xpm", "./Xpm/iop.xpm", "./Xpm/left.xpm", "./Xpm/obs.xpm",
		"./Xpm/right.xpm", "./Xpm/up.xpm", "./Xpm/zaap.xpm"};

	(*mlx)->img_dof = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[0],
			&img_width, &img_height);
	(*mlx)->img_face = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[1],
			&img_width, &img_height);
	(*mlx)->img_grass = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[2],
			&img_width, &img_height);
	(*mlx)->img_iop = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[3],
			&img_width, &img_height);
	(*mlx)->img_left = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[4],
			&img_width, &img_height);
	(*mlx)->img_obs = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[5],
			&img_width, &img_height);
	(*mlx)->img_right = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[6],
			&img_width, &img_height);
	(*mlx)->img_up = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[7],
			&img_width, &img_height);
	(*mlx)->img_zaap = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[8],
			&img_width, &img_height);
}

static void	ft_init_tools(t_mlx **mlx, int size_x, int size_y, char **map)
{
	(*mlx)->map = map;
	(*mlx)->x = 0;
	(*mlx)->coord_x = 0;
	(*mlx)->coord_y = 0;
	(*mlx)->steps = 0;
	(*mlx)->nb_dof = 0;
	(*mlx)->nb_dof_max = 0;
	(*mlx)->ptr = mlx_init();
	(*mlx)->win = mlx_new_window((*mlx)->ptr, size_x, size_y, "so_long");
}

static void	ft_find_coord(t_mlx **mlx, size_t x, size_t y, char **map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			mlx_put_image_to_window((*mlx)->ptr, (*mlx)->win,
				(*mlx)->img_grass, i, j);
			if (map[j / 50][i / 50] == 'P')
			{
				(*mlx)->coord_x = i;
				(*mlx)->coord_y = j;
			}
			else if (map[j / 50][i / 50] == 'C')
				(*mlx)->nb_dof_max += 1;
			i += 50;
		}
		j += 50;
	}
}

t_mlx	*ft_init(char **map, size_t nb_line)
{
	t_mlx	*mlx;
	size_t	x;
	size_t	y;

	x = (ft_strlen(map[0]) - 1) * 50;
	y = nb_line * 50;
	ft_init_tools(&mlx, x, y, map);
	ft_init_img(&mlx);
	ft_find_coord(&mlx, x, y, map);
	ft_display_map(mlx, map, x, y);
	return (mlx);
}
