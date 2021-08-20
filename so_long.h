#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <mlx.h>
#include <stddef.h>

typedef struct st_pam
{
	char	**map;
	int		width;
	int		height;
	int		sum_player;
	int		sum_wall;
	int		sum_goal;
	int		sum_exit;
}	st_map;

typedef struct	s_vars {
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
}				t_vars;


int		get_next_line(int fd, char **line);

void	error_output(char *error);
int		ft_strcmp(char *s1, char *s2);

void	check_map_name(char *map_name);
void	check_map_empty(st_map *lst, char *map);
void	check_map(st_map *lst, int len_line, int gnl);
void	check_map_parametrs(st_map *lst);
void	work_minilib(st_map *lst);
void	move_person(t_vars *vars, int keycode);

#endif