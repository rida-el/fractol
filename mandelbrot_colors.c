/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:30:47 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/14 08:58:11 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	mandelbrot_color_up(t_data *mlx)
{
	mlx->color += 2;
	map_mandelbrot(mlx, &(mlx->addr2));
	swap_images(mlx);
}

void	mandelbrot_color_down(t_data *mlx)
{
	mlx->color -= 2;
	map_mandelbrot(mlx, &(mlx->addr2));
	swap_images(mlx);
}
