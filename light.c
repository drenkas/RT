/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 17:16:13 by drenkas           #+#    #+#             */
/*   Updated: 2017/05/14 17:16:13 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_pos(t_cr *ps, t_mlx *st, t_cr p, t_cr dr)
{
	ps->x = p.x + st->t * dr.x;
	ps->y = p.y + st->t * dr.y;
	ps->z = p.z + st->t * dr.z;
}

void	l_norm(t_mlx *st, t_cr dist, t_cr pos, int i)
{
	if (ft_strcmp(OBJ[i].type, "sphere") == 0)
		st->dst = inter_sphere(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "plane") == 0)
		st->dst = inter_plane(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "cylinder") == 0)
		st->dst = inter_cylinder(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "cone") == 0)
		st->dst = inter_cone(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "trimcyl") == 0)
		st->dst = inter_trimmed_cylinder(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "paraboloid") == 0)
		st->dst = inter_paraboloid(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "disk") == 0)
		st->dst = inter_disk(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "torus") == 0)
		st->dst = inter_torus(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "triangle") == 0)
		st->dst = inter_triangle(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "mobius") == 0)
		st->dst = inter_mobius(st, &OBJ[i], pos, dist);
	else if (ft_strcmp(OBJ[i].type, "cube") == 0)
		st->dst = inter_cube(st, &OBJ[i], pos, dist);
	else
		inter_two_light(i, st, pos, dist);
}

int		ft_shadow(t_mlx *st, t_obj lgh, t_cr pos, int put)
{
	t_cr	dist;
	double	pzdc;
	int		i;

	i = -1;
	dist = vectsub(&lgh.pos, &pos);
	pzdc = sqrtf(vectdot(&dist, &dist));
	vectnorm(&dist);
	st->save_dist = dist;
	while (++i < st->col)
	{
		if (i != put)
		{
			l_norm(st, dist, pos, i);
			if ((st->dst > 0.001) && (st->dst < pzdc))
			{
				st->tr = 1;
				return (1);
			}
		}
	}
	return (0);
}

float	*lambtwo(t_mlx *st, float *tab, t_cr dr, t_cr pos)
{
	if (st->percent_refl != 0.0)
	{
		st->put_ref = st->put;
		st->pos_refl = (t_cr){dr.x, dr.y, dr.z};
		tab = ft_strcmp(st->tmp.type, "plane")\
		!= 0 ? tab : reflect(st, &pos, tab);
	}
	st->put_ref = st->put;
	st->pos_refr = (t_cr){dr.x, dr.y, dr.z};
	tab = ft_strcmp(st->tmp.type,
	"sphere") != 0 ? tab : refract(st, &pos, tab);
	return (tab);
}

float	*lamb_light(t_mlx *st, t_cr p, t_cr dr, float *tab)
{
	t_cr	pos;
	t_cr	range;
	float	xyu;
	int		i;

	i = 0;
	ft_pos(&pos, st, p, dr);
	st->norm = normalize(st, pos, st->tmp);
	while (i < st->ct_l)
	{
		tab[3] = 0.45;
		range = vectsub(&st->lgh[i].pos, &pos);
		xyu = ft_clamp((1 / sqrtf(sqrtf(vectdot(&range, &range)))), 0.0, 1.0);
		vectnorm(&range);
		if (ft_shadow(st, st->lgh[i], pos, st->put) == 0)
			tab[3] += ft_clamp(vectdot(&range, &st->norm), 0.0, 1.0);
		tab[3] = ft_clamp(tab[3] * 4 * xyu, 0.0, 1.0);
		tab[0] += tab[3] * (st->tmp.col.x / 255) * (st->lgh[i].col.x / 255);
		tab[1] += tab[3] * (st->tmp.col.y / 255) * (st->lgh[i].col.y / 255);
		tab[2] += tab[3] * (st->tmp.col.z / 255) * (st->lgh[i].col.z / 255);
		if (st->g == 1 && st->tr == 0 && ft_strcmp(st->tmp.type, "plane") != 0)
			tab = ft_glare(st, tab, range);
		i++;
	}
	return (lambtwo(st, tab, dr, pos));
}
