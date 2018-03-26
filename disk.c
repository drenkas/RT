/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:04:50 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/13 14:04:53 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "menu1.h"

double	iplane(t_mlx *st, t_obj *o, t_cr p, t_cr dir)
{
	double	d;

	d = vectdot(&dir, &o->rot);
	if (fabs(d) > 0.001)
	{
		st->t0 = ((vectdot(&o->rot, &o->pos) - vectdot(&o->rot, &p)) / d);
		return (st->t0);
	}
	return (-1);
}

void	start_bitchtwo(t_mlx *mlx)
{
	t_thr		thread[1];

	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_prt);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGH);
	thread[0].id = 0;
	thread[0].mlx = mlx;
	start_threads(&thread[0]);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_prt, mlx->img, 0, 0);
	show_hub(mlx);
	if (mlx->hub_ch == 1)
		ft_menu(mlx);
}

void	start_bitch(t_mlx *mlx)
{
	int			j;

	j = -1;
	mlx->i = -1;
	mlx_destroy_image(mlx->mlx_ptr, g_m->ld[0].img);
	g_m->ld[0].img = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGH);
	g_m->ld[0].addr = mlx_get_data_addr(g_m->ld[0].img,\
		&g_m->ld[0].bpp, &g_m->ld[0].sl, &g_m->ld[0].en);
	while (++j < HIGH)
	{
		while (++mlx->i < WIDTH)
		{
			g_m->ld[0].addr[mlx->i * g_m->ld[0].bpp / 8 + j \
				* g_m->ld[0].sl] = mlx->addr[mlx->i \
				* mlx->bpp / 8 + j * mlx->s_l];
			g_m->ld[0].addr[mlx->i * g_m->ld[0].bpp / 8 + j\
				* g_m->ld[0].sl + 1] = mlx->addr[mlx->i \
				* mlx->bpp / 8 + j * mlx->s_l + 1];
			g_m->ld[0].addr[mlx->i * g_m->ld[0].bpp / 8 + j\
				* g_m->ld[0].sl + 2] = mlx->addr[mlx->i *\
				mlx->bpp / 8 + j * mlx->s_l + 2];
		}
		mlx->i = -1;
	}
	start_bitchtwo(mlx);
}
