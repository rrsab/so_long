#include "../so_long.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		key_hook(int keycode, t_data *img)
{
	int	i;
	int j;

	i = keycode;
	j = img->endian;
	printf("Press key_hook = %d\n", i);
	return (i);
}

int		ft_close(int keycode, t_data *img)
{
	int	i;

	i = keycode;
	i = img->endian;
	mlx_destroy_window(img->mlx_p, img->mlx_win);
	exit(EXIT_SUCCESS);
}