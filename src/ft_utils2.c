#include "../so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1)
		ft_play(vars, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

char	*ft_check_image(char *image)
{
	if (open(image, O_RDONLY) < 0)
		ft_error("File open error.", image);
	return (image);
}

void	ft_init_image(t_vars *vars, t_map *lst)
{
	vars->count = 0;
	vars->sum_goals = 0;
	vars->var_map = lst->map;
	vars->img_width = 64;
	vars->img_height = 64;
	vars->img_player_up = ft_check_image("./tiger_up.XPM");
	vars->img_player_right = ft_check_image("./tiger_right.XPM");
	vars->img_player_left = ft_check_image("./tiger_left.XPM");
	vars->img_player_down = ft_check_image("./tiger_down.XPM");
	vars->img_wall = ft_check_image("./wall.XPM");
	vars->img_ground = ft_check_image("./ground.XPM");
	vars->img_enemy = ft_check_image("./enemy.XPM");
	vars->img_boss = ft_check_image("./boss1.XPM");
	vars->img_victory = ft_check_image("./boss2.XPM");
	vars->img_victory1 = ft_check_image("./boss3.XPM");
}

void	ft_play(t_vars *vars, int keycode)
{
	if (keycode == 0)
		ft_move1(vars, 0);
	else if (keycode == 2)
		ft_move1(vars, 2);
	else if (keycode == 1)
		ft_move2(vars, 1);
	else if (keycode == 13)
		ft_move2(vars, 13);
}
void	ft_print_step(t_vars *vars)
{
	char *step;

	step = ft_itoa(vars->count);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_wall, \
						&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0 * 64, 0 * 64);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 1 * 64, 0 * 64);
	mlx_string_put(vars->mlx, vars->win, 25, 30, 0x00000000, "STEP=");
	mlx_string_put(vars->mlx, vars->win, 64, 30, 0x00000000, step);
	printf("Step: %d\n", vars->count);
	free(step);
}