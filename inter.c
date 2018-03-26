/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:50:10 by drenkas           #+#    #+#             */
/*   Updated: 2017/05/08 15:50:10 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	inter_cylinder(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
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
	if (discr < 0)
		return (-1);
	st->t0 = (-st->b - sqrtf(discr)) / (2 * st->a);
	if (st->t0 > 0.001)
		return (st->t0);
	return (st->t0);
}

double	inter_plane(t_mlx *st, t_obj *o, t_cr p, t_cr dir)
{
	double	d;

	d = vectdot(&dir, &o->rot);
	if (fabs(d) > 0.001)
	{
		st->t0 = ((vectdot(&o->rot, &o->pos) - vectdot(&o->rot, &p)) / d);
		return (st->t0);
	}
	return (-1);
}

double	inter_sphere(t_mlx *st, t_obj *obj, t_cr pos, t_cr dir)
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
	if (st->t0 < 0.001)
		return (0);
	return (st->t0);
}

double	intertwo(int i, t_mlx *st, t_cr pos, t_cr dir)
{
	double range;

	range = 0;
	if (ft_strcmp(OBJ[i].type, "plane") == 0)
		range = inter_plane(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "cylinder") == 0)
		range = inter_cylinder(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "cone") == 0)
		range = inter_cone(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "trimcyl") == 0)
		range = inter_tri(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "paraboloid") == 0)
		range = inter_paraboloid(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "disk") == 0)
		range = inter_disk(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "torus") == 0)
		range = inter_torus(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "triangle") == 0)
		range = inter_triangle(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "cube") == 0)
		range = inter_cube(st, &OBJ[i], pos, dir);
	else if (ft_strcmp(OBJ[i].type, "piramid") == 0)
		range = inter_piramid(st, &OBJ[i], pos, dir);
	return (range);
}

int		inter(t_mlx *st, t_cr pos, t_cr dir)
{
	int		i;
	double	range;
	int		p;

	i = 0;
	range = 0;
	st->t = 40000.0;
	p = 0;
	while (i < st->col)
	{
		if (ft_strcmp(OBJ[i].type, "sphere") == 0)
			range = inter_sphere(st, &OBJ[i], pos, dir);
		else if (ft_strcmp(OBJ[i].type, "mobius") == 0)
			range = inter_mobius(st, &OBJ[i], pos, dir);
		else if (ft_strcmp(OBJ[i].type, "halfsphere") == 0)
			range = inter_half_sphere(st, &OBJ[i], pos, dir);
		else if (ft_strcmp(OBJ[i].type, "limitcone") == 0)
			range = inter_limit_cone(st, &OBJ[i], pos, dir);
		else
			range = intertwo(i, st, pos, dir);
		if (range > 0.0001 && range < st->t)
			p = fuck_norm(range, st, i);
		i++;
	}
	return (p);
}
