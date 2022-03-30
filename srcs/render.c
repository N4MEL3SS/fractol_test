#include "fractol.h"

void	my_mlx_pixel_put(t_buff	*data, int x, int y, int color)
{
	char	*dst;

	dst = data->adrs + (y * data->line_length + x * data->bits_per_pixel);
	*(unsigned int *)dst = color;
}

//int	render(t_mlx *mlx)
//{
//	static int	flag = 1;
//	int			x;
//	int			y;
//	int			x_offset;
//	int			y_offset;
//	int			color;
//
//	x_offset = WIDTH / 2;
//	y_offset = HEIGHT / 2;
//	y = y_offset * -1 - 1;
//	while (flag && ++y < y_offset)
//	{
//		x = x_offset * -1 - 1;
//		while (++x < x_offset)
//		{
//			color = math_mandelbrot(x, y);
//			my_mlx_pixel_put(mlx->buff, x + x_offset, y + y_offset,
//				create_trgb(0, 0, color, color / 2));
//		}
//	}
//	flag = 0;
//	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->buff->img,
//		0, 0);
//	return (1);
//}

int	render(t_mlx *mlx)
{
	static int	flag = 1;
	double		x;
	double		y;
	int			x_offset;
	int			y_offset;
	int			color;

	y = 0;
	while (flag && y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = math_mandelbrot(x, y);
			my_mlx_pixel_put(mlx->buff, (int)x, (int)y,
				create_trgb(0, 0, color, color / 2));
			x += 0.1;
		}
		y += 0.1;
	}
	flag = 0;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->buff->img,
		0, 0);
	return (1);
}
