/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:01:35 by salyce            #+#    #+#             */
/*   Updated: 2021/08/22 15:01:37 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_checkFirstAndLastLine(t_map *lst, int i)
{
	int	k;

	k = 0;
	while (lst->map[i][k])
	{
		if (lst->map[i][k] != '1')
			ft_error("The map must be closed/surrounded by walls.", "");
		k++;
	}
}

void	ft_check_other_wall(t_map *lst)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i != lst->height - 1)
	{
		if (lst->map[i][k] != '1' || lst->map[i][lst->width - 1] != '1')
			ft_error("The map must be closed/surrounded by walls.", "");
		i++;
	}
}

void	ft_allowed_symbols(char c, t_map *lst)
{
	if (c == '1')
		lst->sum_wall++;
	if (c == 'C')
		lst->sum_goal++;
	if (c == 'P')
	{
		lst->sum_player++;
		if (lst->sum_player > 1)
			ft_error("Too many starting positions.", "");
	}
	if (c == 'E')
	{
		lst->sum_exit++;
		if (lst->sum_exit > 1)
			ft_error("Exit more than 1", "");
	}
	if (!(c == '1' || c == '0' || c == 'P' || c == 'C' || c == 'E'))
	{
		ft_error("The map must be composed of only 5 possible characters:\n"
			" 0 for an empty space, 1 for a wall, C for a collectible, E for\n"
			"map exit and P for the player’s starting position.\n", "");
		exit(1);
	}
}

void	ft_check_all_other(t_map *lst, int i, int k)
{
	while (i != lst->height - 1)
	{
		while (k != lst->width - 1)
		{
			ft_allowed_symbols(lst->map[i][k], lst);
			k++;
		}
		k = 0;
		i++;
	}
	if (lst->sum_player == 0)
		ft_error("Map must have at least one starting position.", "");
	else if (lst->sum_exit == 0)
		ft_error("Map must have at least one exit.", "");
	else if (lst->sum_goal == 0)
		ft_error("Map must have at least one collectible.", "");
}

void	ft_check_map_parametrs(t_map *lst)
{
	lst->sum_wall = 0;
	lst->sum_exit = 0;
	lst->sum_goal = 0;
	lst->sum_player = 0;
	ft_checkFirstAndLastLine(lst, 0);
	ft_checkFirstAndLastLine(lst, lst->height - 1);
	ft_check_other_wall(lst);
	ft_check_all_other(lst, 1, 1);
}
