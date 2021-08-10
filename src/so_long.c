#include "../so_long.h"

int main(int argc, char **argv)
{
	//t_solong	params;
	char**		str;

	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (argc != 2)
		ft_perror("Error\n");
	str = argv;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 500, 500, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
//	params.mlx_p = mlx_init();
//	params.mlx_win = mlx_new_window(params.mlx_p, 1920, 1080, "So_Long");
//	mlx_loop(params.mlx_p);
	return 0;
}
