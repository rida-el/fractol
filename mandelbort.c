#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	void *mlx;
	void *win;
	double ymin;
	double ymax;
	double xmax;
	double xmin;
	double juliax;
	double juliay;
	int loopx;
	int loopy;
} t_data;

int mandelbrot(double x, double y, t_data *mlx)
{
	int it;
	double cx;
	double cy;
	double temp;

	cx = x;
	cy = y;
	it = 1;
	while (it < 100)
	{
		temp = (x * x - y * y) + cx;
		y = (2 * x * y) + cy;
		x = temp;
		if (x * x + y * y > 4)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy, 0x8F83EB * 2 * it);
			return (0);
		}
		it++;
	}
	mlx_pixel_put(mlx->mlx, mlx->win, mlx->loopx, mlx->loopy, 0xE0E0E);
	return (0);
}

int map_mandelbrot(t_data *mlx)
{
	double x;
	double y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	while (mlx->loopy < 800)
	{
		while (mlx->loopx < 800)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / 800));
			y = mlx->ymin + (mlx->loopy * ((mlx->ymax - mlx->ymin) / 800));
			mandelbrot(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	return (1);
}

int mouse_hook(int keycode, t_data *mlx)
{

	if (keycode == 5)
	{
		printf("Scroll down\n");
		//zoom_in();
	}
	else if (keycode == 4)
		printf("Scroll up\n");
	else
		printf("test\n");

	return (0);
}
int main()
{
	t_data mlx;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "Mandelbrot");
	mlx.xmin = -2;
	mlx.xmax = 2;
	mlx.ymin = -2;
	mlx.ymax = 2;
	map_mandelbrot(&mlx);
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
}
