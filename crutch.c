/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crutch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 16:03:32 by drenkas           #+#    #+#             */
/*   Updated: 2017/06/22 16:03:33 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	rot_crutch(t_mlx *st, double x, double y)
{
	double	p;
	double	v;
	t_cr	a;
	t_cr	b;
	t_cr	c;

	p = (WIDTH - x * 2) / HIGH;
	v = (HIGH - y * 2) / WIDTH;
	a = vectsub(&(t_cr){0.0, 0.0, -1.0}, &st->cam_pos);
	vectnorm(&a);
	b = vectcross(&a, &(t_cr){0.0, 1.0, 0.0});
	vectnorm(&b);
	c = vectcross(&b, &a);
	st->ray_dir.x = (2 + (st->zoom * 0.01)) * a.x + v * c.x + p * b.x;
	st->ray_dir.y = (2 + (st->zoom * 0.01)) * a.y + v * c.y + p * b.y;
	st->ray_dir.z = (2 + (st->zoom * 0.01)) * a.z + v * c.z + p * b.z;
}

void	arg_norm(char *line, t_mlx *mlx)
{
	mlx->col++;
	if (check_l(line))
		mlx->ct_l++;
}

int		fuck_norm(double range, t_mlx *st, int i)
{
	st->t = range;
	st->tmp = OBJ[i];
	st->put = i;
	return (1);
}

void	crutch_in_crutch(char **st)
{
	if (!(ft_strcmp(st[0], "halfsphere")))
		check_halfsphere(st);
	else if (!(ft_strcmp(st[0], "torus")))
		check_torus(st);
	else if (!(ft_strcmp(st[0], "limitcone")) ||
	!(ft_strcmp(st[0], "trimcyl")))
		check_limitcone(st);
	else if (!(ft_strcmp(st[0], "mobius")))
		check_mobius(st);
	else if (!(ft_strcmp(st[0], "paraboloid")))
		check_paraboloid(st);
	else if (!(ft_strcmp(st[0], "disk")))
		check_disk(st);
	else if (!(ft_strcmp(st[0], "triangle")))
		check_triangle(st);
}

void	obj_fix(char **st, int n)
{
	int i;

	i = 0;
	while (st[i] != NULL)
		i++;
	if (i != n)
		ft_error("INVALID MAP \n");
	g_m->err = 0;
	if (!(ft_strcmp(st[0], "camera")))
		check_camera(st);
	else if (!(ft_strcmp(st[0], "light")))
		check_light(st);
	else if (!(ft_strcmp(st[0], "plane")))
		check_plane(st);
	else if (!(ft_strcmp(st[0], "sphere")) || !(ft_strcmp(st[0], "piramid"))
											|| !(ft_strcmp(st[0], "cube")))
		check_sphere(st);
	else if (!(ft_strcmp(st[0], "cylinder")) || !(ft_strcmp(st[0], "cone")))
		check_cylinder(st);
	else
		crutch_in_crutch(st);
	(g_m->cam != 1) ? g_m->err = 1 : 0;
	if (g_m->err == 1)
		ft_error("INVALID MAP \n");
}
