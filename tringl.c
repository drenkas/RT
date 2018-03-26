/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tringl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:32:17 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 11:32:21 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	inter_triangle(t_mlx *st, t_obj *o, t_cr p, t_cr dir)
{
	t_tri z;

	z.e1 = vectsub(&o->b, &o->a);
	z.e2 = vectsub(&o->c, &o->a);
	z.pvec = vectcross(&dir, &z.e2);
	z.det = vectdot(&z.e1, &z.pvec);
	z.indet = 1 / z.det;
	z.tvec = vectsub(&p, &o->a);
	z.u = vectdot(&z.tvec, &z.pvec) * z.indet;
	if (z.u < 0 || z.u > 1)
		return (-1);
	z.qvec = vectcross(&z.tvec, &z.e1);
	z.v = vectdot(&dir, &z.qvec) * z.indet;
	if (z.v < 0 || z.u + z.v > 1)
		return (-1);
	st->t0 = vectdot(&z.e2, &z.qvec) * z.indet;
	return (st->t0);
}

double	inter_cone(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double	discr;

	st->dist = vectsub(&pos, &o->pos);
	vectnorm(&o->rot);
	st->a = vectdot(&dir, &dir) - (1 + (o->size * 0.01)) *
	pow(vectdot(&dir, &o->rot), 2);
	st->b = 2 * (vectdot(&dir, &st->dist) - (1 + (o->size * 0.01)) *
	vectdot(&dir, &o->rot) * vectdot(&st->dist, &o->rot));
	st->c = vectdot(&st->dist, &st->dist) - (1 + (o->size * 0.01)) *
	pow(vectdot(&st->dist, &o->rot), 2);
	discr = st->b * st->b - 4 * st->a * st->c;
	if (discr < 0)
		return (-1);
	st->t0 = (-st->b - sqrtf(discr)) / (2 * st->a);
	if (st->t0 > 0.001)
		return (st->t0);
	return (0);
}

void	rec_triangle_two(char **tmp, char **st, t_obj *obj, int i)
{
	double	rot[3];

	tmp = ft_strsplit(st[3], ',');
	obj->c.x = (double)ft_atoi(tmp[0]);
	obj->c.y = (double)ft_atoi(tmp[1]);
	obj->c.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	tmp = ft_strsplit(st[4], ',');
	while (++i < 3)
		rot[i] = ft_check_dot(tmp[i]);
	obj->rot.x = rot[0];
	obj->rot.y = rot[1];
	obj->rot.z = rot[2];
	free_split(tmp);
	tmp = ft_strsplit(st[5], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
}

void	rec_triangle(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;

	i = -1;
	obj_fix(st, 6);
	tmp = ft_strsplit(st[1], ',');
	obj->a.x = (double)ft_atoi(tmp[0]);
	obj->a.y = (double)ft_atoi(tmp[1]);
	obj->a.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	tmp = ft_strsplit(st[2], ',');
	obj->b.x = (double)ft_atoi(tmp[0]);
	obj->b.y = (double)ft_atoi(tmp[1]);
	obj->b.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	rec_triangle_two(tmp, st, obj, i);
}

float	*ft_glare(t_mlx *st, float *tab, t_cr ran)
{
	float	glare;
	float	large;
	t_cr	tmp;

	glare = 0.0;
	tmp = vectscale(&st->norm, (2 * vectdot(&st->norm, &ran)));
	tmp = vectsub(&ran, &tmp);
	large = vectdot(&tmp, &st->ray_dir);
	if (large > 0.0)
		glare = ft_clamp((pow(large, 30.0) * 1.0), 0.0, 1.0);
	tab[0] += glare;
	tab[1] += glare;
	tab[2] += glare;
	return (tab);
}
