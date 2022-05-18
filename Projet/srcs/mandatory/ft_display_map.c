/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:35:00 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 17:46:50 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	ft_display_map(t_mlx *mlx, char **map, size_t x, size_t y)
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
	mlx_key_hook(mlx->win, my_key, &(*mlx));
	mlx_loop(mlx->ptr);
}
