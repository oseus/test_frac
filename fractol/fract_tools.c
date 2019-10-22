/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract_tools.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 10:05:17 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 10:44:28 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int				idx(int row, int col, int dim)
{
	return (row * dim + col);
}

double			ft_lint(double start, double end, double decimal_percent)
{
	if (start == end)
		return (start);
	return (start * (1.0 - decimal_percent) + (end * decimal_percent));
}

void			img_pixel_put(t_envars *env, double x, double y, int color)
{
	t_image		*img;

	img = &(env->image);
	if (x >= 0 && x < env->w && y >= 0 && y < env->h)
		*(int *)(img->ptr + (int)(idx(y, x, env->w) * img->bpp)) = color;
	//ft_printf("je suis img_pixel_put\n");
}

t_fractal		calc_fract_min_max(t_envars *env, t_fractal f)
{
	double		x_wid;
	double		y_wid;

	x_wid = f.x_wid / env->f.z_factor;
	y_wid = f.y_wid / env->f.z_factor;
	f.x_min = f.x_cent + env->x_t - x_wid * (env->mouse.x_ratio);
	f.x_max = f.x_cent + env->x_t + x_wid * (1 - env->mouse.x_ratio);
	f.y_min = f.y_cent + env->y_t - y_wid * (env->mouse.y_ratio);
	f.y_max = f.y_cent + env->y_t + y_wid * (1 - env->mouse.y_ratio);
	//ft_printf("je suis calc_fract_min_max\n");
	return (f);
}
