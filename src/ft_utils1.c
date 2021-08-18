#include "../so_long.h"

void check_map_name(char *map_name)
{
    char *map_extension;

    if (!(map_extension = ft_strrchr(map_name, '.')))
        error_output("Ne nashel tochki");
    if (ft_strcmp(map_extension, ".ber") != 0)
        error_output("Ne .ber extension");
}

void check_map(st_map *lst, int len_line, int gnl)
{
    if (len_line == 0)
        error_output("File is emty");
    if (lst->height != 0 && len_line != lst->width)
        error_output("It is not rectangle");
    if (gnl == 0 && lst->height == 0)
        error_output("Onlu one stroka");
}

void error_output(char *error)
{
    printf("%s", error);
    exit(1);
}