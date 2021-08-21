#include "../so_long.h"

void	ft_image_print1(char a, t_vars *vars, int i, int k)
{
	if (a == 'P')
	{
		vars->player_x = i;
		vars->player_y = k;
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_player_up, \
		&vars->img_width, &vars->img_height);
	}
	else if (a == 'E')
	{
		vars->boss_x = i;
		vars->boss_y = k;
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_boss, \
		&vars->img_width, &vars->img_height);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i * \
							vars->img_width, k * vars->img_height);
}

void	ft_image_print(char a, t_vars *vars, int i, int k)
{
	mlx_string_put(vars->mlx, vars->win, 10, 30, 0x000FF000, "Step = ");
	if (a == '1')
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_wall, \
										&vars->img_width, &vars->img_height);
	else if (a == '0')
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_ground, \
										&vars->img_width, &vars->img_height);
	else if (a == 'C')
	{
		vars->sum_goals++;
		vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_enemy, \
										&vars->img_width, &vars->img_height);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i * \
							vars->img_width, k * vars->img_height);
}

void	ft_image_position(st_map *lst, t_vars *vars)
{
	int		i;
	int		k;

	i = 0;
	ft_init_image(vars, lst);
	while (vars->var_map[i])
	{
		k = 0;
		while (vars->var_map[i][k])
		{
			ft_image_print(vars->var_map[i][k], vars, k, i);
			ft_image_print1(vars->var_map[i][k], vars, k, i);
			k++;
		}
		i++;
	}
}

void	ft_work_minilib(st_map *lst)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, lst->width * 64, lst->height * 64, \
	"so_long");
	ft_image_position(lst, &vars);
	mlx_hook(vars.win, 2, 0, ft_close, &vars);
	mlx_hook(vars.win, 17, 1L << 2, ft_close_window, &vars);
	mlx_loop(vars.mlx);
}
