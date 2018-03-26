/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 19:22:26 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/25 19:22:27 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# define RED "\033[02;31m"
# define OK "\033[32m"
# define HIGH 800
# define WIDTH 800
# define CAEF 5 * M_PI / 180
# define S_L thr->mlx->s_l
# define OBJ st->obj
# define RT 0.19
# define MLX st->mlx_ptr
# define WIN st->win_prt

# define T_E 0.375
# define F_S 0.5
# define F_F 0.25
# define T_S 0.1875
# define F_E 0.125
# define F_T 0.33333333333

typedef struct			s_t
{
	double				u[3];
	double				b;
	double				q2;
	double				i;
	double				rial1;
	double				im1;
	double				rial2;
	double				im2;
	double				beta;
}						t_t;

typedef struct			s_crd
{
	double				x;
	double				y;
	double				z;
}						t_cr;

typedef	struct			s_cube
{
	t_cr				tmin;
	t_cr				tmax;
}						t_cube;

typedef	struct			s_obj
{
	char				*type;
	double				size;
	t_cr				dir;
	t_cr				pos;
	t_cr				rot;
	t_cr				col;
	int					k;
	double				h;
	double				size2;
	t_cr				min;
	t_cr				max;
	t_cr				a;
	t_cr				b;
	t_cr				c;
}						t_obj;

typedef struct			s_tim
{
	double				k;
	double				k1;
	double				k2;
	double				k3;
	double				k4;
	double				k5;
}						t_tim;

typedef struct			s_coef
{
	int					legth;
	t_cr				rx;
	double				o_x2;
	double				o_y2;
	double				o_z2;
	t_tim				x;
	double				c3;
}						t_coef;

typedef struct			s_mlx
{
	int					i;
	int					bnw;
	int					sepia;
	void				*mlx_ptr;
	void				*win_prt;
	void				*img;
	int					bpp;
	int					s_l;
	int					end;
	char				*addr;
	int					put;
	float				percent_refl;
	int					put_ref;
	int					count_refl;
	t_cr				norm;
	t_cr				pos_refl;
	t_cr				refl;
	t_obj				tmp_ref;
	t_cr				refr;
	float				n1;
	float				percent_refr;
	t_cr				pos_refr;
	int					old_x;
	int					old_y;
	double				anti_al;
	int					col;
	int					ct_l;
	t_cr				cam_dir;
	t_cr				cam_pos;
	t_cr				rot;
	t_cr				ray_dir;
	double				zoom;
	double				t;
	t_cr				dist;
	double				dst;
	double				a;
	double				b;
	double				c;
	double				t0;
	double				t1;
	int					count;
	t_obj				*obj;
	t_obj				*lgh;
	t_obj				tmp;
	float				tab[4];
	double				fuck;
	int					code;
	int					hub_ch;
	int					dev_ch;
	int					g;
	int					tr;
	int					test_this_shit;
	t_cr				save_dist;
	int					cockroach;
}						t_mlx;

typedef struct			s_thr
{
	t_mlx				*mlx;
	int					id;
}						t_thr;

typedef struct			s_tri
{
	t_cr				e1;
	t_cr				e2;
	t_cr				pvec;
	double				v;
	double				u;
	float				det;
	float				indet;
	t_cr				tvec;
	t_cr				qvec;
}						t_tri;

