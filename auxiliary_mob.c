/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_mob.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:03:03 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:03:07 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "menu1.h"

t_cr		ft_norm_mobius(t_cr p)
{
	t_cr ret;

	ret.x = 2.0 * p.x * p.y - 2.0 * p.z - 4.0 * p.x * p.z;
	ret.y = -1 + p.x * p.x + 3.0 * p.y * p.y - 4.0 * p.y * p.z + p.z * p.z;
	ret.z = -2.0 * p.x - 2.0 * p.x * p.x - 2.0 * p.y * p.y + 2.0 * p.y * p.z;
	return (ret);
}

int			calculation_coefficients(double *qa, double *s, double q, double r)
{
	double	beta;
	double	ba;
	int		n;

	q = (qa[0] * qa[0] - 3 * qa[1]) / 9;
	r = (2 * pow(qa[0], 3) - 9 * qa[0] * qa[1] + 27 * qa[2]) / 54;
	n = -1;
	if (r >= 0)
		n = 1;
	if (pow(r, 2) < pow(q, 3))
	{
		beta = acos(n * sqrt(pow(r, 2) / pow(q, 3)));
		s[0] = -2 * sqrt(q) * cos(beta * F_T) - qa[0] * F_T;
		s[1] = -2 * sqrt(q) * cos((beta + 2.0 * M_PI) * F_T) - qa[0] * F_T;
		s[2] = -2 * sqrt(q) * cos((beta - 2.0 * M_PI) * F_T) - qa[0] * F_T;
		return (3);
	}
	else
	{
		ba = -n * pow(fabs(r) + sqrt(pow(r, 2) - pow(q, 3)), F_T);
		s[0] = ba + (q / ba) - qa[0] / 3;
		return (1);
	}
	return (0);
}

void		gm_ch_3(t_mlx *mlx, int x, int y)
{
	g_m->obj = 0;
	if (x >= 170 && y >= 710 && x <= 210 && y <= 720 ? g_m->p = 5 : 0)
	{
		g_m->ch = 0;
		back(mlx);
	}
	else if (x >= 170 && y >= 280 && x <= 240 && y <= 290
			? g_m->p = -7 : 0)
	{
		g_m->ch = 0;
		g_m->obj = 1;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 310 && x <= 240 && y <= 320
			? g_m->p = -7 : 0)
	{
		g_m->ch = 0;
		g_m->obj = 2;
		start_scene(mlx);
	}
}

void		gm_ch(t_mlx *mlx, int x, int y)
{
	if (g_m->ch == 0)
	{
		gm_ch_0(mlx, x, y);
		if (x >= 180 && y >= 520 && x <= 220 && y <= 530 ? g_m->p = 3 : 0)
			ft_exit(mlx);
		else if (x >= 135 && y >= 430 && x <= 265 && y <= 440 ? g_m->p = 4 : 0)
			choose_effect(mlx);
		else if (x >= 190 && y >= 740 && x <= 200 && y <= 750
			&& g_m->m == 1 ? g_m->m = 3 : 0)
			play_music(mlx);
		else if (x >= 190 && y >= 740 && x <= 200 && y <= 750
				&& g_m->m == 3 ? g_m->m = 1 : 0)
			play_music(mlx);
	}
	else if (g_m->ch == 1)
	{
		gm_ch_1(mlx, x, y);
		gm_ch_12(mlx, x, y);
	}
}
