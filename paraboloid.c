/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:05:54 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:05:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cr		ft_paraboloid_n(t_mlx *st, t_cr pos)
{
	t_cr	ret;
	double	m;
	t_cr	u;

	u = vectsub(&pos, &st->tmp.pos);
	m = vectdot(&u, &st->tmp.rot);
	ret.x = pos.x - st->tmp.pos.x - st->tmp.rot.x * (m + st->tmp.k);
	ret.y = pos.y - st->tmp.pos.y - st->tmp.rot.y * (m + st->tmp.k);
	ret.z = pos.z - st->tmp.pos.z - st->tmp.rot.z * (m + st->tmp.k);
	return (ret);
}

t_cr		ft_p0(t_cr ray_d, t_cr ray_o, double min_t)
{
	t_cr	p;

	p.x = ray_o.x + (min_t * ray_d.x);
	p.y = ray_o.y + (min_t * ray_d.y);
	p.z = ray_o.z + (min_t * ray_d.z);
	return (p);
}

t_cr		vec_add(t_cr a, t_cr b)
{
	t_cr	u;

	u.x = a.x + b.x;
	u.y = a.y + b.y;
	u.z = a.z + b.z;
	return (u);
}

double		ft_delta(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir)
{
	double	discr;
	t_cr	x;

	x = vectsub(&pos, &obj->pos);
	st->a = vectdot(&dir, &dir) - pow(vectdot(&dir, &obj->rot), 2);
	st->b = 2 * (vectdot(&dir, &x) - vectdot(&dir, &obj->rot) *
		(vectdot(&x, &obj->rot) + 2 * obj->k));
	st->c = vectdot(&x, &x) - vectdot(&x, &obj->rot) *
		(vectdot(&x, &obj->rot) + 4 * obj->k);
	discr = st->b * st->b - 4 * st->a * st->c;
	return (discr);
}

int			ander_side(double t, t_obj *obj, t_cr pos, t_cr dir)
{
	double	ug1;
	double	ug2;
	t_cr	t11;
	t_cr	t12;

	obj->min = ft_p0(dir, pos, t);
	obj->max = vec_add(obj->pos, vectscale(&obj->rot, obj->h));
	t11 = vectsub(&obj->min, &obj->pos);
	t12 = vectsub(&obj->min, &obj->max);
	vectnorm(&t11);
	vectnorm(&t12);
	ug1 = vectdot(&t11, &obj->rot);
	ug2 = vectdot(&t12, &obj->rot);
	if (ug1 > 0 && ug2 < 0)
		return (1);
	else
		return (0);
	return (1);
}
