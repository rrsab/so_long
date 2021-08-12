#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "mlx/mlx.h"

typedef struct s_solong
{
	void	*mlx_p;
	void	*mlx_win;

}	t_solong;

typedef struct	s_data
{
	void	*mlx_p;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_perror(char *str);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
