/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:48:13 by rel-maza          #+#    #+#             */
/*   Updated: 2022/04/11 22:49:47 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*st1;
	unsigned char	*st2;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while ((st1[i] || st2[i]))
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Usage : ./fractol fractal_name\n", 31);
		write(1, "\t- Julia\n\t- Mandelbrot\n", 23);
		write(1, "Bonus :\n", 8);
		write(1, "\t- Burning_ship\n", 16);
	}
	else
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			mandelbrot_set();
		else if (!ft_strcmp(argv[1], "Julia"))
			julia_set();
		else if (!ft_strcmp(argv[1], "Burning_ship"))
			burning_ship_set();
		else
		{
			write(1, "Usage : ./fractol fractal_name\n", 31);
			write(1, "\t- Julia\n\t- Mandelbrot\n", 23);
			write(1, "Bonus :\n", 8);
			write(1, "\t- Burning_ship\n", 16);
		}
	}
}
