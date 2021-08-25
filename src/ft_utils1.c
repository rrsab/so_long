/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:02:10 by salyce            #+#    #+#             */
/*   Updated: 2021/08/22 15:02:12 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_map_name(char *map_name)
{
	char	*map_extension;

	map_extension = ft_strchr(map_name, '.');
	if (!map_extension)
		ft_error("No dot in the name.", map_name);
	if (ft_strcmp(map_extension, ".ber") != 0)
		ft_error("The file extension is not .ber", map_name);
}

void	ft_check_map(t_map *lst, int len_line, int gnl)
{
	if (len_line == 0)
		ft_error("File is emty", "");
	if (lst->height != 0 && len_line != lst->width)
		ft_error("It is not rectangle", "");
	if (gnl == 0 && lst->height == 0)
		ft_error("Only one line", "");
}

void	ft_error(char *error, char *name)
{
	printf("Error\n");
	printf("%s %s\n", error, name);
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

int	ft_close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("Window closed\n");
	exit(EXIT_SUCCESS);
}
