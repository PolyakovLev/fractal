/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:22:26 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 16:40:46 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	get_fractal_type(char *argv, t_fractol *data)
{
	if (!ft_strcmp(argv, "mandelbrot"))
		mandelbrot_init(data);
	else if (!ft_strcmp(argv, "julia"))
		julia_init(data);
	else if (!ft_strcmp(argv, "bonus1"))
		double_mandelbrot_init(data);
	else if (!ft_strcmp(argv, "bonus2"))
		dig_init(data);
	else if (!ft_strcmp(argv, "bonus3"))
		boat_init(data);
	else
	{
		ft_putstr("можно использовать только ");
		ft_putstr("mandelbrot, julia, bonus1, bonus2, bonus3 ");
		ft_putstr("в качестве аргумента\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_fractol *data;

	if (argc == 2)
	{
		data = (t_fractol *)malloc(sizeof(t_fractol));
		win_init(data);
		get_fractal_type(argv[1], data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_hook(data->win, 17, 0L, ft_close, data);
		mlx_key_hook(data->win, keyboard, data);
		mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
		mlx_loop(data->mlx);
	}
	else
	{
		ft_putstr("можно использовать только ");
		ft_putstr("mandelbrot, julia, bonus1, bonus2, bonus3 ");
		ft_putstr("в качестве аргумента\n");
	}
	return (0);
}