void					start_mlx(t_mlx *mlx, char *av);
void					check_arg(t_mlx *mlx, char *av);
int						record_obj(char *line, t_obj *obj, t_mlx *mlx);
void					rec_obj_check(char **strs, t_obj *obj);
void					rec_co_cy(char **st, t_obj *obj);
void					rec_sph(char **st, t_obj *obj);
void					rec_pl(char **st, t_obj *obj);
void					rec_lig(char **st, t_mlx *mlx);
void					rec_cam(char **st, t_mlx *obj);
int						ft_exit(t_mlx *st);
int						ft_key_hook(int key, t_mlx *st);
void					start_threads(void *st);
void					start_bitch(t_mlx *mlx);
double					vectdot(t_cr *v1, t_cr *v2);
t_cr					vectcross(t_cr *v1, t_cr *v2);
t_cr					vectscale(t_cr *v, double n);
t_cr					vectsub(t_cr *v1, t_cr *v2);
t_cr					vectadd(t_cr v1, t_cr v2);
double					ft_check_dot(char *tmp);
void					vectnorm(t_cr *v);
double					inter_sphere(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir);
int						inter(t_mlx *st, t_cr pos, t_cr dir);
void					raytrace(t_mlx *st, double x, double y);
void					create_ray(t_mlx *st, double x, double y);
double					inter_plane(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir);
double					inter_cylinder(t_mlx *st, t_obj *o, t_cr pos, t_cr dir);
double					inter_cone(t_mlx *st, t_obj *o, t_cr pos, t_cr dir);
int						check_l(char *line);
void					ft_fzero(float *s, int n);
float					ft_clamp(float v, float min, float max);
float					*lamb_light(t_mlx *st, t_cr p, t_cr dr, float *tab);
t_cr					normalize(t_mlx *st, t_cr pos, t_obj temp);
float					ft_spec(t_mlx *mlx, t_cr dist, float d, float lambert);
int						ft_shadow(t_mlx *st, t_obj lgh, t_cr pos, int put);
void					move_cam(t_mlx *s, int code);
void					rot_crutch(t_mlx *st, double x, double y);
float					*ft_glare(t_mlx *st, float *tab, t_cr ran);
void					arg_norm(char *line, t_mlx *mlx);
void					ft_pos(t_cr *ps, t_mlx *st, t_cr p, t_cr dr);

void					free_split(char **st);
void					ft_menu(t_mlx *st);
void					show_hub(t_mlx *st);
void					dev_hub(t_mlx *st);
void					free_mass(char **st, int x);
void					menu_key(t_mlx *st, int k);
int						fuck_norm(double range, t_mlx *st, int i);
void					l_norm(t_mlx *st, t_cr dist, t_cr pos, int i);
void					obj_fix(char **st, int n);
float					*reflect(t_mlx *st, t_cr *pos, float *tab);
void					hook_refl(t_mlx *st, int key);
float					*sum_color(float *sum_tab, float *color);
float					*res_color(float *sum_tab, double count, float *color);
void					hook_aa(t_mlx *st, int key);
float					*refract(t_mlx *st, t_cr *pos, float *tab);
t_cr					ft_p0(t_cr ray_d, t_cr ray_o, double min_t);
t_cr					ft_paraboloid_n(t_mlx *st, t_cr pos);
t_cr					ft_p0(t_cr ray_d, t_cr ray_o, double min_t);
t_cr					vec_add(t_cr a, t_cr b);
double					ft_delta(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir);
int						ander_side(double t, t_obj *obj, t_cr pos, t_cr dir);
int						equation_of_degree_4(double *a, double *r);
int						ft_solving_cubic(double a, double b,\
							double c, double d, double *x);
void					ft_discr(t_obj *obj, t_cr pos, t_cr dir, double *u);
t_cr					ft_normal_tor(t_mlx *st, t_cr pos);
double					iplane(t_mlx *st, t_obj *o, t_cr p, t_cr dir);
void					rec_tor(char **st, t_obj *obj);
void					rec_trim_cy(char **st, t_obj *obj);
void					rec_par(char **st, t_obj *obj);
void					rec_disk(char **st, t_obj *obj);
double					inter_trimmed_cylinder(t_mlx *st, t_obj *o,\
						t_cr pos, t_cr dir);
double					inter_paraboloid(t_mlx *st, t_obj *obj,\
						t_cr pos, t_cr dir);
double					inter_disk(t_mlx *st, t_obj *o, t_cr p, t_cr dir);
double					inter_torus(t_mlx *st, t_obj *o, t_cr pos, t_cr dir);
double					inter_triangle(t_mlx *st, t_obj *o, t_cr p, t_cr dir);
void					rec_triangle(char **st, t_obj *obj);

void					rec_mobius(char **st, t_obj *obj);
double					inter_mobius(t_mlx *st, t_obj *o, t_cr pos, t_cr dir);
void					coeffs(double *coeff, t_cr pos, t_cr dir);
t_cr					ft_norm_mobius(t_cr p);
t_cr					vectadd(t_cr a, t_cr b);
int						dblsgn(double x);
int						calculation_coefficients(double *qa, double *s,\
						double q, double r);
