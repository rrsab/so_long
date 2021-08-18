#include "../so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
    if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
        move_person(vars, keycode);
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit(0);
    }
    return 0;
}

void image_print(char a, t_vars *vars, int i, int k)
{
    mlx_string_put(vars->mlx, vars->win, 0, 0, 0x00000000, "Step = ");
    if (a == '1')
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_barrier, &vars->img_width, &vars->img_height);
    else if (a == '0')
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_space, &vars->img_width, &vars->img_height);
    else if (a == 'G')
    {
        vars->sum_goals++;
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_enemy, &vars->img_width, &vars->img_height);
    }

    else if (a == 'P')
    {
        vars->person_x = i;
        vars->person_y = k;
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_person_up, &vars->img_width, &vars->img_height);
    }
    else if (a == 'E')
    {
        vars->eva_x = i;
        vars->eva_y = k;
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_eva_dark, &vars->img_width, &vars->img_height);
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i * 64, k * 64);
}

char	*check_image(char *image)
{
    if (open(image, O_RDONLY) < 0)
        error_output("File can not open");
    return (image);
}

void init_image(t_vars *vars,st_map *lst)
{
    vars->count = 0;
    vars->sum_goals = 0;
    vars->var_map = lst->map;
    vars->img_width = 64;
    vars->img_height = 64;
    vars->img_person_up = check_image("./person_up.XPM");
    vars->img_person_right = check_image("./person_right.XPM");
    vars->img_person_left = check_image("./person_left.XPM");
    vars->img_person_down = check_image("./person_down.XPM");
    vars->img_barrier = check_image("./barrier.XPM");
    vars->img_space = check_image("./space.XPM");
    vars->img_enemy = check_image("./enemy.XPM");
    vars->img_eva_dark = check_image("./eva1.XPM");
    vars->img_eva_white = check_image("./eva2.XPM");
}

void image_position(st_map *lst, t_vars *vars)
{
    int		i;
    int		k;

    i = 0;
    init_image(vars, lst);
    while (vars->var_map[i])
    {
        k = 0;
        while(vars->var_map[i][k])
        {
            image_print(vars->var_map[i][k], vars, k, i);
            k++;
        }
        i++;
    }
}

void work_minilib(st_map *lst)
{
    t_vars	vars;
    vars.mlx = mlx_init();
    if (lst->width > 37 || lst->height > 20)
        error_output("Went beyond the map");
    vars.win = mlx_new_window(vars.mlx, lst->width * 64, lst->height * 64, "so_long");
    image_position(lst, &vars);
    mlx_hook(vars.win, 2, 0, ft_close, &vars);
    mlx_loop(vars.mlx);
}