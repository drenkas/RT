/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:00:40 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:00:44 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		calculate_va(t_obj *o, t_cr pos, t_cr dir, double s)
{
	t_cr	pp;
	t_cr	v;
	double	d2;

	pp = ft_p0(dir, pos, s);
	v = vectsub(&pp, &o->pos);
	d2 = vectdot(&v, &v);
	return (d2);
}

double		calculate_v(t_obj *o, t_cr pos, t_cr dir, double s)
{
	t_cr	pp;
	t_cr	v;
	double	d2;

	pp = ft_p0(dir, pos, s);
	v = vectsub(&pp, &o->max);
	d2 = vectdot(&v, &v);
	return (d2);
}

double		inter_tri(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double	u;
	double	s;

	o->k = 1;
	u = inter_trimmed_cylinder(st, o, pos, dir);
	s = kplane(o, pos, dir, o->pos);
	o->size2 = u;
	if (s > 0)
	{
		if (sqrtf(calculate_va(o, pos, dir, s)) <= o->size
			&& (s < u || u == -1))
			u = s;
	}
	s = kplane(o, pos, dir, o->max);
	if (s > 0)
	{
		if (sqrtf(calculate_v(o, pos, dir, s)) <= o->size && (s < u || u == -1))
			u = s;
	}
	if (o->size2 != u)
		o->k = 8;
	return (u);
}

double		trimmed_disk(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double	discr;

	st->dist = vectsub(&pos, &o->pos);
	vectnorm(&o->rot);
	st->a = vectdot(&dir, &dir) - pow(vectdot(&dir, &o->rot), 2);
	st->b = 2 * (vectdot(&dir, &st->dist) - vectdot(&dir, &o->rot) *
	vectdot(&st->dist, &o->rot));
	st->c = vectdot(&st->dist, &st->dist) -
	pow(vectdot(&st->dist, &o->rot), 2) - pow(o->size, 2);
	discr = st->b * st->b - 4 * st->a * st->c;
	return (discr);
}

double		inter_trimmed_cylinder(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double	discr;
	double	s1;
	double	s2;
	double	t;

	t = 0.0;
	discr = trimmed_disk(st, o, pos, dir);
	if (discr < 0)
		return (-1);
	st->t0 = (-st->b + sqrtf(discr)) / (2 * st->a);
	st->t1 = (-st->b - sqrtf(discr)) / (2 * st->a);
	s1 = ander_side(st->t0, o, pos, dir);
	s2 = ander_side(st->t1, o, pos, dir);
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
