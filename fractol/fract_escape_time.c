/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fract_escape_time.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 10:21:42 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 10:38:53 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_dcmplx		abs_sqr(t_dcmplx z)
{
	z.rsqr = (z.r * z.r);
	z.isqr= (z.i * z.i);
	return (z);
}


void			calc_z(t_envars *env, t_dcmplx *tmp_z, t_dcmplx z, t_dcmplx c)
{
	if (env->f.d == 2)
	{
		tmp_z->i = (z.r + z.i) * (z.r + z.i) - z.rsqr - z.isqr + c.i;
		tmp_z->r = z.rsqr - z.isqr + c.r;
	}
	else if (env->f.d == 3)
	{
		tmp_z->i = z.i * (3 * z.rsqr - z.isqr) + c.i;
		tmp_z->r = z.r * (z.rsqr - 3 * z.isqr) + c.r;
	}
	else if (env->f.d == 4)
	{
		tmp_z->i = (4 * z.r * z.i) * (z.rsqr - z.isqr) + c.i;
		tmp_z->r = (z.rsqr * z.rsqr) + z.isqr * (z.isqr - 6 * z.rsqr) + c.r;
	}
	if (env->f.abs == 1)
	{
		tmp_z->i = (tmp_z->i < 0.0f) ? -tmp_z->i : tmp_z->i;
		tmp_z->r = (tmp_z->r < 0.0f) ? -tmp_z->r : tmp_z->r;
	}
}

float			escape_time(t_envars *env, t_fractal f)
{
	size_t		iter;
	t_dcmplx	z;
	t_dcmplx	c;
	t_dcmplx	tmp_z;

	z = f.z;
	c = f.c;
	iter = 0;
	z = abs_sqr(z);
	while (z.rsqr + z.isqr <= 4.0 && iter < env->iter_lim)
	{
		calc_z(env, &tmp_z, z, c);
		if (z.r == tmp_z.r && z.i == tmp_z.i)
		{
			iter = env->iter_lim;
			break ;
		}
		z = abs_sqr(tmp_z);
		iter++;
	}
	if (env->ccolor == 1 && iter != env->iter_lim)
		return ((float)iter + 1 - log(log(z.rsqr + z.isqr)) / log(env->f.d));
	return ((float)iter);
}
