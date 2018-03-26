/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_t.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 17:43:19 by drenkas           #+#    #+#             */
/*   Updated: 2017/05/01 17:43:19 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_ray(t_mlx *st, double x, double y)
{
	double	p;
	double	v;

	p = (2 * ((x + 0.5) / WIDTH) - 1);
	v = (1 - 2 * ((y + 0.5) / HIGH));
	st->ray_dir.x = (double)(p * tan(st->zoom / 2 * M_PI / 180));
	st->ray_dir.y = (double)(v * tan(st->zoom / 2 * M_PI / 180));
	st->ray_dir.z = 1;
	rot_crutch(st, x, y);
	st->count_refl = 0;
	vectnorm(&st->ray_dir);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, float *tab)
{
	int				i;
	unsigned int	p;

	i = 0;
	if (mlx->bnw == 1)
		bnw(tab);
	else if (mlx->sepia == 1)
		sepia(tab);
	p = x * 4 + y * (mlx->s_l);
	mlx->addr[p] = mlx_get_color_value(mlx->mlx_ptr, 255 *
	ft_clamp(tab[0], 0, 1));
	mlx->addr[p + 1] = mlx_get_color_value(mlx->mlx_ptr, 255 *
	ft_clamp(tab[1], 0, 1));
	mlx->addr[p + 2] = mlx_get_color_value(mlx->mlx_ptr, 255 *
	ft_clamp(tab[2], 0, 1));
	free(tab);
}

void	raytrace(t_mlx *st, double x, double y)
{
	float	*color;
	float	sum_tab[3];
	double	count;

	ft_fzero(sum_tab, 3);
	color = (float *)malloc(sizeof(float) * 4);
	count = 0.0;
	while (y < st->old_y + 1 && (x = st->old_x) > -1)
	{
		while (x < st->old_x + 1 && (count += 1) > 0)
		{
			ft_fzero(color, 4);
			create_ray(st, x, y);
			st->tr = 0;
			if (inter(st, st->cam_pos, st->ray_dir))
				color = lamb_light(st, st->cam_pos, st->ray_dir, color);
			sum_color(sum_tab, color);
			x = x + (1.0 / st->anti_al);
		}
		y = y + (1.0 / st->anti_al);
	}
	res_color(sum_tab, count, color);
	ft_put_pixel(st, st->old_x, st->old_y, color);
}

void	start_threads(void *st)
{
	t_thr	*thr;
	double	x;
	double	y;

	thr = (t_thr *)st;
	y = -1;
	x = 0;
	thr->mlx->count = 0;
	while (++y < HIGH)
	{
		if (y == 0 || y == 200 || y == 100 || y == 300 \
			|| y == 700 || y == 400 || y == 600 || y == 799)
			start_loading(thr->mlx);
		x = 0;
		while (x < WIDTH)
		{
			thr->mlx->old_x = (int)x;
			thr->mlx->old_y = (int)y;
			raytrace(thr->mlx, x, y);
			x++;
		}
	}
}
