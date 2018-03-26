/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:35:36 by osyniegu          #+#    #+#             */
/*   Updated: 2017/12/05 17:35:37 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU1_H
# define MENU1_H

# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "rtv1.h"

typedef struct	s_ml
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			sl;
	int			en;
	int			w;
	int			h;
}				t_ml;

typedef struct	s_m
{
	t_ml		*ml;
	t_ml		*ld;
	int			t;
	int			l;
	char		*av;
	int			key;
	int			glare;
	int			p;
	int			m;
	int			cam;
	int			err;
	int			obj;
	int			ch;
	int			col;
	int			ct_l;
	double		fuck;
	int			i;
	int			oldt;
	int			aa;
}				t_m;

extern t_m		*g_m;

#endif
