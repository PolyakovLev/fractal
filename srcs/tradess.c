/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tradess.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:20:48 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/22 21:21:13 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	tradess(t_fractol *data)
{
	t_fractol	tab[200];
	pthread_t	t[200];
	int			i;

	i = 0;
	while (i < 200)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_fractol));
		tab[i].y = 5 * i;
		tab[i].y_max = 5 * (i + 1);
		if (data->fract == 2)
			pthread_create(&t[i], NULL, calculate, &tab[i]);
		else
			pthread_create(&t[i], NULL, calculate, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
