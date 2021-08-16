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

# define M 64
# define A 97
# define W 119
# define D 100
# define S 115
# define ESC 65307
# define SAND 0xF5DCA0
# define BLACK 0xFF000000
# define RIGHT 65361
# define LEFR 65363
# define ESC 65307

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
int		key_hook(int keycode, t_data *img);
int		ft_close(int keycode, t_data *img);

#endif
