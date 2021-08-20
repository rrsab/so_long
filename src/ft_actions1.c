#include "../so_long.h"

// Движение вправо
void move_robots(t_vars *vars, char s, int x, int y)
{
    static char *step;

    vars->count++;

    step = ft_itoa(vars->count);
    //vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_wall,
	//								   &vars->img_width, &vars->img_height);
    //mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 1 * 64, 0 * 64);
    mlx_string_put(vars->mlx, vars->win, 64, 10, 0x00000000, step);
    printf("Step: %d\n", vars->count);
    if (s == '0' || s == 'C')
    {
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_player, &vars->img_width, &vars->img_height);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
        vars->var_map[y][x] = 'P';
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_ground, &vars->img_width, &vars->img_height);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->player_x * 64, vars->player_y * 64);
        if (s == 'C')
        {
            vars->sum_goals--;
            if (vars->sum_goals == 0)
            {
                vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_victory, &vars->img_width, &vars->img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->boss_x * 64, vars->boss_y * 64);
            }
        }
        vars->var_map[vars->player_y][vars->player_x] = '0';
        vars->player_x = x;
        vars->player_y = y;
    }
}
//

// Движение
void move(t_vars *vars, int move)
{
    int x;
    int y;

    x = vars->player_x;
    y = vars->player_y;
    if (move == 0)
    {
        x = vars->player_x - 1;
        y = vars->player_y;
        vars->img_player = vars->img_player_left;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    else if (move == 2)
    {
        x = vars->player_x + 1;
        y = vars->player_y;
        vars->img_player = vars->img_player_right;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    else if (move == 1)
    {
        x = vars->player_x;
        y = vars->player_y + 1;
        vars->img_player = vars->img_player_down;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    else if (move == 13)
    {
        x = vars->player_x;
        y = vars->player_y - 1;
        vars->img_player = vars->img_player_up;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    if (vars->sum_goals == 0 && x == vars->boss_x && vars->boss_y == y)
    {
        printf("Win");
        exit(1);
    }
}
//

// Передвижение персонажа
void move_person(t_vars *vars, int keycode)
{
    if (keycode == 0)
        move(vars, 0);
    else if (keycode == 2)
        move(vars, 2);
    else if (keycode == 1)
        move(vars, 1);
    else if (keycode == 13)
        move(vars, 13);
}
//