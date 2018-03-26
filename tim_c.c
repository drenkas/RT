/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tim_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:00:41 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 16:00:44 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

double		kplane(t_obj *o, t_cr p, t_cr dir, t_cr q)
{
	double	d;
	double	t;

	d = vectdot(&dir, &o->rot);
	if (fabs(d) > 0.001)
	{
		t = ((vectdot(&o->rot, &q) - vectdot(&o->rot, &p)) / d);
		return (t);
	}
	return (-1);
}

void		inter_two_light(int i, t_mlx *st, t_cr pos, t_cr dist)
{
	if (ft_strcmp(OBJ[i].type, "piramid") == 0)
		st->dst = inter_piramid(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "halfsphere") == 0)
		st->dst = inter_half_sphere(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "limitcone") == 0)
		st->dst = inter_limit_cone(st, &OBJ[i], pos, dist);
}

double		refl_inter_tri(int i, t_mlx *st, t_cr pos)
{
	double range;

	range = 0;
	if (ft_strcmp(OBJ[i].type, "cube") == 0)
		range = inter_cube(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "piramid") == 0)
		range = inter_piramid(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "torus") == 0)
		range = inter_torus(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "mobius") == 0)
		range = inter_mobius(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "halfsphere") == 0)
		range = inter_half_sphere(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "limitcone") == 0)
		range = inter_limit_cone(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "triangle") == 0)
		range = inter_triangle(st, &OBJ[i], pos, st->refl);
	return (range);
}

double		refr_inter_tri(int i, t_mlx *st, t_cr pos)
{
	double range;

	range = 0;
	if (ft_strcmp(OBJ[i].type, "halfsphere") == 0)
		range = inter_half_sphere(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "limitcone") == 0)
		range = inter_limit_cone(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "triangle") == 0)
		range = inter_triangle(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "cube") == 0)
		range = inter_cube(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "piramid") == 0)
		range = inter_piramid(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "paraboloid") == 0)
		range = inter_paraboloid(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "disk") == 0)
		range = inter_disk(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "torus") == 0)
		range = inter_torus(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "mobius") == 0)
		range = inter_mobius(st, &OBJ[i], pos, st->refr);
	return (range);
}

void		crutch_in_hooks(t_mlx *mlx, int x, int y)
{
	if (x >= 170 && y >= 370 && x <= 240 && y <= 380
			? g_m->p = -8 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 400 && x <= 240 && y <= 410
			? g_m->p = -9 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 430 && x <= 240 && y <= 440
			? g_m->p = -10 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 460 && x <= 240 && y <= 470
			? g_m->p = -11 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
}
