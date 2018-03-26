/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 20:53:35 by osyniegu          #+#    #+#             */
/*   Updated: 2018/01/14 20:53:35 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	check_halfsphere(char **st)
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

void	check_torus(char **st)
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
	if (check_num(st[7], 1) == 1)
		return ;
}

void	check_limitcone(char **st)
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
	if (check_num(st[7], 1) == 1)
		return ;
}

void	check_mobius(char **st)
{
	if (check_num(st[1], 0) == 1)
		return ;
	if (check_num(st[2], 0) == 1)
		return ;
	if (check_num(st[3], 0) == 1)
		return ;
	if (check_bgr(st[5]) == 1)
		return ;
}

void	check_paraboloid(char **st)
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
	if (check_num(st[7], 1) == 1)
		return ;
	if (check_num(st[8], 1) == 1)
		return ;
}
