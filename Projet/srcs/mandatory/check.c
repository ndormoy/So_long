/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:07:47 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 16:45:32 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_real_elem(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

static void	init_elem(t_element *elem)
{
	elem->zaap = 0;
	elem->dof = 0;
	elem->perso = 0;
	elem->iop = 0;
}

static void	validate_elem(t_element *elem, char **map, size_t y, size_t x)
{
	if (map[y][x] == 'E')
		elem->zaap += 1;
	else if (map[y][x] == 'C')
		elem->dof += 1;
	else if (map[y][x] == 'P')
		elem->perso += 1;
}

static int	ft_check_elements(char **map, size_t size_line)
{
	size_t		y;
	size_t		x;
	t_element	elem;

	init_elem(&elem);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (x == size_line - 1 && map[y][x] == '\n')
				break ;
			else if (is_real_elem(map[y][x]) == 0)
				return (0);
			validate_elem(&elem, map, y, x);
			x++;
		}
		y++;
	}
	if (elem.zaap >= 1 && elem.dof >= 1 && elem.perso == 1)
		return (1);
	return (0);
}

int	ft_check(char **map, int nb_line)
{
	size_t	size_line;

	size_line = ft_strlen(map[0]);
	if (ft_check_size_line(map, nb_line, size_line) == 0)
		return (0);
	else if (ft_check_border(map, nb_line, size_line) == 0)
		return (0);
	else if (ft_check_elements(map, size_line) == 0)
		return (0);
	return (1);
}
