/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:35:00 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/18 11:21:52 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_animation2(t_mlx *mlx, int i)
{
	if (i <= 20)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_iop15, mlx->x_enemy1, mlx->y_enemy1);
		if (mlx->x_enemy2 != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img_iop15, mlx->x_enemy2, mlx->y_enemy2);
	}
	else if (i <= 30)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_iop30, mlx->x_enemy1, mlx->y_enemy1);
		if (mlx->x_enemy2 != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img_iop30, mlx->x_enemy2, mlx->y_enemy2);
	}
}

int	sprite_animation(t_mlx *mlx)
{
	static int	i = 0;

	if (mlx->x_enemy1 == 0)
		return (0);
	i++;
	mlx_put_image_to_window(mlx->ptr, mlx->win,
		mlx->img_grass, mlx->x_enemy1, mlx->y_enemy1);
	if (mlx->x_enemy2 != 0)
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_grass, mlx->x_enemy2, mlx->y_enemy2);
	if (i <= 10)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_iop, mlx->x_enemy1, mlx->y_enemy1);
		if (mlx->x_enemy2 != 0)
			mlx_put_image_to_window(mlx->ptr, mlx->win,
				mlx->img_iop, mlx->x_enemy2, mlx->y_enemy2);
	}
	else if (i <= 20 || i <= 30)
		sprite_animation2(mlx, i);
	else if (i == 31)
		i = 0;
	return (1);
}

static void	ft_display_img(t_mlx *mlx, char **map, size_t i, size_t j)
{
	if (map[j / 50][i / 50] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_obs, i, j);
	else if (map[j / 50][i / 50] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_zaap, i, j);
	else if (map[j / 50][i / 50] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_dof, i, j);
	else if (map[j / 50][i / 50] == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_face, i, j);
	else if (map[j / 50][i / 50] == 'I')
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->img_iop, i, j);
}

void	ft_display_map_bonus(t_mlx *mlx, char **map, size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_display_img(&(*mlx), map, i, j);
			i += 50;
		}
		j += 50;
	}
	mlx_hook(mlx->win, 17, 0L, ft_clear_all, &(*mlx));
	mlx_key_hook(mlx->win, my_key_bonus, &(*mlx));
	mlx_loop_hook(mlx->ptr, &sprite_animation, mlx);
	mlx_loop(mlx->ptr);
}
