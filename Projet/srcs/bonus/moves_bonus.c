/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:02:33 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/17 12:17:17 by ndormoy          ###   ########.fr       */
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
	else if (c == 'I')
		ft_clear_all(&(*mlx));
	else if (c == 'E' && mlx->nb_dof == mlx->nb_dof_max)
		ft_clear_all(&(*mlx));
	else if (c == 'E' && mlx->nb_dof != mlx->nb_dof_max)
		return (*check = NOT);
	return (*check = 1);
}

void	display_dof_anim(t_mlx *mlx, int x, int y)
{
	int		i;
	void	*perso;

	perso = NULL;
	i = 0;
	if (y == -50)
		perso = mlx->img_up;
	else if (y == 50)
		perso = mlx->img_face;
	else if (x == -50)
		perso = mlx->img_left;
	else if (x == 50)
		perso = mlx->img_right;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_dofup,
		mlx->coord_x + x, mlx->coord_y + y);
}

static void	manage_img(t_mlx *mlx, int x, int y, int *check)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
		mlx->coord_x, mlx->coord_y);
	if (mlx->map[mlx->coord_y / 50][(mlx->coord_x) / 50] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_zaap,
			mlx->coord_x, mlx->coord_y);
	if (*check == DOF)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_grass,
			mlx->coord_x + x, mlx->coord_y + y);
		mlx->map[(mlx->coord_y + y) / 50][(mlx->coord_x + x) / 50] = '0';
	}
	if (y == -50)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_up,
			mlx->coord_x + x, mlx->coord_y + y);
	else if (y == 50)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_face,
			mlx->coord_x + x, mlx->coord_y + y);
	else if (x == -50)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_left,
			mlx->coord_x + x, mlx->coord_y + y);
	else if (x == 50)
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_right,
			mlx->coord_x + x, mlx->coord_y + y);
	if (*check == DOF)
		display_dof_anim(mlx, x, y);
}

int	manage_key(t_mlx *mlx, int dir)
{
	int	check;

	if (check_possible(mlx, dir, &check) == 0)
		return (0);
	else if (dir != UP && dir != DOWN && dir != LEFT && dir != RIGHT)
		return (0);
	if (dir == UP)
		manage_img(&(*mlx), 0, -50, &check);
	else if (dir == DOWN)
		manage_img(&(*mlx), 0, 50, &check);
	else if (dir == LEFT)
		manage_img(&(*mlx), -50, 0, &check);
	else if (dir == RIGHT)
		manage_img(&(*mlx), 50, 0, &check);
	return (1);
}
