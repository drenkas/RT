/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:51:43 by drenkas           #+#    #+#             */
/*   Updated: 2017/05/05 17:51:44 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cr	normalizetwo(t_cr norm, t_mlx *st, t_cr pos, t_obj temp)
{
	if (ft_strcmp(temp.type, "torus") == 0)
		norm = ft_normal_tor(st, pos);
	if (ft_strcmp(temp.type, "mobius") == 0)
		norm = ft_norm_mobius(pos);
	if (ft_strcmp(temp.type, "cube") == 0)
		norm = ft_cubenorm(st, pos);
	if (ft_strcmp(temp.type, "piramid") == 0)
		norm = ft_pyramid_norm(st);
	if (ft_strcmp(temp.type, "paraboloid") == 0)
		norm = ft_paraboloid_n(st, pos);
	if (ft_strcmp(temp.type, "halfsphere") == 0)
	{
		norm = vectsub(&pos, &temp.pos);
		if (st->tmp.k == 5)
		{
			norm.x = -1;
			norm.y = 0;
			norm.z = 0;
		}
	}
	vectnorm(&norm);
	return (norm);
}

t_cr	normalize(t_mlx *st, t_cr pos, t_obj temp)
{
	t_cr	norm;
	t_cr	tmp;
	t_cr	tmp2;

	if (ft_strcmp(temp.type, "sphere") == 0)
		norm = vectsub(&pos, &temp.pos);
	else if (ft_strcmp(temp.type, "plane") == 0 ||
	ft_strcmp(temp.type, "disk") == 0 || ft_strcmp(temp.type, "triangle") == 0)
		norm = temp.rot;
	if (ft_strcmp(temp.type, "cylinder") == 0 ||
	ft_strcmp(temp.type, "cone") == 0 ||
	ft_strcmp(temp.type, "limitcone") == 0 ||
	ft_strcmp(temp.type, "trimcyl") == 0)
	{
		tmp = vectscale(&temp.rot, (vectdot(&st->ray_dir, &temp.rot)
		* st->t + vectdot(&st->dist, &temp.rot)));
		if (ft_strcmp(temp.type, "cone") == 0)
			tmp = vectscale(&tmp, (1 + (temp.size * 0.01)));
		tmp2 = vectsub(&pos, &temp.pos);
		norm = vectsub(&tmp2, &tmp);
		if (st->tmp.k == 8)
			norm = temp.rot;
	}
	return (normalizetwo(norm, st, pos, temp));
}

void	ft_fzero(float *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0.0;
		i++;
	}
}

t_cr	vectcross(t_cr *v1, t_cr *v2)
{
	t_cr	res;

	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	return (res);
}

t_cr	vectsub(t_cr *v1, t_cr *v2)
{
	t_cr	sub;

	sub.x = v1->x - v2->x;
	sub.y = v1->y - v2->y;
	sub.z = v1->z - v2->z;
	return (sub);
}
