/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:02:33 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 18:01:36 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_possible(t_mlx *mlx, int dir, int *check)
{
	char	c;

	c = 0;
	if (dir == UP)
		c = mlx->map[(mlx->coord_y - 50) / 50][mlx->coord_x / 50];
	else if (dir == DOWN)
		c = mlx->map[(mlx->coord_y + 50) / 50][mlx->coord_x / 50];
	else if (dir == LEFT)
		c = mlx->map[mlx->coord_y / 50][(mlx->coord_x - 50) / 50];
	else if (dir == RIGHT)
		c = mlx->map[mlx->coord_y / 50][(mlx->coord_x + 50) / 50];
	if (c == '1')
		return (*check = 0);
	else if (c == 'C')
	{
		mlx->nb_dof += 1;
		return (*check = DOF);
	}
	else if (c == 'E' && mlx->nb_dof == mlx->nb_dof_max)
		ft_clear_all(&(*mlx));
	else if (c == 'E' && mlx->nb_dof != mlx->nb_dof_max)
		return (*check = NOT);
	return (*check = 1);
}

static int	manage_key4(t_mlx *mlx, int dir, int *check)
{
	if (dir == RIGHT)
	{
		if (check_possible(mlx, dir, check) >= 1)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
				mlx->coord_x, mlx->coord_y);
			if (mlx->map[mlx->coord_y / 50][(mlx->coord_x) / 50] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_zaap,
					mlx->coord_x, mlx->coord_y);
			if (*check == DOF)
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
					mlx->coord_x + 50, mlx->coord_y);
				mlx->map[mlx->coord_y / 50][(mlx->coord_x + 50) / 50] = '0';
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_right,
				mlx->coord_x + 50, mlx->coord_y);
			return (1);
		}
	}
	return (0);
}

static int	manage_key3(t_mlx *mlx, int dir, int *check)
{
	if (dir == LEFT)
	{
		if (check_possible(mlx, dir, check) >= 1)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
				mlx->coord_x, mlx->coord_y);
			if (mlx->map[mlx->coord_y / 50][(mlx->coord_x) / 50] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_zaap,
					mlx->coord_x, mlx->coord_y);
			if (*check == DOF)
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
					mlx->coord_x - 50, mlx->coord_y);
				mlx->map[mlx->coord_y / 50][(mlx->coord_x - 50) / 50] = '0';
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_left,
				mlx->coord_x - 50, mlx->coord_y);
			return (1);
		}
	}
	else if (manage_key4(mlx, dir, &(*check)) >= 1)
		return (1);
	return (0);
}

static int	manage_key2(t_mlx *mlx, int dir, int *check)
{
	if (dir == DOWN)
	{
		if (check_possible(mlx, dir, check) >= 1)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
				mlx->coord_x, mlx->coord_y);
			if (mlx->map[mlx->coord_y / 50][(mlx->coord_x) / 50] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_zaap,
					mlx->coord_x, mlx->coord_y);
			if (*check == DOF)
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
					mlx->coord_x, mlx->coord_y + 50);
				mlx->map[(mlx->coord_y + 50) / 50][mlx->coord_x / 50] = '0';
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_face,
				mlx->coord_x, mlx->coord_y + 50);
			return (1);
		}
	}
	else if (manage_key3(mlx, dir, &(*check)) >= 1)
		return (1);
	return (0);
}

int	manage_key(t_mlx *mlx, int dir)
{
	int	check;

	if (dir == UP)
	{
		if (check_possible(mlx, dir, &check) >= 1)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
				mlx->coord_x, mlx->coord_y);
			if (mlx->map[mlx->coord_y / 50][(mlx->coord_x) / 50] == 'E')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_zaap,
					mlx->coord_x, mlx->coord_y);
			if (check == DOF)
			{
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
					mlx->coord_x, mlx->coord_y - 50);
				mlx->map[(mlx->coord_y - 50) / 50][mlx->coord_x / 50] = '0';
			}
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_up,
				mlx->coord_x, mlx->coord_y - 50);
			return (1);
		}
	}
	else if (manage_key2(mlx, dir, &check) >= 1)
		return (1);
	return (0);
}
