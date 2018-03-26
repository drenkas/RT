/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 23:41:29 by drenkas           #+#    #+#             */
/*   Updated: 2018/01/13 23:41:32 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				discr_halfsp(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir)
{
	double	discr;

	st->dist = vectsub(&pos, &obj->pos);
	st->a = vectdot(&dir, &dir);
	st->b = 2 * vectdot(&dir, &st->dist);
	st->c = vectdot(&st->dist, &st->dist) - (obj->size * obj->size);
	discr = st->b * st->b - 4 * st->a * st->c;
	if (discr < 0)
		return (0);
	st->t0 = (-st->b - sqrtf(discr)) / (2 * st->a);
	st->t1 = (-st->b + sqrtf(discr)) / (2 * st->a);
	return (1);
}

static double	ft_s(double s1, double s2, t_mlx *st)
{
	double t;

	t = 0.0;
	if (s2 > 0 && s1 > 0)
		t = st->t0 > st->t1 ? st->t1 : st->t0;
	else if (s2 > 0)
		t = st->t1;
	else if (s1 > 0)
		t = st->t0;
	return (t);
}

double			inter_half_sphere(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir)
{
	double	s1;
	double	s2;
	double	t;
	double	w;

	if (discr_halfsp(st, obj, pos, dir) == 0)
		return (0);
	s1 = ander_side(st->t0, obj, pos, dir);
	s2 = ander_side(st->t1, obj, pos, dir);
	obj->rot = appropriation(1, 0, 0);
	obj->h = obj->size;
	t = 20000;
	if (s1 == 0 && s2 == 0)
		return (-1);
	t = ft_s(s1, s2, st);
	w = inter_disk(st, obj, pos, dir);
	if (w < t && w > 0)
	{
		obj->k = 5;
		return (w);
	}
	obj->k = 1;
	return (t);
}

void			rec_half_sph(char **st, t_obj *obj)
{
	char **tmp;

	obj_fix(st, 6);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	obj->size = (double)ft_atoi(st[4]);
	tmp = ft_strsplit(st[5], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
}
