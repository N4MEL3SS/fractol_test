#include "fractol.h"
#define MANDEL_R 64

double	map(double n, int start, int range, int in, int out)
{
	double	res;

	res = (double)(out - in) / (double)(range - start);
	return (n * res);
}

int	math_mandelbrot(double x, double y)
{
	double	a;
	double	aa;
	double	b;
	double	bb;
	double	ca;
	double	cb;
	int		i;

	i = -1;
	a = map(x, 0, WIDTH, 0, 4) - 2;
	b = map(y, 0, HEIGHT, 0, 4) - 2;
	ca = a;
	cb = b;
	while (++i < 10 && (a * a + b * b < MANDEL_R))
	{
		aa = a * a - b * b;
		a = aa + ca;
		bb = 2 * a * b;
		b = bb + cb;
	}
	if (i == 10)
		return (0);
	i = (int)map(i, 0, 100, 0, 255);
	return (i);
}

int	math_mandelbrot2(int x, int y)
{
	double	p;
	double	deg;
	double	pc;

	p = ((x - 0.25) * (x - 0.25)) + (y * y);
	deg = atan2(x, y) - 0.25;
	pc = 0.25 - 0.25 * cos(deg);
	if (p <= pc)
		return (1);
	return (2);
}

int	math_circle(int x, int y)
{
	int	res;

	res = x * x + y * y;
	if (res >= 32400 && res < 40000)
		return (2);
	else if (res < 32400)
		return (1);
	return (0);
}
