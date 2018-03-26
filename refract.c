/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:01:20 by drenkas           #+#    #+#             */
/*   Updated: 2017/12/10 19:01:24 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				refr_inter_two(t_mlx *st, int i, t_cr pos, int p)
{
	double range;

	range = 0;
	if (ft_strcmp(OBJ[i].type, "sphere") == 0)
		range = inter_sphere(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "plane") == 0)
		range = inter_plane(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "cylinder") == 0)
		range = inter_cylinder(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "cone") == 0)
		range = inter_cone(st, &OBJ[i], pos, st->refr);
	else if (ft_strcmp(OBJ[i].type, "trimcyl") == 0)
		range = inter_trimmed_cylinder(st, &OBJ[i], pos, st->refr);
	else
		range = refl_inter_tri(i, st, pos);
	if (range > 0.0001 && range < st->t)
	{
		st->t = range;
		st->tmp_ref = OBJ[i];
		st->put_ref = i;
		p = 1;
	}
	return (p);
}

static int		refr_inter(t_mlx *st, int put, t_cr pos)
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
			p = refr_inter_two(st, i, pos, p);
		}
	}
	return (p);
}

static int		init_refr(t_mlx *st, t_cr *pos)
{
	st->n1 = 1.0;
	st->t = 8000;
	st->refr = vectadd(vectscale(&st->pos_refr, st->n1 / st->percent_refr),
	vectscale(&st->norm, (st->n1 / st->percent_refr)\
		* (-vectdot(&st->pos_refr, &st->norm))
	- sqrtf(1 - (powf(st->n1 / st->percent_refr, 2) * (1 -
	powf(vectdot(&st->pos_refr, &st->norm), 2))))));
	if (refr_inter(st, st->put_ref, *pos) == 0)
		return (0);
	ft_pos(pos, st, *pos, st->refr);
	st->pos_refr = (t_cr){st->refr.x, st->refr.y, st->refr.z};
	st->norm = normalize(st, *pos, st->tmp_ref);
	return (1);
}

float			*refract(t_mlx *st, t_cr *pos, float *tab)
{
	t_cr	range;
	float	x;
	int		i;

	i = 0;
	if (init_refr(st, pos) == 0)
		return (tab);
	while (i < st->ct_l)
	{
		tab[3] = 0.1;
		range = vectsub(&st->lgh[i].pos, pos);
		x = ft_clamp((1 / sqrtf(sqrtf(vectdot(&range, &range)))), 0.0, 1.0);
		vectnorm(&range);
		if (ft_shadow(st, st->lgh[i], *pos, st->put_ref) == 0)
			tab[3] += ft_clamp(vectdot(&range, &st->norm), 0.0, 1.0);
		tab[3] = ft_clamp(tab[3] * 4 * x, 0.0, 1.0);
		tab[0] += tab[3] * (st->tmp_ref.col.x * st->percent_refr / 255);
		tab[1] += tab[3] * (st->tmp_ref.col.y * st->percent_refr / 255);
		tab[2] += tab[3] * (st->tmp_ref.col.z * st->percent_refr / 255);
		if (st->g == 1 && st->tr == 0 && \
			ft_strcmp(st->tmp_ref.type, "plane") != 0)
			tab = ft_glare(st, tab, range);
		i++;
	}
	return (tab);
}

void			hooks_refr(t_mlx *s, int code)
{
	if (s->percent_refr == 0.0)
		s->percent_refr = 1.0;
	else if (s->percent_refr == 1.0)
		s->percent_refr = 0.0;
	s->code = code;
	start_bitch(s);
}
