/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:12:54 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 15:53:25 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	size_t	nb_line;
	t_mlx	*mlx;

	map = parse_and_check(argc, argv, &nb_line);
	mlx = ft_init(map, nb_line);
}
