/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dasha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 02:24:46 by drenkas           #+#    #+#             */
/*   Updated: 2018/01/14 02:24:49 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	*sepia(float *tab)
{
	tab[2] += 112.0 / 255;
	tab[1] += 66.0 / 255;
	tab[0] += 20.0 / 255;
	tab[2] /= 2;
	tab[1] /= 2;
	tab[0] /= 2;
	return (tab);
}

float	*bnw(float *tab)
{
	float filter;

	filter = (tab[2] * .21) + (tab[1] * .72) + (tab[0] * .07);
	tab[2] = filter;
	tab[1] = filter;
	tab[0] = filter;
	return (tab);
}

void	check_dot_rt(char *av)
{
	int	l;

	l = ft_strlen(av);
	if (av[l - 1] != 't' || av[l - 2] != 'r' || av[l - 3] != '.')
		ft_error("Invalid file extension!\n");
}

void	check_disk(char **st)
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
	if (check_num(st[6], 1) == 1)
		return ;
}

void	check_triangle(char **st)
{
	if (check_rot(st[1]) == 1)
		return ;
	if (check_rot(st[2]) == 1)
		return ;
	if (check_rot(st[3]) == 1)
		return ;
	if (check_rot(st[4]) == 1)
		return ;
	if (check_bgr(st[5]) == 1)
		return ;
}
