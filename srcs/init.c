#include "fractol.h"

t_buff	*buff_init(t_mlx *mlx)
{
	t_buff	*buff;

	buff = malloc(sizeof(t_buff));
	buff->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	buff->adrs = mlx_get_data_addr(buff->img, &buff->bits_per_pixel,
			&buff->line_length, &buff->endian);
	buff->bits_per_pixel /= 8;
	return (buff);
}
