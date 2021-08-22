#include "../so_long.h"

void	ft_check_map_empty(t_map *lst, char *map)
{
	int		fd;
	int		gnl;
	char	*line;
	int		len_line;

	line = NULL;
	lst->height = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0 || (read(fd, 0, 0) < 0))
		ft_error("Not can read", map);
	while (1)
	{
		gnl = get_next_line(fd, &line);
		len_line = ft_strlen(line);
		ft_check_map(lst, len_line, gnl);
		lst->width = len_line;
		lst->height++;
		free(line);
		if (gnl == 0)
			break ;
	}
	close(fd);
}

void	ft_fill_map(t_map *lst, char *map)
{
	int		fd;
	int		s;
	int		gnl;
	char	*line;

	line = NULL;
	s = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd, &line);
		lst->map[s] = ft_strdup(line);
		s++;
		free(line);
		if (gnl == 0)
			break ;
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	t_map	lst;

	if (argc != 2)
		ft_error("Argc != 2", "");
	ft_check_map_name(argv[1]);
	ft_check_map_empty(&lst, argv[1]);
	lst.map = ft_calloc(lst.height + 1, sizeof(char *));
	ft_fill_map(&lst, argv[1]);
	ft_check_map_parametrs(&lst);
	ft_work_minilib(&lst);
	return (1);
}
