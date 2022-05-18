/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:41:28 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 14:54:51 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	ft_printf(strerror(errno));
	ft_printf("\n");
	exit(0);
}

void	ft_putstr_error(char *s)
{
	if (s)
	{
		write(2, s, ft_strlen(s));
	}
}

int	ft_clear_all(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	ft_clean_tab2d(mlx->map);
	exit(0);
	return (0);
}
