/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:11:46 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/13 17:14:04 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_mlx **mlx, int size_x, int size_y)
{
	int		img_width;
	int		img_height;
	const char	path[10][20] = {"./Xpm/dofus.xpm", "./Xpm/face.xpm", "./Xpm/grass.xpm", 
		"./Xpm/iop.xpm", "./Xpm/left.xpm", "./Xpm/obs.xpm", "./Xpm/right.xpm", 
		"./Xpm/up.xpm", "./Xpm/zaap.xpm"};

	(*mlx)->ptr = mlx_init();
	(*mlx)->win = mlx_new_window((*mlx)->ptr, size_x, size_y, "Win_42");
	(*mlx)->img_dof = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[0], &img_width, &img_height);
	(*mlx)->img_face = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[1], &img_width, &img_height);
	(*mlx)->img_grass = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[2], &img_width, &img_height);
	(*mlx)->img_iop = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[3], &img_width, &img_height);
	(*mlx)->img_left = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[4], &img_width, &img_height);
	(*mlx)->img_obs = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[5], &img_width, &img_height);
	(*mlx)->img_right = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[6], &img_width, &img_height);
	(*mlx)->img_up = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[7], &img_width, &img_height);
	(*mlx)->img_zaap = mlx_xpm_file_to_image((*mlx)->ptr, (char *)path[8], &img_width, &img_height);
}

int main()
{
	t_mlx	*mlx;
	int		i = 0;
	int		j = 0;

	ft_init(&mlx, 1000, 500);
	while (j < 500)
	{
		while (i < 500)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass, i, j);
			i += 50;
		}
		i = 0;
		j += 50;
	}
	
	i = 50;
	j = 150;
	while (j < 200)
	{
		while (i < 100)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_face, i, j);
			i += 50;
		}
		i = 0;
		j += 50;
	}

	mlx_loop(mlx->ptr);
}