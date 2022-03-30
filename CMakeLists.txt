cmake_minimum_required(VERSION 3.16)
project(fractol C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
include_directories("mlx_mac/")

#set(HEADERS includes/fractol.h includes/image.h includes/error_msg.h
#		includes/macos_keycode.h includes/events.h includes/types.h)

#set(SRC_CORE srcs/core/loop.c srcs/core/init.c srcs/core/utils.c srcs/core/free.c srcs/core/draw.c srcs/core/render.c)
#set(SRC_CONTEXT srcs/context/palette.c srcs/context/viewport.c)
#set(SRC_CONTROL srcs/context/color.c)
#set(SRC_FRACTALS srcs/fractals/mandelbrot.c srcs/fractals/fractal_init.c)
set(SRC_MAIN srcs/main.c includes/fractol.h srcs/close.c srcs/render.c srcs/utils.c srcs/init.c srcs/color.c srcs/mandelbrot.c)
set(SRC_MLX mlx_mac/mlx_init_loop.m srcs/background.c srcs/math.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(fractol ${SRC_MAIN} ${SRC_MLX})
target_link_libraries(fractol ${MLX})
target_link_libraries(fractol m)
target_link_libraries(fractol "-framework OpenGL")
target_link_libraries(fractol "-framework AppKit")
