/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   choose_fract.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 09:04:53 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 13:26:39 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void				fract_table(t_fract_jt j_table[25])
{
		j_table[0] = &julia;
		j_table[1] = &mandelbrot;
		j_table[2] = &burning_ship;
		j_table[3] = &koch;
}

static void				fract_init_table(t_f_set_jt j_table[25])
{
			j_table[0] = &init_julia;
			j_table[1] = &init_mandelbrot;
			j_table[2] = &init_burning_ship;
			j_table[3] = &init_koch;
}

int						get_fract_funct(void *environ, char *choice_str)
{
	static t_fract_jt	fractal_jt[25] = {NULL};
	static t_f_set_jt	fract_setup_jt[25] = {NULL};
	int					choice;
	char				*itoa_choice;
	t_envars			*env;

	env = (t_envars *)environ;
	if (fractal_jt[0] == NULL)
		fract_table(fractal_jt);
	if (fract_setup_jt[0] == NULL)
		fract_init_table(fract_setup_jt);
	choice = ft_atoi(choice_str);
	itoa_choice = ft_itoa(choice);
	if ((choice >= 0 && choice < 4) && ft_strcmp(itoa_choice, choice_str) == 0)
	{
		env->fract_func = fractal_jt[choice];
		env->fract_setup = fract_setup_jt[choice];
		free(itoa_choice);
		return (choice);
		}
		else
		{
		free(itoa_choice);
		return (-1);
		}
}
