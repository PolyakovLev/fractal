/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:20:30 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 15:22:09 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	formula_use(t_fractol *data)
{
	if (data->fract == 2)
		mandelbrot_formula(data);
	if (data->fract == 1)
		julia_formula(data);
	if (data->fract == 3)
		double_mandelbrot_formula(data);
	if (data->fract == 4)
		dig_formula(data);
	if (data->fract == 5)
		boat_formula(data);
}

void	*calculate(void *tab)
{
	t_fractol	*data;
	int			tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < 1000)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			formula_use(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}