double					inter_cube(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir);
void					rec_cube(char **st, t_obj *obj);
t_cr					ft_cubenorm(t_mlx *st, t_cr pos);
t_cr					appropriation(double a, double b, double c);
t_cr					ft_pyramid_norm(t_mlx *st);
double					inter_piramid(t_mlx *st, t_obj *o, t_cr pos, t_cr dir);
void					rec_piramid(char **st, t_obj *obj);

void					solution(t_t *t, double c, double disc, double br);
void					plus(t_t *t);
double					ft_count_first(t_t *t, double *a,\
						double disc, double aa);
double					inter_tri(t_mlx *st, t_obj *o, t_cr pos, t_cr dir);
double					kplane(t_obj *o, t_cr p, t_cr dir, t_cr q);
float					*bnw(float *tab);
float					*sepia(float *tab);
double					calculate_va(t_obj *o, t_cr pos, t_cr dir, double s);
double					calculate_v(t_obj *o, t_cr pos, t_cr dir, double s);

void					rec_half_sph(char **st, t_obj *obj);
double					inter_half_sphere(t_mlx *st, \
							t_obj *obj, t_cr pos, t_cr dir);
void					rec_lim_cone(char **st, t_obj *obj);
double					inter_limit_cone(t_mlx *st, \
							t_obj *o, t_cr pos, t_cr dir);
void					inter_two_light(int i, t_mlx *st, t_cr pos, t_cr dist);
double					refl_inter_tri(int i, t_mlx *st, t_cr pos);
double					refr_inter_tri(int i, t_mlx *st, t_cr pos);
void					hooks_refr(t_mlx *s, int code);

void					menu1(t_mlx *mlx);
void					draw_menu(t_mlx *mlx);
int						mouse_hook1(int b, int x, int y, t_mlx *mlx);
int						hooks1(int c, t_mlx *mlx);
void					check_camera(char **st);
void					check_light(char **st);
void					check_plane(char **st);
void					check_sphere(char **st);
void					check_cylinder(char **st);
void					choose_scene(t_mlx *mlx);
void					draw_ccontent(t_mlx *mlx);
void					start_scene(t_mlx *mlx);
void					free_arr(t_obj *obj, t_mlx *st);
void					check_arg1(t_mlx *mlx, char *av);
void					add_sphere(t_mlx *mlx, int i);
void					add_cone(t_mlx *mlx, int i);
int						mouse_hook2(int b, int x, int y, t_mlx *mlx);
void					draw_econtent(t_mlx *mlx);
void					choose_effect(t_mlx *mlx);
void					back(t_mlx *mlx);
void					draw_ocontent(t_mlx *mlx);
void					add_obj(t_mlx *mlx);
int						check_num(char *st, int f);
int						check_bgr(char *st);
int						check_rot1(char *st, int i, int *c, int *t);
int						check_rot2(char *st, int i, int *c, int *t);
int						check_rot(char *st);
void					gm_ch_0(t_mlx *mlx, int x, int y);
void					gm_ch_1(t_mlx *mlx, int x, int y);
void					gm_ch_12(t_mlx *mlx, int x, int y);
void					gm_ch_3(t_mlx *mlx, int x, int y);
void					gm_ch(t_mlx *mlx, int x, int y);
void					dr_mc_1(t_mlx *mlx, char **str, char **str1);
void					dr_mc_2(t_mlx *mlx, char **str);
void					dr_mc_3(t_mlx *mlx, char **str);
void					dr_mc_4(t_mlx *mlx);
void					menu1_init(t_mlx *mlx);
void					load_spin(t_mlx *mlx);
void					start_loading(t_mlx *mlx);
void					take_screenshot(t_mlx *mlx);
void					play_music(t_mlx *mlx);
void					zoom_cam(t_mlx *s, int code);
void					gm_ch_2(t_mlx *mlx, int x, int y);
void					move_obj(t_mlx *mlx, int key);
void					check_halfsphere(char **st);
void					check_torus(char **st);
void					check_limitcone(char **st);
void					check_mobius(char **st);
void					check_paraboloid(char **st);
void					check_disk(char **st);
void					check_triangle(char **st);
void					check_dot_rt(char *av);
void					crutch_in_hooks(t_mlx *mlx, int x, int y);
#endif
