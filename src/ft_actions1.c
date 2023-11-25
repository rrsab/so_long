
#include "../includes/so_long.h"

void	ft_move_plaver22(t_vars *vars, int x, int y)
{
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_player, \
										&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
										x * 64, y * 64);
	vars->var_map[y][x] = 'P';
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_ground, \
							&vars->img_width, &vars->img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, \
							vars->player_x * 64, vars->player_y * 64);
}

void	ft_move_plaver23(t_vars *vars)
{
	mlx_loop_hook(vars->mlx, ft_animateenemy, vars);
}

void	ft_move_player(t_vars *vars, char s, int x, int y)
{
	if (s == '0' || s == 'C')
	{
		ft_move_plaver22(vars, x, y);
		if (s == 'C')
		{
			vars->sum_goals--;
			if (vars->sum_goals == 0)
				ft_move_plaver23(vars);
		}
		vars->count++;
		ft_print_step(vars);
		vars->var_map[vars->player_y][vars->player_x] = '0';
		vars->player_x = x;
		vars->player_y = y;
	}
}

void	ft_move1(t_vars *vars, int move)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (move == 0)
	{
		x = vars->player_x - 1;
		vars->img_player = vars->img_player_left;
		ft_move_player(vars, vars->var_map[y][x], x, y);
	}
	else if (move == 2)
	{
		x = vars->player_x + 1;
		vars->img_player = vars->img_player_right;
		ft_move_player(vars, vars->var_map[y][x], x, y);
	}
	if (vars->sum_goals == 0 && x == vars->boss_x && vars->boss_y == y)
	{
		printf("Window closed.\n");
		exit(EXIT_SUCCESS);
	}
}

void	ft_move2(t_vars *vars, int move)
{
	int	x;
	int	y;

	x = vars->player_x;
	y = vars->player_y;
	if (move == 1)
	{
		y = vars->player_y + 1;
		vars->img_player = vars->img_player_down;
		ft_move_player(vars, vars->var_map[y][x], x, y);
	}
	else if (move == 13)
	{
		y = vars->player_y - 1;
		vars->img_player = vars->img_player_up;
		ft_move_player(vars, vars->var_map[y][x], x, y);
	}
	if (vars->sum_goals == 0 && x == vars->boss_x && vars->boss_y == y)
	{
		printf("Window closed.\n");
		exit(EXIT_SUCCESS);
	}
}
