/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:57:42 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 16:17:52 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	double_mandelbrot_init(t_fractol *data)
{
	data->deep = 10;
	data->zoom = 200;
	data->x1 = -2.3;
	data->y1 = -1.5;
	data->color = 0xFF0000;
	data->fract = 3;
	tradess(data);
}

void	double_mandelbrot_formula(t_fractol *data)
{
	data->cr = data->x / data->zoom + data->x1;
	data->ci = data->y / data->zoom + data->y1;
	data->zr = 0;
	data->zi = 0;
	data->it = 0;
	while (data->zr * data->zr + data->zi *
			data->zi < 4 && data->it < data->deep)
	{
		data->tmp = data->zr;
		data->zr = data->zr * data->zr * data->zr -
				(3 * (data->zr * data->zi * data->zi)) + data->cr;
		data->zi = 3 * data->zi * data->tmp * data->tmp
				- data->zi * data->zi * data->zi + data->ci;
		data->it++;
	}
	if (data->it == data->deep)
		put_pxl(data, data->x, data->y, 0x00FF00);
	else
		put_pxl(data, data->x, data->y, (data->color * data->it));
}
