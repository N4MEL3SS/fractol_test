#include "fractol.h"

int	main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		exit(EXIT_FAILURE);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	mlx.buff = buff_init(&mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &close_program, &mlx);
//	white_background(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, &render, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
