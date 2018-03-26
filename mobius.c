/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mobius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:57:25 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 11:57:31 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			ft_s(double t, t_cr p0)
{
	if (sin(t / 2) > 0)
		return (p0.z / sin(t / 2));
	else
	{
		if (cos(t) > 0.001)
			return ((p0.x / cos(t) - 1) / cos(t / 2));
		else
			return ((p0.y / sin(t) - 1) / cos(t / 2));
	}
}

int				check_point(t_cr p0, double max)
{
	double t;
	double s;

	t = atan2(p0.y, p0.x);
	s = ft_s(t, p0);
	p0.x -= (1 + s * cos(t / 2)) * cos(t);
	p0.y -= (1 + s * cos(t / 2)) * sin(t);
	p0.z -= s * sin(t / 2);
	t = vectdot(&p0, &p0);
	if (t > 0.0000001)
		return (0);
	if (s >= -max && s <= max)
		return (1);
	else
		return (0);
}

double			inter_mobius(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	double		a[3];
	double		t[3];
	t_cr		p0;
	t_cr		u;

	st->cockroach = 0;
	pos = vectsub(&pos, &o->pos);
	coeffs(a, pos, dir);
	a[1] = calculation_coefficients(a, t, 0.0, 0.0);
	a[0] = 0;
	while (a[0] < a[1])
	{
		if (t[(int)a[0]] > 0.001)
		{
			u = vectscale(&dir, t[(int)a[0]]);
			p0 = vectadd(u, pos);
			if (check_point(p0, o->size))
				return (t[(int)a[0]]);
		}
		a[0]++;
	}
	return (-1);
}

void			rec_mobius(char **st, t_obj *obj)
{
	char		**tmp;

	obj_fix(st, 6);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	obj->size = atof(st[4]);
	if (obj->size > 1.0 || obj->size < 0.1)
		ft_error("INVALID MAP \n");
	tmp = ft_strsplit(st[5], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
}
