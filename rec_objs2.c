/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_objs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 18:42:01 by drenkas           #+#    #+#             */
/*   Updated: 2017/12/25 18:42:05 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rec_disk(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;
	double	rot[3];

	i = -1;
	obj_fix(st, 7);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	tmp = ft_strsplit(st[4], ',');
	while (++i < 3)
		rot[i] = ft_check_dot(tmp[i]);
	obj->rot.x = rot[0];
	obj->rot.y = rot[1];
	obj->rot.z = rot[2];
	free_split(tmp);
	tmp = ft_strsplit(st[5], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	obj->h = (double)ft_atoi(st[6]);
}

void	rec_par(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;
	double	rot[3];

	i = -1;
	obj_fix(st, 9);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	tmp = ft_strsplit(st[4], ',');
	while (++i < 3)
		rot[i] = ft_check_dot(tmp[i]);
	obj->rot.x = rot[0];
	obj->rot.y = rot[1];
	obj->rot.z = rot[2];
	obj->size = (double)ft_atoi(st[5]);
	free_split(tmp);
	tmp = ft_strsplit(st[6], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	obj->h = (double)ft_atoi(st[7]);
	obj->k = (double)ft_atoi(st[8]);
}

void	rec_trim_cy(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;
	double	rot[3];

	i = -1;
	obj_fix(st, 8);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	tmp = ft_strsplit(st[4], ',');
	while (++i < 3)
		rot[i] = ft_check_dot(tmp[i]);
	obj->rot.x = rot[0];
	obj->rot.y = rot[1];
	obj->rot.z = rot[2];
	obj->size = (double)ft_atoi(st[5]);
	free_split(tmp);
	tmp = ft_strsplit(st[6], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	obj->h = (double)ft_atoi(st[7]);
}

void	rec_tor(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;
	double	rot[3];

	i = -1;
	obj_fix(st, 8);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	tmp = ft_strsplit(st[4], ',');
	while (++i < 3)
		rot[i] = ft_check_dot(tmp[i]);
	obj->rot.x = rot[0];
	obj->rot.y = rot[1];
	obj->rot.z = rot[2];
	obj->size = (double)ft_atoi(st[5]);
	free_split(tmp);
	tmp = ft_strsplit(st[6], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	obj->size2 = (double)ft_atoi(st[7]);
}

void	rec_cube(char **st, t_obj *obj)
{
	char **tmp;

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
