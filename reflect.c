/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:08:15 by drenkas           #+#    #+#             */
/*   Updated: 2017/12/02 19:08:19 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			refl_inter_two(t_mlx *st, t_cr pos, int i)
{
	double range;

	range = 0;
	if (ft_strcmp(OBJ[i].type, "sphere") == 0)
		range = inter_sphere(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "plane") == 0)
		range = inter_plane(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "cylinder") == 0)
		range = inter_cylinder(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "cone") == 0)
		range = inter_cone(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "trimcyl") == 0)
		range = inter_trimmed_cylinder(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "paraboloid") == 0)
		range = inter_paraboloid(st, &OBJ[i], pos, st->refl);
	else if (ft_strcmp(OBJ[i].type, "disk") == 0)
		range = inter_disk(st, &OBJ[i], pos, st->refl);
	else
		range = refl_inter_tri(i, st, pos);
	return (range);
}

static int		refl_inter(t_mlx *st, int put, t_cr pos)
{
	int		i;
	double	range;
	int		p;

	i = -1;
	range = 0;
	p = 0;
	while (++i < st->col)
	{
		if (i != put)
		{
			range = refl_inter_two(st, pos, i);
			if (range > 0.0001 && range < st->t)
			{
				st->t = range;
				st->tmp_ref = OBJ[i];
				st->put_ref = i;
				p = 1;
			}
		}
	}
	return (p);
}

static int		init_refl(t_mlx *st, t_cr *pos)
{
	st->t = 8000.0;
	st->refl = vectscale(&st->norm, (2 * vectdot(&st->pos_refl, &st->norm)));
	st->refl = vectsub(&st->pos_refl, &st->refl);
	vectnorm(&st->refl);
	if (refl_inter(st, st->put_ref, *pos) == 0)
		return (0);
	ft_pos(pos, st, *pos, st->refl);
	st->pos_refl = (t_cr){st->refl.x, st->refl.y, st->refl.z};
	st->norm = normalize(st, *pos, st->tmp_ref);
	return (1);
}

float			*reflecttwo(t_mlx *st, float *tab, float x)
{
	tab[3] = ft_clamp(tab[3] * 4 * x, 0.0, 1.0);
	tab[0] += tab[3] * (st->tmp_ref.col.x * st->percent_refl / 255);
	tab[1] += tab[3] * (st->tmp_ref.col.y * st->percent_refl / 255);
	tab[2] += tab[3] * (st->tmp_ref.col.z * st->percent_refl / 255);
	return (tab);
}

float			*reflect(t_mlx *st, t_cr *pos, float *tab)
{
	t_cr	range;
	float	x;
	int		i;

	i = 0;
	if (init_refl(st, pos) == 0 || st->count_refl >= 1)
		return (tab);
	st->count_refl++;
	while (i < st->ct_l)
	{
		tab[3] = 0.1;
		range = vectsub(&st->lgh[i].pos, pos);
		x = ft_clamp((1 / sqrtf(sqrtf(vectdot(&range, &range)))), 0.0, 1.0);
		vectnorm(&range);
		if (ft_shadow(st, st->lgh[i], *pos, st->put_ref) == 0)
			tab[3] += ft_clamp(vectdot(&range, &st->norm), 0.0, 1.0);
		reflecttwo(st, tab, x);
		if (st->g == 1 && st->tr == 0 && \
			ft_strcmp(st->tmp_ref.type, "plane") != 0)
			tab = ft_glare(st, tab, range);
		i++;
	}
	return (ft_strcmp(st->tmp_ref.type, "disk") \
		!= 0 ? tab : reflect(st, pos, tab));
}
