/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:05:20 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:05:26 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		*ft_sort(double *u, double *q)
{
	if (fabs(u[0]) > fabs(u[1]) && fabs(u[0]) > fabs(u[2]))
	{
		q[0] = u[0];
		q[1] = fabs(u[1]) > fabs(u[2]) ? u[1] : u[2];
	}
	else if (fabs(u[1]) > fabs(u[0]) && fabs(u[1]) > fabs(u[2]))
	{
		q[0] = u[1];
		q[1] = fabs(u[0]) > fabs(u[2]) ? u[0] : u[2];
	}
	else
	{
		q[0] = u[2];
		q[1] = fabs(u[0]) > fabs(u[1]) ? u[0] : u[1];
	}
	return (q);
}

void		minus(t_t *t, double *l)
{
	t->i = 2;
	ft_sort(t->u, l);
	if (l[0] >= 0.0)
	{
		t->rial1 = sqrt(l[0]);
		t->im1 = 0.0;
	}
	else
	{
		t->im1 = sqrt(-l[0]);
		t->rial1 = 0.0;
	}
	if (l[1] >= 0.0)
	{
		t->im2 = 0.0;
		t->rial2 = sqrt(l[1]);
	}
	else
	{
		t->rial2 = 0.0;
		t->im2 = sqrt(-l[1]);
	}
}

int			ft_coef(t_t *t, double *r, double h, double *l)
{
	double	res;
	double	im_re1;
	double	im_re2;
	double	komp;

	im_re1 = t->im1 * t->im1 + t->rial1 * t->rial1;
	im_re2 = t->im2 * t->im2 + t->rial2 * t->rial2;
	komp = t->im1 * t->im2 - t->rial1 * t->rial2;
	res = t->q2 * F_E * komp / im_re1 / im_re2;
	r[0] = t->rial1 + t->rial2 + res - h;
	r[1] = -t->rial1 - t->rial2 + res - h;
	r[2] = -t->rial1 + t->rial2 - res - h;
	r[3] = t->rial1 - t->rial2 - res - h;
	if (t->i == 2 && l[0] >= 0 && l[1] >= 0)
		return (4);
	else if (t->i == 2)
		return (0);
	else
	{
		r[2] = -1;
		r[3] = 0;
	}
	return (2);
}

int			start(t_t *t, double *a, double *r)
{
	double	disc;
	double	l[2];
	double	h;

	disc = 0.0;
	disc = ft_count_first(t, a, disc, 0.0);
	h = a[0] * F_F;
	if (disc < 0)
		minus(t, l);
	else
		plus(t);
	return (ft_coef(t, r, h, l));
}

int			equation_of_degree_4(double *a, double *r)
{
	t_t t;
	int ans;

	ans = start(&t, a, r);
	return (ans);
}
