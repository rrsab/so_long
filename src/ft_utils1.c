#include "../so_long.h"

void ft_check_map_name(char *map_name)
{
    char *map_extension;

    if (!(map_extension = ft_strchr(map_name, '.')))
		ft_error("Ne nashel tochki");
    if (ft_strcmp(map_extension, ".ber") != 0)
		ft_error("Ne .ber extension");
}

void ft_check_map(st_map *lst, int len_line, int gnl)
{
    if (len_line == 0)
		ft_error("File is emty");
    if (lst->height != 0 && len_line != lst->width)
		ft_error("It is not rectangle");
    if (gnl == 0 && lst->height == 0)
		ft_error("Only one line");
}

void ft_error(char *error)
{
    printf("Error\n");
	printf("%s", error);
    exit(EXIT_FAILURE);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int ft_close_window(void)
{
	printf("Window closed\n");
	exit(EXIT_SUCCESS);
}