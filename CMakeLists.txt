cmake_minimum_required(VERSION 3.19)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long src/so_long.c so_long.h src/ft_utils1.c src/ft_actions1.c src/ft_game.c src/ft_checkmap.c)