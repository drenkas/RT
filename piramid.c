/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piramid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:06:14 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:06:16 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		determination_coordinates(t_cr *j, double x, t_cr u)
{
	j[0].x = u.x;
	j[0].y = u.y + x;
	j[0].z = u.z;
	j[1].y = u.y;
	j[2].y = u.y;
	j[3].y = u.y;
	j[4].y = u.y;
	j[1].x = u.x - x;
	j[1].z = u.z + x;
	j[2].x = u.x + x;
	j[2].z = u.z + x;
	j[3].x = u.x + x;
	j[3].z = u.z - x;
	j[4].x = u.x - x;
	j[4].z = u.z - x;
}

void		set_value(t_obj *o, int i, t_cr *j)
{
	if (i == 4)
	{
		o->a = appropriation(j[0].x, j[0].y, j[0].z);
		o->b = appropriation(j[i].x, j[i].y, j[i].z);
		o->c = appropriation(j[1].x, j[1].y, j[1].z);
	}
	else if (i == 5)
	{
		o->a = appropriation(j[2].x, j[2].y, j[2].z);
		o->b = appropriation(j[3].x, j[3].y, j[3].z);
		o->c = appropriation(j[1].x, j[1].y, j[1].z);
	}
	else if (i == 6)
	{
		o->a = appropriation(j[4].x, j[4].y, j[4].z);
		o->b = appropriation(j[3].x, j[3].y, j[3].z);
		o->c = appropriation(j[1].x, j[1].y, j[1].z);
	}
	else
	{
		o->a = appropriation(j[0].x, j[0].y, j[0].z);
		o->b = appropriation(j[i].x, j[i].y, j[i].z);
		o->c = appropriation(j[i + 1].x, j[i + 1].y, j[i + 1].z);
	}
}

double		inter_piramid(t_mlx *st, t_obj *o, t_cr pos, t_cr dir)
{
	t_cr	j[5];
	double	s;
	double	k;
	int		i;
	double	size;

	size = o->size;
	s = -1;
	k = 20000;
	determination_coordinates(j, size, o->pos);
	i = 1;
	while (i < 7)
	{
		set_value(o, i, j);
		s = inter_triangle(st, o, pos, dir);
		if (s > -1 && s < k)
		{
			k = s;
			o->k = i;
		}
		i++;
	}
	return (k);
}

t_cr		ft_pyramid_norm(t_mlx *st)
{
	t_cr	e;

	e = appropriation(0, 0, 1);
	if (st->tmp.k == 1 || st->tmp.k == 3)
		e = appropriation(0.7071, 0.7071, 0);
	else if (st->tmp.k == 2 || st->tmp.k == 4)
		e = appropriation(1, 0, 0);
	return (e);
}

void		rec_piramid(char **st, t_obj *obj)
{
	char	**tmp;

	obj_fix(st, 6);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	obj->size = (double)ft_atoi(st[4]);
	tmp = ft_strsplit(st[5], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
}
