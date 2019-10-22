/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_management.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 10:51:00 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 13:42:32 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void		cleanup_env(t_envars *env)
{
	free(env->iter_buf);
	mlx_destroy_image(env->mlx, (&env->image)->image);
	mlx_destroy_window(env->mlx, env->win);
}

void			reset_env(t_envars *env)
{
	cleanup_env(env);
	setup_env(env);
}

int				keydown_hook(int key, t_envars *env)
{
	if (key == 53)
	{
		cleanup_env(env);
		exit(0);
	}
	if (key == 8)
		cool_color(env);
	if (key == 37)
		env->ccolor = (env->ccolor) ? 0 : 1;//smooth color
	if (key == 15)
		reset_env(env);
	if (key == 37 || key == 15 || key == 8 || key == 1)
		render(env);
	return (0);
}

int				key_pressed_hook(int key, t_envars *env)
{
	if (key != 53)
	{
		if (key == 123)
			env->x_t -= (0.05 / env->f.z_factor);
		if (key == 124)
			env->x_t += (0.05 / env->f.z_factor);
		if (key == 125)
			env->y_t += (0.05 / env->f.z_factor);
		if (key == 126)
			env->y_t -= (0.05 / env->f.z_factor);
		if (key == 24)
			env->iter_lim += 10;
		if (key == 27)
			env->iter_lim -= (env->iter_lim > 10) ? 10 : 0;
		if (key == 78)
			env->f.z_factor /= 1.1;
		if (key == 69)
			env->f.z_factor *= 1.1;
		if (key == 33 && env->iter_lim > 0)
			env->iter_lim -= 5;
		if (key == 30 && env->iter_lim < 100)
			env->iter_lim += 5;
		render(env);
	}
	return (0);
}

/*
void			init_mouse(t_envars *env)
{
	t_mouse		*new_mouse;

	new_mouse = &env->mouse;
	new_mouse->is_pressed = 0;
	new_mouse->freeze = 0;
	new_mouse->prev_x = 0;
	new_mouse->prev_y = 0;
	new_mouse->x = 0;
	new_mouse->y = 0;
	new_mouse->x_ratio = 0.5;
	new_mouse->y_ratio = 0.5;
}

int				mouse_moved_hook(int x, int y, t_envars *env)
{
	t_mouse		*mouse;
	int			f_i;

	mouse = &env->mouse;
	f_i = env->f.interactive;
	if (mouse->freeze == 0 && (x >= 0 && x <= env->w && y >= 0 && y <= env->h))
	{
		mouse->prev_x = mouse->x;
		mouse->prev_y = mouse->y;
		mouse->x = x;
		mouse->y = y;
	}
	return (0);
}
*/
