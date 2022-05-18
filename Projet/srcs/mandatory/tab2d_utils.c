/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:13:56 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/13 17:13:57 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean_tab2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	free(strs);
}

void	print_tab_2d(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		ft_printf("strs[i] = %s", strs[i]);
		i++;
	}
}

size_t	ft_strlen_2d(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
