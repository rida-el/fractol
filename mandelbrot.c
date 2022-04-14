/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:06:38 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/14 08:57:42 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	mandelbrot(double x, double y, t_data *mlx)
{
	int		it;
	double	cx;
	double	cy;
	double	temp;

	cx = x;
	cy = y;
	it = 1;
	while (it < 100)
	{
		temp = (x * x - y * y) + cx;
		y = (2 * x * y) + cy;
		x = temp;
		if (x * x + y * y > 4)
			return (0x8F83EB * mlx->color * it);
		it++;
	}
	return (0xE0E0E);
}

int	map_mandelbrot(t_data *mlx, char **curr_img)
{
	double	x;
	double	y;
	char	*img;

	mlx->loopx = 0;
	mlx->loopy = 0;
	img = *curr_img;
	while (mlx->loopy < 800)
	{
		mlx->loopx = 0;
		while (mlx->loopx < 800)
		{
			y = mlx->ymin + (mlx->loopy * ((mlx->ymax - mlx->ymin) / 800));
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / 800));
			img = *curr_img + (mlx->loopy * mlx->line_length
					+ mlx->loopx * (mlx->bits_per_pixel / 8));
			*(int *)img = mandelbrot(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
	}
	return (1);
}

void	mandelbrot_set(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "Mandelbrot");
	mlx.xmin = -2.0;
	mlx.xmax = 2.0;
	mlx.ymin = -2.0;
	mlx.ymax = 2.0;
	mlx.color = 2;
	mlx.img1 = mlx_new_image(mlx.mlx, 800, 800);
	mlx.addr1 = mlx_get_data_addr(mlx.img1,
			&mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	mlx.img2 = mlx_new_image(mlx.mlx, 800, 800);
	mlx.addr2 = mlx_get_data_addr(mlx.img2,
			&mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	mlx_mouse_hook(mlx.win, zoom_mandelbort, &mlx);
	mlx_hook(mlx.win, 3, 0, key_hook_mandelbrot, &mlx);
	map_mandelbrot(&mlx, &(mlx.addr1));
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img1, 0, 0);
	mlx_hook(mlx.win, 17, 0, fun_exit, &mlx);
	mlx_loop(mlx.mlx);
}
