#include "../so_long.h"
//zarahatsagortsyan

int main(int argc, char **argv)
{
	//t_solong	game;
	char**		str;

	t_data	img;

	if (argc != 2)
		ft_perror("Error\n");
	str = argv;


	img.mlx_p = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx_p, 920, 500, "so_long");
	img.img = mlx_new_image(img.mlx_p, 920, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	my_mlx_pixel_put(&img, 500, 200, 0x00FF0000);
	my_mlx_pixel_put(&img, 500, 300, 0x00FF0000);
	mlx_string_put(img.mlx_p, img.mlx_win, 200, 250, 0x50FF0000, "str");
	mlx_put_image_to_window(img.mlx_p, img.mlx_win, img.img, 0, 0);
	mlx_hook(img.mlx_win, 2, 1L << 0, key_hook, &img);
	mlx_hook(img.mlx_win, 33, 1L << 5, ft_close, &img);
	mlx_loop(img.mlx_p);
//	params.mlx_p = mlx_init();
//	params.mlx_win = mlx_new_window(params.mlx_p, 1920, 1080, "So_Long");
//	mlx_loop(params.mlx_p);
	return 0;
}
