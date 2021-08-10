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