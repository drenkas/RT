/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coeff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:03:22 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:03:25 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		coef_first(double *coeff, t_coef c, t_cr dir)
{
	double	k;

	k = 2 * dir.z * c.o_x2;
	c.x.k = dir.y * c.o_x2 - k;
	k = 3 * dir.y * c.o_y2;
	c.x.k1 = 2 * dir.x * c.rx.x * c.rx.y + k;
	c.x.k2 = 2 * dir.z * c.o_y2;
	k = 4 * dir.y * c.rx.y * c.rx.z;
	c.x.k3 = 4 * dir.x * c.rx.x * c.rx.z + k;
	k = dir.y * c.o_z2;
	c.x.k4 = 2 * dir.z * c.rx.y * c.rx.z + k;
	k = 2 * dir.x * c.rx.z * c.legth;
	c.x.k5 = 2 * dir.z * c.rx.x * c.legth + k
		+ dir.y * c.legth * c.legth;
	coeff[1] = (c.x.k + c.x.k1 - c.x.k2 - c.x.k3 + c.x.k4 - c.x.k5) / c.c3;
}

void		coef_sec(double *coeff, t_coef c, t_cr dir)
{
	double	d_x2;
	double	d_y2;
	double	d_z2;
	double	k;

	d_x2 = dir.x * dir.x;
	d_y2 = dir.y * dir.y;
	d_z2 = dir.z * dir.z;
	k = 2 * dir.x * dir.y * c.rx.x;
	c.x.k = k - 4 * dir.x * dir.z * c.rx.x;
	k = d_x2 * c.rx.y + 3 * d_y2 * c.rx.y;
	c.x.k1 = k - 4 * dir.y * dir.z * c.rx.y;
	k = d_z2 * c.rx.y - 2 * d_x2 * c.rx.z;
	c.x.k2 = k - 2 * d_y2 * c.rx.z;
	k = 2 * dir.y * dir.z * c.rx.z;
	c.x.k3 = k - 2 * dir.x * dir.z * c.legth;
	coeff[0] = (c.x.k + c.x.k1 + c.x.k2 + c.x.k3) / c.c3;
}

void		coeffs(double *coeff, t_cr pos, t_cr dir)
{
	t_coef c;
	double d_x2;
	double d_y2;
	double d_z2;
	double d_y3;

	c.legth = 1;
	c.rx = appropriation(pos.x, pos.y, pos.z);
	d_x2 = (double)dir.x * (double)dir.x;
	d_y2 = dir.y * dir.y;
	d_z2 = dir.z * dir.z;
	d_y3 = dir.y * dir.y * dir.y;
	c.c3 = d_x2 * dir.y + d_y3 - 2 * d_x2 * dir.z -
		2 * d_y2 * dir.z + dir.y * d_z2;
	c.o_x2 = c.rx.x * c.rx.x;
	c.o_y2 = c.rx.y * c.rx.y;
	c.o_z2 = c.rx.z * c.rx.z;
	coeff[2] = (c.o_x2 * c.rx.y + c.rx.y * c.rx.y * c.rx.y - 2 * c.o_x2
		* c.rx.z - 2 * c.o_y2 * c.rx.z + c.rx.y * c.o_z2 -
		2 * pos.x * pos.z - pos.y) / c.c3;
	coef_first(coeff, c, dir);
	coef_sec(coeff, c, dir);
}
