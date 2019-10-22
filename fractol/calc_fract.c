/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   calc_fract.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:35:25 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 10:49:35 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void				julia(void *environ, int pix_ind)
{
	t_fractal		f;
	t_envars		*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	f = calc_fract_min_max(env, f);
	env->f = f;
	f.c.r = ft_lint(-f.x_wid / 2, f.x_wid / 2, env->mouse.x / env->w);
	f.c.i = ft_lint(-f.y_wid / 2, f.y_wid / 2, env->mouse.y / env->h);
	f.z.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
	f.z.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
	env->iter_buf[pix_ind] = escape_time(env, f);
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}

void				mandelbrot(void *environ, int pix_ind)
{
	t_fractal		f;
	t_envars		*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	f = calc_fract_min_max(env, f);
	env->f = f;
	f.c.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
	f.c.i = ft_lint(f.y_min	, f.y_max, (float)f.y / env->h);
	f.z.r = 0;
	f.z.i = 0;
	env->iter_buf[pix_ind] = escape_time(env, f);
	//ft_printf("%d\n",pix_ind);
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}

void				burning_ship(void *environ, int pix_ind)
{
	t_fractal		f;
	t_envars		*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	f = calc_fract_min_max(env, f);
	env->f = f;
	f.c.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
	f.c.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
	f.z.r = 0;
	f.z.i = 0;
	env->iter_buf[pix_ind] = escape_time(env, f);
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}

void				koch(void *environ, int pix_ind)
{
	t_fractal		f;
	t_envars		*env;

	env = (t_envars *)environ;
	f = env->f;
	f.x = pix_ind % env->w;
	f.y = pix_ind / env->w;
	f = calc_fract_min_max(env, f);
	env->f = f;
	f.c.r = ft_lint(-f.x_wid / 3, f.x_wid / 3, env->mouse.x / env->w);
	f.c.i = ft_lint(-f.y_wid / 2, f.y_wid / 2, env->mouse.y / env->h);
	f.z.r = ft_lint(f.x_min, f.x_max, (float)f.x / env->w);
	f.z.i = ft_lint(f.y_min, f.y_max, (float)f.y / env->h);
	env->iter_buf[pix_ind] = escape_time(env, f);
	img_pixel_put(env, f.x, f.y, choose_col(env, env->iter_buf[pix_ind]));
}
