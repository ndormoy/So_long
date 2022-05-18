#include <mlx.h>


int	main(int argc, char **argv)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./Xpm/Iop.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;
	int		i = 0;
	int		j = 0;
	int		length = 600;
	int		width = 800;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, length, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	while (j < length)
	{
		while (i < width)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, i, j);
			i += 32;
		}
		i = 0;
		j += 32;
	}
	mlx_loop(mlx);
}