#include "../so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1)
		ft_play(vars, keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return 0;
}

char	*ft_check_image(char *image)
{
	if (open(image, O_RDONLY) < 0)
		ft_error(image);
		//ft_error("File can not open");
	return (image);
}

void ft_init_image(t_vars *vars,st_map *lst)
{
	vars->count = 0;
	vars->sum_goals = 0;
	vars->var_map = lst->map;
	vars->img_width = 64;
	vars->img_height = 64;
	vars->img_player_up = ft_check_image("./tiger_up1.XPM");
	vars->img_player_right = ft_check_image("./tiger_right1.XPM");
	vars->img_player_left = ft_check_image("./tiger_left1.XPM");
	vars->img_player_down = ft_check_image("./tiger_down1.XPM");
	vars->img_wall = ft_check_image("./wall.XPM");
	vars->img_ground = ft_check_image("./ground1.XPM");
	vars->img_enemy = ft_check_image("./enemy1.XPM");
	vars->img_boss = ft_check_image("./boss1.XPM");
	vars->img_victory = ft_check_image("./boss2.XPM");
	vars->img_victory1 = ft_check_image("./boss3.XPM");
}
