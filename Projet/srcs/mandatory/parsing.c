/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:07:49 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/14 16:48:09 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_line_map(char *file)
{
	size_t	nb_line;
	int		fd;
	char	*ret;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	ret = get_next_line(fd);
	while (ret)
	{
		nb_line++;
		free(ret);
		ret = get_next_line(fd);
	}
	return (nb_line);
}

static char	**ft_convert_map(char **strs, char *file)
{
	int		i;
	int		fd;
	char	*ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	ret = get_next_line(fd);
	while (ret)
	{
		strs[i] = ft_strdup(ret);
		if (!strs[i])
			return (NULL);
		free(ret);
		ret = get_next_line(fd);
		i++;
	}
	strs[i] = NULL;
	if (ret)
		free(ret);
	return (strs);
}

char	**parse_and_check(int argc, char **argv, size_t *nb_line)
{
	char	**map;

	if (argc != 2)
		exit(0);
	*nb_line = ft_count_line_map(argv[1]);
	map = malloc(sizeof(char *) * (*nb_line + 1));
	if (!map)
		ft_error();
	map = ft_convert_map(map, argv[1]);
	if (!map)
		ft_error();
	if (ft_check(map, *nb_line) == 0)
	{
		ft_clean_tab2d(map);
		write(2, "Error\n", 6);
		ft_putstr_error("Mauvaise map\n");
		exit(0);
	}
	return (map);
}
