#include <stdio.h>
#include <mlx.h>

void print_bit(int maxbit, int value)
{
    for(int i = maxbit-1; i >= 0; i--)
    {
        if((value >> i) & 1) //affiche le bit de valeur '1' en rouge
        {
            //      \033[91m : code couleur correspondant au rouge
            printf("\033[91m1\033[0m ");
            //      \033[0m : code correspondant à la remise des couleurs par défaut
        }
        else //affiche le bit de valeur '0' en bleu
        {
            //      \033[96m : code couleur correspondant au bleu ciel
            printf("\033[96m0\033[0m ");
        }
    }
    printf("\n");
}

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}		t_mlx;

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	add_shade(int color, int shade)
{
	int new_color;
	int	i;
	int	reset;

	new_color = create_trgb(shade, 0, 0, 0);
	reset = create_trgb(0, 255, 255, 255);
	color = color & reset;
	return (color);
}

int	my_key(int key_code, void *mlx)
{
	t_mlx	*real_mlx;
	static int		x = 400;
	static int		y = 249;
	int				tmp = 10;
	int color = create_trgb(255, 255, 0, 0);

	color = add_shade(color, 0);
	real_mlx = (t_mlx *)mlx;
	printf("Quelle touche ? : %d\n", key_code);
	while (tmp >= 0)
	{
		mlx_pixel_put(real_mlx->ptr, real_mlx->win, x, y, color);
		if (key_code == 13)
			y--;
		else if (key_code == 1)
			y++;
		else if (key_code == 0)
			x--;
		else if (key_code == 2)
			x++;
		tmp--;
	}
	
	return (0);
}

int main()
{
	t_mlx	*mlx;
	int		size_x = 1000;
	int		size_y = 500;
	void	*img;
	int		img_width;
	int		img_height;
	char	*relative_path = "./Xpm/Grass2.xpm";
	char	*relative_path2 = "./Xpm/Face.xpm";
	int		i = 0;
	int		j = 0;

	/* mlx->ptr = NULL;
	mlx->win = NULL; */
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, size_x, size_y, "Win_42");
	img = mlx_xpm_file_to_image(mlx->ptr, relative_path, &img_width, &img_height);
	while (j < 500)
	{
		while (i < 500)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, i, j);
			i += 50;
		}
		i = 0;
		j += 50;
	}
	
	i = 50;
	j = 150;
	img = mlx_xpm_file_to_image(mlx->ptr, relative_path2, &img_width, &img_height);
	while (j < 200)
	{
		while (i < 100)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, img, i, j);
			i += 50;
		}
		i = 0;
		j += 50;
	}

	mlx_loop(mlx->ptr);
}


