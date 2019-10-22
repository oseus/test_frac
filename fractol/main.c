/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 08:03:27 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 13:35:04 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "fractol.h"



void			setup_env(t_envars *env)
{
	env->w = SCREEN_X;
	env->h = SCREEN_Y;
	env->size = env->w * env->h;
	env->x_t = 0;
	env->y_t = 0;
	env->ccolor = 0;
	env->iter_lim = 50;
	env->iter_buf = (float *)malloc(env->size * sizeof(float));
	env->fract_setup(env);
	setup_color(env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w, env->h, "fractol");
	init_img(env);
	mlx_key_hook(env->win, keydown_hook, env);
	mlx_hook(env->win, 2, 0, key_pressed_hook, env);
	render(env);
	mlx_loop(env->mlx);
}

int				main(int ac, char **av)
{
	t_envars	env;

	env.fract_choice = -1;
	if (ac == 2 && (env.fract_choice = get_fract_funct(&env, av[1])) != -1)
	{
		//info(1);
		setup_env(&env);
		return (0);
	}
	//else
	//{
	////info(0);
	//return (1);
	//}
	return (0);
}
