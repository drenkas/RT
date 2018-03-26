/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:03:51 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:03:56 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cr		appropriation(double a, double b, double c)
{
	t_cr u;

	u.x = a;
	u.y = b;
	u.z = c;
	return (u);
}

void		ft_minmax_xy(t_cube *c, t_obj *obj, t_cr pos, t_cr dir)
{
	double	t;

	c->tmin.x = (obj->min.x - pos.x) / dir.x;
	c->tmax.x = (obj->max.x - pos.x) / dir.x;
	if (c->tmin.x > c->tmax.x)
	{
		t = c->tmin.x;
		c->tmin.x = c->tmax.x;
		c->tmax.x = t;
	}
	c->tmin.y = (obj->min.y - pos.y) / dir.y;
	c->tmax.y = (obj->max.y - pos.y) / dir.y;
	if (c->tmin.y > c->tmax.y)
	{
		t = c->tmin.y;
		c->tmin.y = c->tmax.y;
		c->tmax.y = t;
	}
	if (c->tmin.y > c->tmin.x)
		c->tmin.x = c->tmin.y;
	if (c->tmax.y < c->tmax.x)
		c->tmax.x = c->tmax.y;
}

void		calculate_value(t_obj *obj, t_mlx *st)
{
	float	size;

	size = obj->size / 2;
	obj->min.x = obj->pos.x - size;
	obj->max.x = obj->pos.x + size;
	obj->min.y = obj->pos.y - size;
	obj->max.y = obj->pos.y + size;
	obj->min.z = obj->pos.z - size;
	obj->max.z = obj->pos.z + size;
	st->t0 = 0;
}

double		inter_cube(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir)
{
	float	t;
	t_cube	c;

	calculate_value(obj, st);
	ft_minmax_xy(&c, obj, pos, dir);
	if ((c.tmin.x > c.tmax.y) || (c.tmin.y > c.tmax.x))
		return (-1);
	c.tmin.z = (obj->min.z - pos.z) / dir.z;
	c.tmax.z = (obj->max.z - pos.z) / dir.z;
	if (c.tmin.z > c.tmax.z)
	{
		t = c.tmin.z;
		c.tmin.z = c.tmax.z;
		c.tmax.z = t;
	}
	if ((c.tmin.x > c.tmax.z) || (c.tmin.z > c.tmax.x))
		return (-1);
	if (c.tmin.z > c.tmin.x)
		c.tmin.x = c.tmin.z;
	if (c.tmax.z < c.tmax.x)
		c.tmax.x = c.tmax.z;
	return (c.tmin.x);
}

t_cr		ft_cubenorm(t_mlx *st, t_cr pos)
{
	t_cr	ret;

	ret = appropriation(0, 0, 0);
	if ((pos.z >= (st->tmp.min.z - 0.0001) && pos.z <=
		(st->tmp.min.z + 0.0001)) || (pos.z >= (st->tmp.max.z - 0.0001)
		&& pos.z <= (st->tmp.max.z + 0.0001)))
		ret = appropriation(1, 0, 0);
	else if ((pos.x >= (st->tmp.min.x - 0.0001) && pos.x <=
		(st->tmp.min.x + 0.0001)) || (pos.x >= (st->tmp.max.x - 0.0001)
		&& pos.x <= (st->tmp.max.z + 0.0001)))
		ret = appropriation(0, -1, 0);
	else if ((pos.y >= (st->tmp.min.y - 0.0001) && pos.y <=
		(st->tmp.min.y + 0.0001)) || (pos.y >= (st->tmp.max.y - 0.0001)
		&& pos.y <= (st->tmp.max.y + 0.0001)))
		ret = appropriation(0, 0, -1);
	return (ret);
}
