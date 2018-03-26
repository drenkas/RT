/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rec_objs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 20:42:50 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/30 20:42:51 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rec_cam(char **st, t_mlx *obj)
{
	obj_fix(st, 4);
	obj->cam_pos.x = (double)ft_atoi(st[1]);
	obj->cam_pos.y = (double)ft_atoi(st[2]);
	obj->cam_pos.z = (double)ft_atoi(st[3]);
	obj->cam_dir.x = 0.0;
	obj->cam_dir.y = 0.0;
	obj->cam_dir.z = 0.0;
}

void	rec_lig(char **st, t_mlx *mlx)
{
	char **tmp;

	obj_fix(st, 5);
	mlx->lgh[mlx->ct_l].pos.x = (double)ft_atoi(st[1]);
	mlx->lgh[mlx->ct_l].pos.y = (double)ft_atoi(st[2]);
	mlx->lgh[mlx->ct_l].pos.z = (double)ft_atoi(st[3]);
	tmp = ft_strsplit(st[4], ',');
	mlx->lgh[mlx->ct_l].col.x = (double)ft_atoi(tmp[0]);
	mlx->lgh[mlx->ct_l].col.y = (double)ft_atoi(tmp[1]);
	mlx->lgh[mlx->ct_l].col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
	mlx->ct_l++;
}

void	rec_pl(char **st, t_obj *obj)
{
	char	**tmp;
	int		i;
	double	rot[3];

	i = -1;
	obj_fix(st, 6);
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
}

void	rec_sph(char **st, t_obj *obj)
{
	char **tmp;

	obj_fix(st, 6);
	obj->pos.x = (double)ft_atoi(st[1]);
	obj->pos.y = (double)ft_atoi(st[2]);
	obj->pos.z = (double)ft_atoi(st[3]);
	obj->size = (double)ft_atoi(st[4]);
	if (obj->size <= 0)
		ft_error("INVALID MAP \n");
	tmp = ft_strsplit(st[5], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
}

void	rec_co_cy(char **st, t_obj *obj)
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
	obj->size = (double)ft_atoi(st[5]);
	if (obj->size <= 0)
		ft_error("INVALID MAP \n");
	free_split(tmp);
	tmp = ft_strsplit(st[6], ',');
	obj->col.x = (double)ft_atoi(tmp[0]);
	obj->col.y = (double)ft_atoi(tmp[1]);
	obj->col.z = (double)ft_atoi(tmp[2]);
	free_split(tmp);
}
