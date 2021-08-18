#include "../so_long.h"

void checkFirstAndLastLine(st_map *lst, int i)
{
    int k;

    k = 0;
    while (lst->map[i][k])
    {
        if (lst->map[i][k] != '1')
            error_output("Eto ne stena");
        k++;
    }
}

void check_other_wall(st_map *lst)
{
    int i;
    int k;

    i = 1;
    k = 0;
    while (i != lst->height - 1)
    {
        if (lst->map[i][k] != '1' || lst->map[i][lst->width - 1] != '1')
            error_output("Eto ne stena 2");
        i++;
    }
}

void init_parametrs(st_map *lst)
{
    lst->sum_barrier = 0;
    lst->sum_exit = 0;
    lst->sum_goal = 0;
    lst->sum_player = 0;
}

void allowed_symbols(char c, st_map *lst)
{
    if (c == '1')
        lst->sum_barrier++;
    if (c == 'G')
        lst->sum_goal++;
    if (c == 'P')
    {
        lst->sum_player++;
        if (lst->sum_player > 1)
            error_output("Player more than 1");
    }
    if (c == 'E')
    {
        lst->sum_exit++;
        if (lst->sum_exit > 1)
            error_output("Exit more than 1");
    }
    if (!(c == '1' || c == '0' || c == 'P' || c == 'G' || c == 'E'))
    {
        error_output("Nedopustim symbols");
        exit(1);
    }
}

void check_all_other(st_map *lst, int i, int k)
{
    while(i != lst->height -1)
    {
        while(k != lst->width - 1)
        {
            allowed_symbols(lst->map[i][k], lst);
            k++;
        }
        if (lst->sum_barrier == lst->width - 2 && lst->sum_goal > 0)
            error_output("nekuda idti");
        k = 0;
        i++;
    }
    if (lst->sum_exit == 0 || lst->sum_player == 0 || lst->sum_goal == 0)
        error_output("net P or E or G");
}

void check_map_parametrs(st_map *lst)
{
    init_parametrs(lst);
    checkFirstAndLastLine(lst, 0);
    checkFirstAndLastLine(lst, lst->height - 1);
    check_other_wall(lst);
    check_all_other(lst, 1, 1);
}