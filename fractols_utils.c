/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:42:14 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/11 22:44:28 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale_x(int x, t_data *mlx)
{
	double	x_scale;

	x_scale = ((x * (mlx->xmax - mlx->xmin)) / 800) + mlx->xmin;
	return (x_scale);
}

double	scale_y(int y, t_data *mlx)
{
	double	y_scale;

	y_scale = ((y * (mlx->ymax - mlx->ymin)) / 800) + mlx->ymin;
	return (y_scale);
}

void	swap_images(t_data *mlx)
{
	void	*tmp_img;
	char	*tmp_addr;

	tmp_img = mlx->img2;
	tmp_addr = mlx->addr2;
	mlx->addr2 = mlx->addr1;
	mlx->addr1 = tmp_addr;
	mlx->img2 = mlx->img1;
	mlx->img1 = tmp_img;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img1, 0, 0);
}
