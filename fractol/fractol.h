/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dcoat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 07:54:40 by dcoat        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 13:25:33 by dcoat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <stddef.h>
# include <pthread.h>

# include "libft/includes/ft_printf.h"

# define SCREEN_X 600
# define SCREEN_Y 600

#define IS_LEFT(x) ((x)==0||(x)==2)
#define IS_TOP(x) ((x)==0||(x)==1)
#define BUFF_THREAD 4


typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				line_s;
	int				endian;
}					t_image;

typedef struct		s_mouse
{
	double			prev_x;
	double			prev_y;
	double			x;
	double			y;
	double			x_ratio;
	double			y_ratio;
	int				freeze;
	int				is_pressed;
}					t_mouse;

typedef struct		s_dcmplx
{
	double			r;
	double			i;
	double			rsqr;
	double			isqr;
}					t_dcmplx;

typedef struct		s_fractal
{
	t_dcmplx		z;
	t_dcmplx		c;
	int				d;
	int				x;
	int				y;
	int				abs;
	int				interactive;
	double			z_factor;
	double			x_cent;
	double			x_wid;
	double			x_min;
	double			x_max;
	double			y_cent;
	double			y_wid;
	double			y_min;
	double			y_max;
}					t_fractal;

typedef struct		s_collor
{
	int				cent;
	int				wid;
	float			r_freq;
	float			g_freq;
	float			b_freq;
	float			r_phase;
	float			g_phase;
	float			b_phase;
}					t_collor;

typedef void		(*t_fract_jt)(void *environ, int pix_ind);
typedef void		(*t_f_set_jt)(void *environ);

typedef struct		s_envars
{
	void			*mlx;
	void			*win;
	int				w;
	int				h;
	int				size;
	int				fract_choice;
	float			*iter_buf;
	size_t			iter_lim;
	double			x_t;
	double			y_t;
	pthread_t		tids[4];
	int				color_style;
	int				ccolor;
	t_fractal		f;
	t_collor		c;
	t_fract_jt		fract_func;
	t_f_set_jt		fract_setup;
	t_image			image;
	t_mouse			mouse;
}					t_envars;

typedef struct		s_targs
{
	t_envars		*env;
	int				quad;
}					t_targs;


/** main.c **/

void				setup_env(t_envars *env);

/** render_fract.c **/

void				render(t_envars *env);
void				clear_img(t_envars *env);
//static void			*render_quads(void *args);
void				init_img(t_envars *env);

/** choose_fract.c  **/

int					get_fract_funct(void *environ, char *choice_str);
//static void			fract_init_choice(t_f_set_jt j_table[25]);
//static void			fract_table(t_fract_jt j_table[25]);

/** init_fract.c **/

void				init_koch(void *environ);
void				init_burning_ship(void *environ);
void				init_mandelbrot(void *environ);
void				init_julia(void *environ);

/** calc_fract **/

void				koch(void *environ, int pix_ind);
void				burning_ship(void *environ, int pix_ind);
void				mandelbrot(void *environ, int pix_ind);
void				julia(void *environ, int pix_ind);

/** fract_escape_time.c **/

float				escape_time(t_envars *env, t_fractal f);
void				calc_z(t_envars *env, t_dcmplx *tmp_z, t_dcmplx z, 
					t_dcmplx c);

/** fract_tools.c **/

t_fractal			calc_fract_min_max(t_envars *env, t_fractal f);
void				img_pixel_put(t_envars *env, double x, double y, 
					int color);
double				ft_lint(double start, double end, 
					double decimal_percent);
int					idx(int row, int col, int dim);

/** key_management.c **/

int					key_pressed_hook(int key, t_envars *env);
int					keydown_hook(int key, t_envars *env);
void				reset_env(t_envars *env);
//static void			cleanup_env(t_envars *env);

/** fract_color.c **/

int					choose_col(t_envars *env, float iter);
void				toogle_palette(t_envars *env);
void				setup_color(t_envars *env);

#endif
