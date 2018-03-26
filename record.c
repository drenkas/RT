/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 19:43:49 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/30 19:43:50 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_check_dot(char *tmp)
{
	double		i;
	double		j;
	double		res;
	char		*ch;
	int			m;

	m = 0;
	if (tmp[0] == '-')
		m += 1;
	ch = (char *)malloc(sizeof(char) * 2 + m);
	ch[0] = tmp[0 + m];
	ch[1] = '\0';
	i = ft_atoi(ch);
	ch[0] = tmp[2 + m];
	j = ft_atoi(ch);
	res = i + j * 0.1;
	if (m == 1)
		res *= -1;
	free(ch);
	return (res);
}

void	free_split(char **st)
{
	int		i;

	i = -1;
	while (st[++i] != NULL)
		free(st[i]);
	free(st);
}

void	rec_obj_two(char **strs, t_obj *obj)
{
	if (ft_strcmp(obj->type, "trimcyl") == 0)
		rec_trim_cy(strs, obj);
	else if (ft_strcmp(obj->type, "cone") == 0)
		rec_co_cy(strs, obj);
	else if (ft_strcmp(obj->type, "torus") == 0)
		rec_tor(strs, obj);
	else if (ft_strcmp(obj->type, "triangle") == 0)
		rec_triangle(strs, obj);
	else if (ft_strcmp(obj->type, "mobius") == 0)
		rec_mobius(strs, obj);
	else if (ft_strcmp(obj->type, "cube") == 0)
		rec_cube(strs, obj);
	else if (ft_strcmp(obj->type, "piramid") == 0)
		rec_piramid(strs, obj);
	else
		ft_error("INVALID MAP \n");
}

void	rec_obj_check(char **strs, t_obj *obj)
{
	if (ft_strcmp(obj->type, "plane") == 0)
		rec_pl(strs, obj);
	else if (ft_strcmp(obj->type, "disk") == 0)
		rec_disk(strs, obj);
	else if (ft_strcmp(obj->type, "sphere") == 0)
		rec_sph(strs, obj);
	else if (ft_strcmp(obj->type, "halfsphere") == 0)
		rec_half_sph(strs, obj);
	else if (ft_strcmp(obj->type, "limitcone") == 0)
		rec_lim_cone(strs, obj);
	else if (ft_strcmp(obj->type, "paraboloid") == 0)
		rec_par(strs, obj);
	else if (ft_strcmp(obj->type, "cylinder") == 0)
		rec_co_cy(strs, obj);
	else
		rec_obj_two(strs, obj);
}

int		record_obj(char *line, t_obj *obj, t_mlx *mlx)
{
	char	**strs;

	if (line == NULL)
		ft_error("INVALID MAP (give me empty line, b*tch) \n");
	strs = ft_strsplit(line, '\t');
	free(line);
	if (ft_strcmp(strs[0], "#info") == 0 ||
	ft_strcmp(strs[0], "camera") == 0 || ft_strcmp(strs[0], "light") == 0)
	{
		if (ft_strcmp(strs[0], "camera") == 0)
			rec_cam(strs, mlx);
		if (ft_strcmp(strs[0], "light") == 0)
			rec_lig(strs, mlx);
		free_split(strs);
		return (0);
	}
	obj->type = ft_strdup(strs[0]);
	rec_obj_check(strs, obj);
	free_split(strs);
	return (1);
}
