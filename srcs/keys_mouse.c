/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:20:43 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 16:41:17 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_close(void)
{
	exit(0);
	return (1);
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom_in(x, y, data);
	if (mousecode == 5 || mousecode == 2)
		ft_zoom_out(x, y, data);
	tradess(data);
	return (0);
}

void	ft_move(int keycode, t_fractol *data)
{
	if (keycode == 124)
		data->x1 -= 0.01;
	if (keycode == 123)
		data->x1 += 0.01;
	if (keycode == 125)
		data->y1 -= 0.01;
	if (keycode == 126)
		data->y1 += 0.01;
}

int		keyboard(int keycode, t_fractol *data)
{
	if (keycode == 2)
		ft_plus_deep(data);
	if (keycode == 53 || keycode == 17)
		exit(0);
	if (keycode == 19)
		data->color = 167216;
	if (keycode == 18)
		data->color = 255;
	if (keycode == 20)
		data->color = 46462;
	if (keycode == 15)
	{
		data->zoom = 300;
		data->x1 = -2.3;
		data->y1 = -1.5;
	}
	ft_move(keycode, data);
	tradess(data);
	return (0);
}

int		mouse_julia(int x, int y, t_fractol *data)
{
	if (data->fract == 1)
	{
		data->cr = x * 2;
		data->ci = y * 2 - 800;
		tradess(data);
	}
	return (0);
}
