/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:37:13 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/17 18:57:19 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	refresh_img(t_mlx *r_mlx)
{
	r_mlx->steps += 1;
	mlx_put_image_to_window(r_mlx->ptr, r_mlx->win, r_mlx->img_grass, 0, 0);
	mlx_put_image_to_window(r_mlx->ptr, r_mlx->win, r_mlx->img_obs, 0, 0);
	mlx_string_put(r_mlx->ptr, r_mlx->win, 0, 0, 0x00FFFF00,
		ft_itoa(r_mlx->steps));
}

static void	my_key_bonus2(int key_code, t_mlx *r_mlx)
{
	if (key_code == DOWN)
	{
		if (manage_key(r_mlx, DOWN) == 1)
		{
			refresh_img(&(*r_mlx));
			r_mlx->coord_y += 50;
		}
	}
	else if (key_code == LEFT)
	{
		if (manage_key(r_mlx, LEFT) == 1)
		{
			refresh_img(&(*r_mlx));
			r_mlx->coord_x -= 50;
		}
	}
	else if (key_code == RIGHT)
	{
		if (manage_key(r_mlx, RIGHT) == 1)
		{
			refresh_img(&(*r_mlx));
			r_mlx->coord_x += 50;
		}
	}
}

int	my_key_bonus(int key_code, void *mlx)
{
	t_mlx	*r_mlx;

	mlx = (t_mlx *)mlx;
	r_mlx = (t_mlx *)mlx;
	if (key_code == ESC)
		ft_clear_all(&(*r_mlx));
	if (key_code == UP)
	{
		if (manage_key(r_mlx, UP) == 1)
		{
			refresh_img(&(*r_mlx));
			r_mlx->coord_y -= 50;
		}
	}
	my_key_bonus2(key_code, r_mlx);
	return (0);
}
