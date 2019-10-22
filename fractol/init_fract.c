/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_fract.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:17:45 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 13:27:14 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 1;
	env->f.x_cent = 0.0;
	env->f.y_cent = -0.25;
	env->f.x_wid = 1.25;
	env->f.y_wid = 1.25;
}


void			init_mandelbrot(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = -1;
	env->f.y_cent = -1.25;
	env->f.x_wid = 1.5;
	env->f.y_wid = 2.5;
}

void			init_burning_ship(void *environ)
{
	t_envars	*env;
	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 1;
	env->f.interactive = 0;
	env->f.x_cent = -2;
	env->f.y_cent = -1;
	env->f.x_wid = 0.75;
	env->f.y_wid = 2;//position fenetre axe y
}

void			init_koch(void *environ)
{
	t_envars	*env;

	env = (t_envars *)environ;
	env->f.z_factor = 1;
	env->f.d = 2;
	env->f.abs = 0;
	env->f.interactive = 0;
	env->f.x_cent = -1.25;
	env->f.y_cent = -1;
	env->f.x_wid = 1.25;
	env->f.y_wid = 1.25;
}
