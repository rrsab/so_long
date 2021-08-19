#include "../so_long.h"

// Движение вправо
void move_robots(t_vars *vars, char s, int x, int y)
{
    static char *step;

    vars->count++;

    step = ft_itoa(vars->count);
    vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_barrier, &vars->img_width, &vars->img_height);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 1 * 64, 0 * 64);
    mlx_string_put(vars->mlx, vars->win, 64, 10, 0x00000000, step);
    printf("Step: %d\n", vars->count);
    if (s == '0' || s == 'G')
    {
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_person, &vars->img_width, &vars->img_height);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x * 64, y * 64);
        vars->var_map[y][x] = 'P';
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_space, &vars->img_width, &vars->img_height);
        mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->person_x * 64, vars->person_y * 64);
        if (s == 'G')
        {
            vars->sum_goals--;
            if (vars->sum_goals == 0)
            {
                vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_eva_white, &vars->img_width, &vars->img_height);
                mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->eva_x * 64, vars->eva_y * 64);
            }
        }
        vars->var_map[vars->person_y][vars->person_x] = '0';
        vars->person_x = x;
        vars->person_y = y;
    }
}
//

// Движение
void move(t_vars *vars, int move)
{
    int x;
    int y;

    x = vars->person_x;
    y = vars->person_y;
    if (move == 123)
    {
        x = vars->person_x - 1;
        y = vars->person_y;
        vars->img_person = vars->img_person_left;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    else if (move == 124)
    {
        x = vars->person_x + 1;
        y = vars->person_y;
        vars->img_person = vars->img_person_right;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    else if (move == 125)
    {
        x = vars->person_x;
        y = vars->person_y + 1;
        vars->img_person = vars->img_person_down;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    else if (move == 126)
    {
        x = vars->person_x;
        y = vars->person_y - 1;
        vars->img_person = vars->img_person_up;
        move_robots(vars, vars->var_map[y][x], x, y);
    }
    if (vars->sum_goals == 0 && x == vars->eva_x && vars->eva_y == y)
    {
        printf("Win");
        exit(1);
    }
}
//

// Передвижение персонажа
void move_person(t_vars *vars, int keycode)
{
    if (keycode == 123)
        move(vars, 123);
    else if (keycode == 124)
        move(vars, 124);
    else if (keycode == 125)
        move(vars, 125);
    else if (keycode == 126)
        move(vars, 126);
}
//