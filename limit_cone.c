/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 00:18:15 by drenkas           #+#    #+#             */
/*   Updated: 2018/01/14 00:18:18 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		discr_cone(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
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
	return (discr);
}

int			ander_side_t(double t, t_obj *obj, t_cr pos, t_cr dir)
{
	t_cr	p0;
	t_cr	delt_p;
	t_cr	t11;
	double	ug1;
	double	ug2;

	p0 = ft_p0(dir, pos, t);
	delt_p = vectscale(&obj->rot, obj->h);
	obj->max = vec_add(obj->pos, delt_p);
	obj->min = vectsub(&obj->pos, &delt_p);
	t11 = vectsub(&p0, &obj->min);
	delt_p = vectsub(&p0, &obj->max);
	vectnorm(&t11);
	vectnorm(&delt_p);
	ug1 = vectdot(&t11, &obj->rot);
	ug2 = vectdot(&delt_p, &obj->rot);
	if (ug1 > 0 && ug2 < 0)
		return (1);
	else
		return (0);
	return (1);
}

double		int_conelim(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double	discr;
	double	t;
	double	s1;
	double	s2;

	t = 0.0;
	discr = discr_cone(st, o, pos, dir);
	if (discr < 0)
		return (-1);
	st->t0 = (-st->b - sqrtf(discr)) / (2 * st->a);
	st->t1 = (-st->b + sqrtf(discr)) / (2 * st->a);
	s1 = ander_side_t(st->t0, o, pos, dir);
	s2 = ander_side_t(st->t1, o, pos, dir);
	if (s1 == 0 && s2 == 0)
		return (-1);
	else if (s2 > 0 && s1 > 0)
		t = st->t0 > st->t1 ? st->t1 : st->t0;
	else if (s2 > 0)
		t = st->t1;
	else if (s1 > 0)
		t = st->t0;
	return (t);
}

double		inter_limit_cone(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double	u;
	double	s;
	double	beta;

	u = int_conelim(st, o, pos, dir);
	o->k = 1;
	s = kplane(o, pos, dir, o->min);
	beta = sqrtf(o->size * 0.01) * o->h;
	o->size2 = u;
	if (s > 0)
	{
		if (sqrtf(calculate_va(o, pos, dir, s)) <= beta
			&& (s < u || u == -1))
			u = s;
	}
	s = kplane(o, pos, dir, o->max);
	if (s > 0)
	{
		if (sqrtf(calculate_v(o, pos, dir, s)) <= beta && (s < u || u == -1))
			u = s;
	}
	if (o->size2 != u)
		o->k = 8;
	return (u);
}

void		rec_lim_cone(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;
	double	rot[3];

	i = -1;
	obj_fix(st, 8);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	tmp = ft_strsplit(st[4], ',');
	while (++i < 3)
		rot[i] = ft_check_dot(tmp[i]);
	obj->rot.x = rot[0];
	obj->rot.y = rot[1];
	obj->rot.z = rot[2];
	obj->size = (double)ft_atoi(st[5]);
	free_split(tmp);
	tmp = ft_strsplit(st[6], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	obj->h = (double)ft_atoi(st[7]);
}
