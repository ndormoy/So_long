/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 12:37:13 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 17:35:09 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	my_key2(int key_code, t_mlx *r_mlx)
{
	if (key_code == DOWN)
	{
		if (manage_key(r_mlx, DOWN) == 1)
		{
			ft_printf("Steps : %d\n", r_mlx->steps += 1);
			r_mlx->coord_y += 50;
		}
	}
	else if (key_code == LEFT)
	{
		if (manage_key(r_mlx, LEFT) == 1)
		{
			ft_printf("Steps : %d\n", r_mlx->steps += 1);
			r_mlx->coord_x -= 50;
		}
	}
	else if (key_code == RIGHT)
	{
		if (manage_key(r_mlx, RIGHT) == 1)
		{
			ft_printf("Steps : %d\n", r_mlx->steps += 1);
			r_mlx->coord_x += 50;
		}
	}
}

int	my_key(int key_code, void *mlx)
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
			ft_printf("Steps : %d\n", r_mlx->steps += 1);
			r_mlx->coord_y -= 50;
		}
	}
	my_key2(key_code, r_mlx);
	return (0);
}
