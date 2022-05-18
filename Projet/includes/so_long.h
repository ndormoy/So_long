/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:47:16 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/18 11:18:49 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define DOF 100
# define NOT 150
# define EXIT 200

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img_dof;
	void	*img_face;
	void	*img_grass;
	void	*img_iop;
	void	*img_left;
	void	*img_obs;
	void	*img_right;
	void	*img_up;
	void	*img_zaap;
	char	**map;
	size_t	x;
	size_t	coord_x;
	size_t	coord_y;
	size_t	steps;
	size_t	nb_dof;
	size_t	nb_dof_max;
	void	*img_dofup;
	void	*img_iop15;
	void	*img_iop30;
	int		nb_space;
	int		x_enemy1;
	int		y_enemy1;
	int		x_enemy2;
	int		y_enemy2;
}		t_mlx;

typedef struct s_element
{
	int	grass;
	int	wall;
	int	zaap;
	int	dof;
	int	perso;
	int	iop;
}		t_element;

size_t	ft_strlen_2d(char **strs);
void	print_tab_2d(char **strs);
void	ft_clean_tab2d(char **strs);

int		ft_check_size_line(char **map, size_t nb_line, size_t size_line);
int		ft_check_border(char **map, int nb_line, size_t size_line);
int		ft_check(char **map, int nb_line);
char	**parse_and_check(int argc, char **argv, size_t *nb_line);

t_mlx	*ft_init(char **map, size_t nb_line);
int		my_key(int key_code, void *mlx);

void	ft_error(void);
void	ft_putstr_error(char *s);
int		ft_clear_all(t_mlx *mlx);

int		manage_key(t_mlx *mlx, int dir);

void	ft_display_map(t_mlx *mlx, char **map, size_t x, size_t y);

int		my_key_bonus(int key_code, void *mlx);
t_mlx	*ft_init_bonus(char **map, size_t nb_line);
void	ft_display_map_bonus(t_mlx *mlx, char **map, size_t x, size_t y);
void	ft_init_enemy(t_mlx *mlx, size_t x_max, size_t y_max, char **map);

void	ft_refresh_map(t_mlx *mlx, char **map, size_t x, size_t y);
#endif