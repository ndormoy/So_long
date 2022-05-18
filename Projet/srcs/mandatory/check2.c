/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:09:56 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/18 11:02:00 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_one(int x, int y, int size_line, int nb_line)
{
	if (x == 0 || x == size_line - 2)
		return (1);
	else if ((y == 0 && x != size_line - 1)
		|| (y == nb_line - 1 && x != size_line - 1))
		return (1);
	return (0);
}

int	ft_c_cmp(char c1, char c2)
{
	return (c1 - c2);
}

int	ft_check_border(char **map, int nb_line, size_t size_line)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_one(x, y, size_line, nb_line) == 1)
			{
				if (ft_c_cmp(map[y][x], '1') != 0)
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_check_size_line(char **map, size_t nb_line, size_t size_line)
{
	size_t	i;

	i = 0;
	if (size_line <= 2 || size_line - 1 <= nb_line)
		return (0);
	while (map[i])
	{
		if ((size_line != ft_strlen(map[i])) && (i != nb_line - 1))
			return (0);
		else if ((size_line - 1 != ft_strlen(map[i])) && (i == nb_line - 1))
			return (0);
		else if ((map[i][size_line - 1] != '\n') && (i != nb_line - 1))
			return (0);
		i++;
	}
	return (1);
}
