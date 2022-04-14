/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:40:38 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/11 18:51:35 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img1;
	char	*addr1;
	void	*img2;
	char	*addr2;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	ymin;
	double	ymax;
	double	xmax;
	double	xmin;
	double	color;
	double	juliax;
	double	juliay;
	int		loopx;
	int		loopy;
	int		stop;
}	t_data;

int		zoom_mandelbort(int keycode, int x, int y, t_data *mlx);
int		map_mandelbrot(t_data *mlx, char **curr_img);
double	scale_y(int y, t_data *mlx);
double	scale_x(int x, t_data *mlx);
void	swap_images(t_data *mlx);
int		mandelbrot(double x, double y, t_data *mlx);
int		julia(double x, double y, t_data *mlx);
int		map_julia(t_data *mlx, char **curr_img);

int		mouse_mouve(int x, int y, t_data *mlx);

void	julia_color_up(t_data *mlx);
void	julia_color_down(t_data *mlx);

void	mandelbrot_color_up(t_data *mlx);
void	mandelbrot_color_down(t_data *mlx);

void	burning_ship_color_up(t_data *mlx);
void	burning_ship_color_down(t_data *mlx);

int		key_hook_julia(int keycode, t_data *mlx);
void	julia_move_right(t_data *mlx);
void	julia_move_left(t_data *mlx);
void	julia_move_up(t_data *mlx);
void	julia_move_down(t_data *mlx);

int		key_hook_mandelbrot(int keycode, t_data *mlx);
void	mandelbrot_move_down(t_data *mlx);
void	mandelbrot_move_right(t_data *mlx);
void	mandelbrot_move_left(t_data *mlx);
void	mandelbrot_move_up(t_data *mlx);

int		key_hook_burning_ship(int keycode, t_data *mlx);
void	burning_ship_move_down(t_data *mlx);
void	burning_ship_move_right(t_data *mlx);
void	burning_ship_move_left(t_data *mlx);
void	burning_ship_move_up(t_data *mlx);

int		zoom_julia(int keycode, int x, int y, t_data *mlx);
void	zoom_out(int x, int y, t_data *mlx);
void	zoom_in(int x, int y, t_data *mlx);
int		zoom_burning(int keycode, int x, int y, t_data *mlx);
int		burning_ship(double x, double y, t_data *mlx);
int		map_burning_ship(t_data *mlx, char **curr_img);
void	mandelbrot_set(void);
void	julia_set(void);
void	burning_ship_set(void);
int		fun_exit(void *mlx);
#endif
