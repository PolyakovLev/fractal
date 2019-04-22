/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:20:51 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 16:17:25 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "fractal");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp,
						&data->sl, &data->endian);
}

void	put_pxl(t_fractol *data, int x, int y, int color)
{
	if (data->x < 1000 && data->y < 1000)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * 1000 * y + x * 4, &color, sizeof(int));
	}
}
