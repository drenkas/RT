/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_4_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:55:39 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 10:55:42 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "menu1.h"

void		solution(t_t *t, double c, double disc, double br)
{
	double	bq3;
	double	n;
	double	a;

	if (disc < 0)
	{
		n = sqrt(t->b);
		bq3 = pow(n, 3);
		if (br / bq3 < 1.0)
			t->beta = acos(br / bq3);
		a = -2 * n;
		t->u[0] = a * cos(t->beta / 3) - c / 3;
		t->u[1] = a * cos((t->beta + 2.0 * M_PI) / 3) - c / 3;
		t->u[2] = a * cos((t->beta - 2.0 * M_PI) / 3) - c / 3;
	}
	else
	{
		n = 1;
		if (br < 0)
			n = -1;
		a = -n * pow(fabs(br) + sqrt(disc), F_T);
		t->u[0] = a + t->b / a - c / 3;
		t->u[1] = -F_S * ((pow(a, 2) + t->b) / a) - c / 3;
		t->u[2] = -(sqrt(3.0) / 2.0) * fabs(a - (t->b / a));
	}
}

void		plus(t_t *t)
{
	double	n;
	double	u;

	t->i = 3;
	n = sqrt(sqrt(t->u[1] * t->u[1] + t->u[2] * t->u[2]));
	u = atan2(t->u[2], t->u[1]);
	t->rial1 = n * cos(u * F_S);
	t->im1 = n * sin(u * F_S);
	t->rial2 = t->rial1;
	t->im2 = -t->im1;
}

double		ft_count_first(t_t *t, double *a, double disc, double aa)
{
	double	pp;
	double	rr;
	double	c;
	double	br;

	aa = a[0] * a[0];
	pp = a[1] - T_E * aa;
	rr = a[3] - F_F * (a[0] * a[2] - F_F * aa * (a[1] - T_S * aa));
	t->q2 = a[2] - F_S * a[0] * (a[1] - F_F * aa);
	c = F_S * pp;
	aa = F_F * (F_F * pp * pp - rr);
	t->b = (pow(c, 2) / 9.0 - aa * F_T);
	br = (pow(c, 3) / 27 - c * aa / 6 - (F_E * t->q2 * F_E * t->q2) / 2);
	disc = ((br * br) - (t->b * t->b * t->b));
	t->beta = 0.0;
	solution(t, c, disc, br);
	return (disc);
}

void		move_objtwo(t_mlx *mlx, int key)
{
	if (key == 92)
	{
		mlx->obj[g_m->i].pos.z += 4;
		start_bitch(mlx);
	}
	else if (key == 85)
	{
		mlx->obj[g_m->i].pos.z -= 4;
		start_bitch(mlx);
	}
	else if (key == 89)
	{
		mlx->obj[g_m->i].size += 2;
		start_bitch(mlx);
	}
	else if (key == 83)
	{
		mlx->obj[g_m->i].size -= 2;
		start_bitch(mlx);
	}
}

void		move_obj(t_mlx *mlx, int key)
{
	if (key == 86)
	{
		mlx->obj[g_m->i].pos.x -= 2;
		start_bitch(mlx);
	}
	else if (key == 88)
	{
		mlx->obj[g_m->i].pos.x += 2;
		start_bitch(mlx);
	}
	else if (key == 91)
	{
		mlx->obj[g_m->i].pos.y += 2;
		start_bitch(mlx);
	}
	else if (key == 84)
	{
		mlx->obj[g_m->i].pos.y -= 2;
		start_bitch(mlx);
	}
	else
		move_objtwo(mlx, key);
}
