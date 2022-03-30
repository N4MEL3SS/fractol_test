#include "fractol.h"

void	white_background(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_mlx_pixel_put(mlx->buff, x, y, UINT32_MAX >> 2);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->buff->img,
		0, 0);
}
