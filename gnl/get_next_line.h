#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
#endif
