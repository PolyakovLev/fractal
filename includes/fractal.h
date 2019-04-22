/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daharwoo <daharwoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:25:37 by daharwoo          #+#    #+#             */
/*   Updated: 2019/01/23 16:42:16 by daharwoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <pthread/pthread.h>

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				endian;
	int				sl;
	int				bpp;
	int				color;
	int				julia_mouse;
	int				x;
	int				y;
	int				y_max;
	int				it;
	int				deep;
	int				fract;
	long double		zoom;
	long double		x1;
	long double		y1;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		tmp;
}					t_fractol;

int					mouse_hook(int mousecode, int x, int y, t_fractol *data);
int					keyboard(int keycode, t_fractol *data);
int					mouse_julia(int x, int y, t_fractol *data);
int					ft_close(void);
void				ft_zoom_in(int x, int y, t_fractol *data);
void				ft_zoom_out(int x, int y, t_fractol *data);
void				ft_plus_deep(t_fractol *data);
void				tradess(t_fractol *data);
void				*calculate(void *tab);
void				mandelbrot_init(t_fractol *data);
void				mandelbrot_formula(t_fractol *data);
void				julia_init(t_fractol *data);
void				julia_formula(t_fractol *data);
void				double_mandelbrot_formula(t_fractol *data);
void				double_mandelbrot_init(t_fractol *data);
void				dig_formula(t_fractol *data);
void				dig_init(t_fractol *data);
void				boat_formula(t_fractol *data);
void				boat_init(t_fractol *data);
void				win_init(t_fractol *data);
void				put_pxl(t_fractol *data, int x, int y, int color);
#endif
