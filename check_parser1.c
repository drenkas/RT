/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parser1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 22:06:35 by osyniegu          #+#    #+#             */
/*   Updated: 2018/01/11 22:06:35 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

int		check_num(char *st, int f)
{
	int i;

	if (st[0] == '-')
	{
		if (f == 1 ? g_m->err = 1 : 0)
			return (1);
		i = 0;
	}
	else
		i = -1;
	if (i == -1)
		while (st[i + 1] == ' ')
			i++;
	while (st[++i])
		if (st[i] < '0' || st[i] > '9' ? g_m->err = 1 : 0)
			return (1);
	return (0);
}

int		check_bgr(char *st)
{
	int i;
	int c;

	i = -1;
	c = 0;
	if (st[0] < '0' || st[0] > '9' ? g_m->err = 1 : 0)
		return (1);
	while (st[++i])
	{
		if (((st[i] < '0' || st[i] > '9') && st[i] != ',') ? g_m->err = 1 : 0)
			return (1);
		else
		{
			if (st[i] == ',')
			{
				if (i > 0)
					if (st[i - 1] == ',' ? g_m->err = 1 : 0)
						return (1);
				c++;
			}
		}
	}
	if (c != 2 ? g_m->err = 1 : 0)
		return (1);
	return (0);
}

int		check_rot1(char *st, int i, int *c, int *t)
{
	if (st[i] == ',')
	{
		if (i > 0)
			if (st[i - 1] == ',' ? g_m->err = 1 : 0)
				return (1);
		c[0]++;
	}
	else
	{
		if (st[i] == '.')
		{
			if (i > 0)
				if (st[i - 1] == '.' ? g_m->err = 1 : 0)
					return (1);
			t[0]++;
		}
	}
	return (0);
}

int		check_rot2(char *st, int i, int *c, int *t)
{
	while (st[++i])
	{
		if (((st[i] < '0' || st[i] > '9') && st[i] != ','
			&& st[i] != '.' && st[i] != '-') ? g_m->err = 1 : 0)
			return (1);
		else
		{
			if (st[i] == '-')
			{
				if (i > 0 && st[i - 1] == '-' ? g_m->err = 1 : 0)
					return (1);
				else if (st[i - 1] != ',' && i != 0 ? g_m->err = 1 : 0)
					return (1);
			}
			else if (check_rot1(st, i, c, t) == 1)
				return (1);
		}
	}
	if (c[0] != 2 ? g_m->err = 1 : 0)
		return (1);
	return (0);
}

int		check_rot(char *st)
{
	int i;
	int c;
	int t;

	i = -1;
	c = 0;
	t = 0;
	if (((st[0] < '0' || st[0] > '9') && st[0] != '-') ? g_m->err = 1 : 0)
		return (1);
	if (check_rot2(st, i, &c, &t) == 1)
		return (1);
	if (t != 3 ? g_m->err = 1 : 0)
		return (1);
	return (0);
}
