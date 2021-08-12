ifeq ($(MAKECMDGOALS),bonus)
	NAME = so_long_bonus
else
	NAME = so_long
endif
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g
CC			= gcc

ifeq ($(MAKECMDGOALS),bonus)
	OBJS = $(SRCS_BONUS:%.c=%.o)
else
	OBJS = $(SRCS:%.c=%.o)
endif

LIBFT_OBJS	= $(LIBFT:%.c=%.o)
SRCS 		= src/so_long.c \
			src/ft_utils1.c \
			gnl/get_next_line.c

SRCS_BONUS	=
INCLUDE		= so_long.h \

LIBFT_A		= libft/libft.a
MINI_LIBX	= mlx/libmlx.a
FRAMEWORK	= -Lmlx -lmlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re bonus libft norm mlx

.o:.c 		$(INCLUDE)
			$(CC) $(CFLAGS) $< -o $@

all:		libft mlx $(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(CC) $(OBJS) $(LIBFT_A) $(MINI_LIBX) $(FRAMEWORK) -o $(NAME)

bonus:		libft $(NAME)

norm:
			norminette $(SRCS)
			norminette $(SRCS_BONUS)
			norminette $(INCLUDE)
			make -C libft/ norm

libft:
			make -C libft

mlx:
			make -C mlx

clean:
			rm -f src/*.o
			rm -f gnl/*.o
			make -C libft clean
			make -C mlx clean

fclean:		clean
			rm -f $(NAME)
			rm -f so_long
			rm -f so_long_bonus
			rm -rf a.out*
			rm -rf */a.out*
			rm -rf *.gch
			rm -rf */*.gch
			rm -f libft/libft.a

re:			fclean all