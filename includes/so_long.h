/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salyce <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 15:04:53 by salyce            #+#    #+#             */
/*   Updated: 2021/08/22 15:04:55 by salyce           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <stddef.h>

typedef struct t_pam
{
	char	**map;
	int		width;
	int		height;
	int		sum_player;
	int		sum_wall;
	int		sum_goal;
	int		sum_exit;
}	t_map;

typedef struct s_vars
{
	int		count;
	char	**var_map;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img_player;
	void	*img_player_up;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_player_down;
	void	*img_boss;
	void	*img_victory;
	void	*img_victory1;
	void	*img_enemy;
	void	*img_wall;
	void	*img_ground;
	int		img_width;
	int		img_height;
	int		player_x;
	int		player_y;
	int		boss_x;
	int		boss_y;
	int		sum_goals;
}	t_vars;

int		get_next_line(int fd, char **line);
void	ft_error(char *error, char *name);
int		ft_strcmp(char *s1, char *s2);
void	ft_check_map_name(char *map_name);
void	ft_check_map_empty(t_map *lst, char *map);
void	ft_check_map(t_map *lst, int len_line, int gnl);
void	ft_check_map_parametrs(t_map *lst);
void	ft_work_minilib(t_map *lst);
void	ft_play(t_vars *vars, int keycode);
int		ft_close_window(void);
int		ft_close(int keycode, t_vars *vars);
void	ft_init_image(t_vars *vars, t_map *lst);
void	ft_move1(t_vars *vars, int move);
void	ft_move2(t_vars *vars, int move);
void	ft_print_step(t_vars *vars);

#endif
