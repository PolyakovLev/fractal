/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:20:39 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 16:17:52 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	julia_init(t_fractol *data)
{
	data->deep = 10;
	data->zoom = 200;
	data->x1 = -2.5;
	data->y1 = -2.5;
	data->cr = 1;
	data->ci = 1.1;
	data->color = 265;
	data->fract = 1;
	tradess(data);
}

void	julia_formula(t_fractol *data)
{
	data->zr = data->x / data->zoom + data->x1;
	data->zi = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->zi * data->zi + data->zr *
			data->zr < 4 && data->it < data->deep)
	{
		data->tmp = data->zr;
		data->zr = data->zr * data->zr - data->zi *
					data->zi - 1 + (data->cr / 1000);
		data->zi = 2 * data->zi * data->tmp + data->ci / 1000;
		data->it++;
	}
	if (data->it == data->deep)
		put_pxl(data, data->x, data->y, 0x00FF00);
	else
		put_pxl(data, data->x, data->y, (data->color * data->it));
}
