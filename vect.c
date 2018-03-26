/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:40:23 by drenkas           #+#    #+#             */
/*   Updated: 2017/05/05 16:40:24 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cr	vectscale(t_cr *v, double n)
{
	t_cr vec;

	vec.x = v->x * n;
	vec.y = v->y * n;
	vec.z = v->z * n;
	return (vec);
}

t_cr	vectadd(t_cr a, t_cr b)
{
	t_cr k;

	k.x = a.x + b.x;
	k.y = a.y + b.y;
	k.z = a.z + b.z;
	return (k);
}

double	vectdot(t_cr *v1, t_cr *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

void	vectnorm(t_cr *v)
{
	double	n;

	n = 1.0 / sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

float	ft_clamp(float v, float min, float max)
{
	if (v < min)
		v = min;
	if (v > max)
		v = max;
	return (v);
}
