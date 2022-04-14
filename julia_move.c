/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:29:35 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/14 08:56:11 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	julia_move_right(t_data *mlx)
{
	double	dist;
	double	offset;

	dist = mlx->xmax - mlx->xmin;
	offset = 0.05 * dist;
	mlx->xmin = ((mlx->xmin - offset));
	mlx->xmax = ((mlx->xmax - offset));
	map_julia(mlx, &(mlx->addr2));
	swap_images(mlx);
}

void	julia_move_left(t_data *mlx)
{
	double	dist;
	double	offset;

	dist = mlx->xmax - mlx->xmin;
	offset = 0.05 * dist;
	mlx->xmin += offset;
	mlx->xmax += offset;
	map_julia(mlx, &(mlx->addr2));
	swap_images(mlx);
}

void	julia_move_up(t_data *mlx)
{
	double	dist;
	double	offset;

	dist = mlx->xmax - mlx->xmin;
	offset = 0.05 * dist;
	mlx->ymin += offset;
	mlx->ymax += offset;
	map_julia(mlx, &(mlx->addr2));
	swap_images(mlx);
}

void	julia_move_down(t_data *mlx)
{
	double	dist;
	double	offset;

	dist = mlx->xmax - mlx->xmin;
	offset = 0.05 * dist;
	mlx->ymin -= offset;
	mlx->ymax -= offset;
	map_julia(mlx, &(mlx->addr2));
	swap_images(mlx);
}
