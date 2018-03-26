/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:01:00 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:01:04 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		inter_paraboloid(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir)
{
	double	discr;
	double	s1;
	double	s2;

	discr = ft_delta(st, obj, pos, dir);
	if (discr < 0)
		return (0);
	st->t0 = (-st->b + sqrtf(discr)) / (2 * st->a);
	st->t1 = (-st->b - sqrtf(discr)) / (2 * st->a);
	s1 = ander_side(st->t0, obj, pos, dir);
	s2 = ander_side(st->t1, obj, pos, dir);
	if (s1 == 0 && s2 == 0)
		return (-1);
	if (s2 > 0 && s1 > 0)
		obj->size = st->t0 > st->t1 ? st->t1 : st->t0;
	else if (s2 > 0)
		obj->size = st->t1;
	else if (s1 > 0)
		obj->size = st->t0;
	else
		return (-1);
	return (obj->size);
}

double		inter_disk(t_mlx *st, t_obj *o, t_cr p, t_cr dir)
{
	t_cr	pp;
	t_cr	v;
	double	d2;

	if (iplane(st, o, p, dir))
	{
		pp = ft_p0(dir, p, st->t0);
		v = vectsub(&pp, &o->pos);
		d2 = vectdot(&v, &v);
		if (sqrtf(d2) <= o->h)
			return (st->t0);
	}
	return (-1);
}

double		inter_torus(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	int		count_roots;
	int		i;
	double	u[4];
	double	x[4];
	double	l;

	st->t0 = 0;
	ft_discr(o, pos, dir, u);
	count_roots = equation_of_degree_4(u, x);
	if (count_roots <= 0)
		return (-1);
	i = 0;
	l = 20000;
	while (count_roots > i)
	{
		if (x[i] < l && x[i] > 0)
			l = x[i];
		i++;
	}
	if (l < 0 && l == 20000)
		return (-1);
	return (l);
}
