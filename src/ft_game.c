#include "../so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
    if (keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1)
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
    mlx_string_put(vars->mlx, vars->win, 10, 10, 0x00000000, "Step = ");
    if (a == '1')
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_wall, &vars->img_width, &vars->img_height);
    else if (a == '0')
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_ground, &vars->img_width, &vars->img_height);
    else if (a == 'C')
    {
        vars->sum_goals++;
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_enemy, &vars->img_width, &vars->img_height);
    }

    else if (a == 'P')
    {
        vars->player_x = i;
        vars->player_y = k;
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_player_up, &vars->img_width, &vars->img_height);
    }
    else if (a == 'E')
    {
        vars->boss_x = i;
        vars->boss_y = k;
        vars->img = mlx_xpm_file_to_image(vars->mlx, vars->img_boss, &vars->img_width, &vars->img_height);
    }
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, i *
    vars->img_width, k * vars->img_height);
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
    vars->img_player_up = check_image("./tiger_up.XPM");
    vars->img_player_right = check_image("./tiger_right.XPM");
    vars->img_player_left = check_image("./tiger_left.XPM");
    vars->img_player_down = check_image("./tiger_down.XPM");
    vars->img_wall = check_image("./wall.XPM");
    vars->img_ground = check_image("./ground.XPM");
    vars->img_enemy = check_image("./enemy.XPM");
    vars->img_boss = check_image("./boss.XPM");
    vars->img_victory = check_image("./victory.XPM");
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
    //if (lst->width > 37 || lst->height > 20)
      //  error_output("Went beyond the map");
    vars.win = mlx_new_window(vars.mlx, lst->width * 64, lst->height * 64,
							  "so_long");
    image_position(lst, &vars);
    mlx_hook(vars.win, 2, 0, ft_close, &vars);
    mlx_loop(vars.mlx);
}