/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:46:34 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/11 22:48:05 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_mouve(int x, int y, t_data *mlx)
{
	double	mouse_x;
	double	mouse_y;

	if (x <= 800 && y <= 800 && mlx->stop == 0)
	{
		mouse_x = scale_x(x, mlx);
		mouse_y = scale_y(y, mlx);
		mlx->juliax = mouse_x;
		mlx->juliay = mouse_y;
		map_julia(mlx, &(mlx->addr2));
		swap_images(mlx);
	}
	return (0);
}

int	key_hook_julia(int keycode, t_data *mlx)
{
	if (keycode == 53)
		fun_exit(mlx);
	if (keycode == 1)
		mlx->stop = 1;
	if (keycode == 2)
		mlx->stop = 0;
	if (keycode == 37)
		julia_color_up(mlx);
	if (keycode == 38)
		julia_color_down(mlx);
	if (keycode == 124)
		julia_move_right(mlx);
	if (keycode == 123)
		julia_move_left(mlx);
	if (keycode == 126)
		julia_move_up(mlx);
	if (keycode == 125)
		julia_move_down(mlx);
	return (0);
}

int	key_hook_mandelbrot(int keycode, t_data *mlx)
{
	if (keycode == 53)
		fun_exit(mlx);
	if (keycode == 1)
		mlx->stop = 1;
	if (keycode == 2)
		mlx->stop = 0;
	if (keycode == 37)
		mandelbrot_color_up(mlx);
	if (keycode == 38)
		mandelbrot_color_down(mlx);
	if (keycode == 124)
		mandelbrot_move_right(mlx);
	if (keycode == 123)
		mandelbrot_move_left(mlx);
	if (keycode == 126)
		mandelbrot_move_up(mlx);
	if (keycode == 125)
		mandelbrot_move_down(mlx);
	return (0);
}

int	key_hook_burning_ship(int keycode, t_data *mlx)
{
	if (keycode == 53)
		fun_exit(mlx);
	if (keycode == 1)
		mlx->stop = 1;
	if (keycode == 2)
		mlx->stop = 0;
	if (keycode == 37)
		burning_ship_color_up(mlx);
	if (keycode == 38)
		burning_ship_color_down(mlx);
	if (keycode == 124)
		burning_ship_move_right(mlx);
	if (keycode == 123)
		burning_ship_move_left(mlx);
	if (keycode == 126)
		burning_ship_move_up(mlx);
	if (keycode == 125)
		burning_ship_move_down(mlx);
	return (0);
}
