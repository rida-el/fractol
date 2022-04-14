/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:38:44 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/14 08:52:53 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	burning_ship_color_up(t_data *mlx)
{
	mlx->color += 2;
	map_burning_ship(mlx, &(mlx->addr2));
	swap_images(mlx);
}

void	burning_ship_color_down(t_data *mlx)
{
	mlx->color -= 2;
	map_burning_ship(mlx, &(mlx->addr2));
	swap_images(mlx);
}
