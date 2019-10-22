/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract_color.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:03:10 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 13:43:00 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			setup_color(t_envars *env)
{
	env->color_style = 0;
	env	->c.cent = 127;
	env->c.wid = 128;
	env->c.r_freq = 0.33;
	env->c.g_freq = 0.33;
	env->c.b_freq = 0.33;
	env->c.r_phase = (2 * M_PI) / 3;
	env->c.g_phase = (2 * M_PI) / 3;
	env->c.b_phase = 0.0;
}

void			cool_color(t_envars *env)
{
	env->color_style = (env->color_style + 1) % 4;
	if (env->color_style == 0)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.33;
	}
	if (env->color_style == 1)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.00;
	}
	if (env->color_style == 2)
	{
		env->c.r_freq = 0.33;
		env->c.g_freq = 0.00;
		env->c.b_freq = 0.33;
	}
	if (env->color_style == 3)
	{
		env->c.r_freq = 0.00;
		env->c.g_freq = 0.33;
		env->c.b_freq = 0.33;
	}
}

int				choose_col(t_envars *env, float iter)
{
	int			r;
	int			g;
	int			b;
	t_collor	c;

	c = env->c;
	if (iter >= env->iter_lim)
		return (0);
	else
	{
		r = sin(fmod(c.r_freq * iter + c.r_phase, 2 * M_PI)) * c.wid + c.cent;
		g = sin(fmod(c.g_freq * iter + c.g_phase, 2 * M_PI)) * c.wid + c.cent;
		b = sin(fmod(c.b_freq * iter + c.b_phase, 2 * M_PI)) * c.wid + c.cent;
		return (r << 16 | g << 8 | b);
	}
}
