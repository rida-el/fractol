/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:27:55 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/14 08:55:05 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	julia_color_up(t_data *mlx)
{
	mlx->color += 2;
	map_julia(mlx, &(mlx->addr2));
	swap_images(mlx);
}

void	julia_color_down(t_data *mlx)
{
	mlx->color -= 2;
	map_julia(mlx, &(mlx->addr2));
	swap_images(mlx);
}
