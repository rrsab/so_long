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
    lst->sum_wall = 0;
    lst->sum_exit = 0;
    lst->sum_goal = 0;
    lst->sum_player = 0;
}

void allowed_symbols(char c, st_map *lst)
{
    if (c == '1')
        lst->sum_wall++;
    if (c == 'C')
        lst->sum_goal++;
    if (c == 'P')
    {
        lst->sum_player++;
      //  if (lst->sum_player == 0)
        //    error_output("Map must have at least one starting position.");
    }
    if (c == 'E')
    {
        lst->sum_exit++;
     //   if (lst->sum_exit > 1)
     //       error_output("Exit more than 1");
    }
    if (!(c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E'))
    {
        error_output("The map must be composed of only 5 possible characters: 0 for an empty\n"
					 "space, 1 for a wall, C for a collectible, E for map exit and P for the player’s\n"
					 "starting position.");
        exit(1);
    }
}

void check_all_other(st_map *lst, int i, int k)
{
    while(i != lst->height - 1)
    {
        while(k != lst->width - 1)
        {
            allowed_symbols(lst->map[i][k], lst);
            k++;
        }
        //if (lst->sum_wall == lst->width - 2 && lst->sum_goal > 0)
          //  error_output("nekuda idti");
        k = 0;
        i++;
    }
//    if (lst->sum_exit == 0 || lst->sum_player == 0 || lst->sum_goal == 0)
	if (lst->sum_player == 0)
			error_output("Map must have at least one starting position.");
	else if (lst->sum_exit == 0)
		error_output("Map must have at least one exit.");
	else if (lst->sum_goal == 0)
		error_output("Map must have at least one collectible.");
    //    error_output("net P or E or C");
}

void check_map_parametrs(st_map *lst)
{
    init_parametrs(lst);
    checkFirstAndLastLine(lst, 0);
    checkFirstAndLastLine(lst, lst->height - 1);
    check_other_wall(lst);
    check_all_other(lst, 1, 1);
}