/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:06:48 by osyniegu          #+#    #+#             */
/*   Updated: 2017/12/13 16:06:48 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	check_camera(char **st)
{
	g_m->cam = 1;
	if (check_num(st[1], 0) == 1)
		return ;
	if (check_num(st[2], 0) == 1)
		return ;
	if (check_num(st[3], 0) == 1)
		return ;
}

void	check_light(char **st)
{
	if (check_num(st[1], 0) == 1)
		return ;
	if (check_num(st[2], 0) == 1)
		return ;
	if (check_num(st[3], 0) == 1)
		return ;
	if (check_bgr(st[4]) == 1)
		return ;
}

void	check_plane(char **st)
{
	if (check_num(st[1], 0) == 1)
		return ;
	if (check_num(st[2], 0) == 1)
		return ;
	if (check_num(st[3], 0) == 1)
		return ;
	if (check_rot(st[4]) == 1)
		return ;
	if (check_bgr(st[5]) == 1)
		return ;
}

void	check_sphere(char **st)
{
	if (check_num(st[1], 0) == 1)
		return ;
	if (check_num(st[2], 0) == 1)
		return ;
	if (check_num(st[3], 0) == 1)
		return ;
	if (check_num(st[4], 1) == 1)
		return ;
	if (check_bgr(st[5]) == 1)
		return ;
}

void	check_cylinder(char **st)
{
	if (check_num(st[1], 0) == 1)
		return ;
	if (check_num(st[2], 0) == 1)
		return ;
	if (check_num(st[3], 0) == 1)
		return ;
	if (check_rot(st[4]) == 1)
		return ;
	if (check_num(st[5], 1) == 1)
		return ;
	if (check_bgr(st[6]) == 1)
		return ;
}
