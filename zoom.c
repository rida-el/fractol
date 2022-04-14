/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 02:14:21 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/10 02:56:53 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int x, int y, t_data *mlx)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = scale_x(x, mlx);
	mouse_y = scale_y(y, mlx);
	mlx->xmin = ((mlx->xmin - mouse_x) * 1.2) + mouse_x;
	mlx->xmax = ((mlx->xmax - mouse_x) * 1.2) + mouse_x;
	mlx->ymin = ((mlx->ymin - mouse_y) * 1.2) + mouse_y;
	mlx->ymax = ((mlx->ymax - mouse_y) * 1.2) + mouse_y;
}

void	zoom_out(int x, int y, t_data *mlx)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = scale_x(x, mlx);
	mouse_y = scale_y(y, mlx);
	mlx->xmin = ((mlx->xmin - mouse_x) / 1.2) + mouse_x;
	mlx->xmax = ((mlx->xmax - mouse_x) / 1.2) + mouse_x;
	mlx->ymin = ((mlx->ymin - mouse_y) / 1.2) + mouse_y;
	mlx->ymax = ((mlx->ymax - mouse_y) / 1.2) + mouse_y;
}

int	zoom_julia(int keycode, int x, int y, t_data *mlx)
{
	if (mlx->stop == 1)
	{
		if (keycode == 5)
		{
			zoom_in(x, y, mlx);
			map_julia(mlx, &(mlx->addr2));
			swap_images(mlx);
		}
		else if (keycode == 4)
		{
			zoom_out(x, y, mlx);
			map_julia(mlx, &(mlx->addr2));
			swap_images(mlx);
		}
	}
	return (0);
}

int	zoom_mandelbort(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == 5)
	{
		zoom_in(x, y, mlx);
		map_mandelbrot(mlx, &(mlx->addr2));
		swap_images(mlx);
	}
	else if (keycode == 4)
	{
		zoom_out(x, y, mlx);
		map_mandelbrot(mlx, &(mlx->addr2));
		swap_images(mlx);
	}
	return (0);
}

int	zoom_burning(int keycode, int x, int y, t_data *mlx)
{
	if (keycode == 5)
	{
		zoom_in(x, y, mlx);
		map_burning_ship(mlx, &(mlx->addr2));
		swap_images(mlx);
	}
	else if (keycode == 4)
	{
		zoom_out(x, y, mlx);
		map_burning_ship(mlx, &(mlx->addr2));
		swap_images(mlx);
	}
	return (0);
}
