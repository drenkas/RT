/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:31:04 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 11:31:07 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cr		ft_normal_tor(t_mlx *st, t_cr pos)
{
	t_cr	cent;
	double	k;
	t_cr	a;

	cent = vectsub(&pos, &st->tmp.pos);
	k = vectdot(&st->tmp.rot, &cent);
	a = vectscale(&st->tmp.rot, k);
	a = vectsub(&cent, &a);
	k = vectdot(&a, &a);
	k = 1 / sqrt(k) * st->tmp.size2;
	cent.x = pos.x - a.x - (st->tmp.pos.x - a.x) * k / (st->tmp.size2 + k);
	cent.y = pos.y - a.y - (st->tmp.pos.y - a.y) * k / (st->tmp.size2 + k);
	cent.z = pos.z - a.z - (st->tmp.pos.z - a.z) * k / (st->tmp.size2 + k);
	return (cent);
}

void		ft_discr(t_obj *obj, t_cr pos, t_cr dir, double *u)
{
	t_cr	x;
	double	qq[4];
	double	q;
	double	r2;

	x = vectsub(&pos, &obj->pos);
	vectnorm(&obj->rot);
	r2 = pow(obj->size2, 2);
	q = vectdot(&x, &obj->rot);
	qq[0] = 1 - pow(vectdot(&dir, &obj->rot), 2);
	qq[1] = vectdot(&dir, &x);
	qq[1] = 2 * (qq[1] - q * vectdot(&dir, &obj->rot));
	qq[2] = vectdot(&x, &x) - q * q;
	qq[3] = vectdot(&x, &x) + r2 - pow(obj->size, 2);
	u[0] = 4 * vectdot(&x, &dir);
	u[1] = 2 * qq[3] + u[0] * u[0] * 0.25 - 4 * r2 * qq[0];
	u[2] = u[0] * qq[3] - 4 * r2 * qq[1];
	u[3] = qq[3] * qq[3] - 4 * r2 * qq[2];
}

void		hook_refl(t_mlx *st, int key)
{
	if (key == 12)
	{
		if (st->percent_refl > 0.0)
		{
			st->percent_refl -= 0.1;
			draw_menu(st);
			start_bitch(st);
		}
	}
	else if (key == 13)
	{
		if (st->percent_refl < 1.0)
		{
			st->percent_refl += 0.1;
			draw_menu(st);
			start_bitch(st);
		}
	}
}

int			check_l(char *line)
{
	char	**strs;
	int		i;

	i = -1;
	if (ft_strcmp(line, "\0") == 0)
		ft_error("INVALID MAP \n");
	strs = ft_strsplit(line, '\t');
	if (ft_strcmp(strs[0], "light") == 0)
	{
		free_split(strs);
		return (1);
	}
	free_split(strs);
	return (0);
}
