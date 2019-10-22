/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render_fract.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 08:37:10 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 10:19:26 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void			init_img(t_envars *env)
{
	t_image		*img;

	img = &env->image;
	img->image = mlx_new_image(env->mlx, env->w, env->h);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->line_s, 
			&img->endian);
	img->bpp /= 8;
}

static void		*render_quads(void *args)
{
	int			x_ind;
	int			y_ind;
	int			x_end;
	int			y_end;
	t_envars	*env;

	env = ((t_targs *)args)->env;
	x_end = (IS_LEFT(((t_targs *)args)->quad)) ? env->w / 2 : env->w;
	y_end = (IS_TOP(((t_targs *)args)->quad)) ? env->h / 2 : env->h;
	x_ind = (IS_LEFT(((t_targs *)args)->quad)) ? -1 : env->w / 2 - 1;
	while (++x_ind < x_end)
	{
		y_ind = (IS_TOP(((t_targs *)args)->quad)) ? -1 : env->h / 2 - 1;
		while (++y_ind < y_end)
		{
			env->fract_func(env, idx(y_ind, x_ind, env->w));
		}
	}
	return (NULL);
}


void			clear_img(t_envars *env)
{
	t_image		*img;

	img = &(env->image);
	ft_bzero(img->ptr, env->size * img->bpp);
}


void			render(t_envars *env)
{
	int			i;
	t_targs		args[BUFF_THREAD];

	clear_img(env);
	i = -1;
	while (++i < BUFF_THREAD)
	{
		args[i].env = env;
		args[i].quad = i;
		pthread_create(&env->tids[i], NULL, render_quads, (void *)&args[i]);
	}
	i = -1;
	while (++i < BUFF_THREAD)
		pthread_join(env->tids[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->image.image, 0, 0);
}

