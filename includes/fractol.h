#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include "mlx.h"

# define WIDTH 720
# define HEIGHT 720
# define TITLE "fract-ol"

typedef struct s_complex
{
	double	x_re;
	double	y_im;
}				t_complex;

typedef struct s_fractal
{
	void	*img;
	char	*adrs;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_buff;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_buff	*buff;
}				t_mlx;

int		math_mandelbrot3(double x, double y);
int		math_mandelbrot(double x, double y);

t_buff	*buff_init(t_mlx *mlx);

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_buff	*data, int x, int y, int color);

int		render(t_mlx *mlx);
void	white_background(t_mlx *mlx);
int		close_program(t_mlx *mlx);

#endif //FRACTOL_H
