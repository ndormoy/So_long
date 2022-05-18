/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:58:02 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/18 11:23:53 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_place_enemy1(t_mlx *mlx, size_t x, size_t y, char **map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (map[j][i] == '0')
			{
				mlx->map[j][i] = 'I';
				mlx->x_enemy1 = i * 50;
				mlx->y_enemy1 = j * 50;
				return ;
			}
			i++;
		}
		j++;
	}
}

static void	ft_place_enemy2(t_mlx *mlx, size_t x, size_t y, char **map)
{
	size_t	save_x;

	save_x = x;
	y--;
	while (y > 0)
	{
		x = save_x - 1;
		while (x > 0)
		{
			if (map[y][x] == '0')
			{
				mlx->map[y][x] = 'I';
				mlx->x_enemy2 = x * 50;
				mlx->y_enemy2 = y * 50;
				return ;
			}
			x--;
		}
		y--;
	}
}

void	ft_init_enemy(t_mlx *mlx, size_t x_max, size_t y_max, char **map)
{
	if (mlx->nb_space == 0)
		return ;
	if (mlx->nb_space >= 1)
		ft_place_enemy1(&(*mlx), x_max, y_max, map);
	if (mlx->nb_space >= 2)
		ft_place_enemy2(&(*mlx), x_max, y_max, map);
}
