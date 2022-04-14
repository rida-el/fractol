/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:34:05 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/14 08:52:14 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	burning_ship(double x, double y, t_data *mlx)
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
		if (y < 0)
			y *= -(1);
		if (x < 0)
			x *= -(1);
		if (x * x + y * y > 4)
			return (0x000000FF * it * mlx->color);
		it++;
	}
	return (0xE0E0E);
}

int	map_burning_ship(t_data *mlx, char **curr_img)
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
			*(int *)img = burning_ship(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
	}
	return (1);
}

void	burning_ship_set(void)
{
	t_data	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 800, 800, "Burning Ship");
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
	mlx_hook(mlx.win, 3, 0, key_hook_burning_ship, &mlx);
	mlx_mouse_hook(mlx.win, zoom_burning, &mlx);
	map_burning_ship(&mlx, &(mlx.addr1));
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img1, 0, 0);
	mlx_hook(mlx.win, 17, 0, fun_exit, &mlx);
	mlx_loop(mlx.mlx);
}
