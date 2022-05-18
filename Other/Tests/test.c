#include <stdio.h>
#include <stdlib.h>
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
	char	*ptr;
	char	*win;
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
	if (key_code == 53)
	{
		mlx_destroy_window(real_mlx->ptr, real_mlx->win);
		exit(0);
	}
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
	int		x;
	int		y;
	void	*img;

	x = 400;
	y = 250;
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 1000, 500, "Win_42");
	while (y < 300)
	{
		x = 400;
		while (x < 500)
		{
			mlx_pixel_put(mlx->ptr, mlx->win, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	mlx_key_hook(mlx->win, my_key, &(*mlx));
	mlx_loop(mlx->ptr);
}
