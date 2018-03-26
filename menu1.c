/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:32:30 by osyniegu          #+#    #+#             */
/*   Updated: 2017/12/05 17:32:30 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

t_m *g_m;

void	draw_background(void)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++j < g_m->ml[1].h)
	{
		while (++i < g_m->ml[1].w)
		{
			g_m->ml[0].addr[i * g_m->ml[0].bpp / 8 + j
				* g_m->ml[0].sl] = g_m->ml[1].addr[i * g_m->ml[1].bpp
				/ 8 + j * g_m->ml[1].sl];
			g_m->ml[0].addr[i * g_m->ml[0].bpp / 8 + j
				* g_m->ml[0].sl + 1] = g_m->ml[1].addr[i * g_m->ml[1].bpp
				/ 8 + j * g_m->ml[1].sl + 1];
			g_m->ml[0].addr[i * g_m->ml[0].bpp / 8 + j
				* g_m->ml[0].sl + 2] = g_m->ml[1].addr[i * g_m->ml[1].bpp
				/ 8 + j * g_m->ml[1].sl + 2];
			g_m->ml[0].addr[i * g_m->ml[0].bpp / 8
				+ j * g_m->ml[0].sl + 3] = 110;
		}
		i = -1;
	}
}

void	draw_mcontent(t_mlx *mlx)
{
	char	*str;
	char	*str1;

	dr_mc_1(mlx, &str, &str1);
	dr_mc_2(mlx, &str);
	dr_mc_3(mlx, &str);
	dr_mc_4(mlx);
	if (g_m->p == 1)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 150, 480,
					0x1874cd, "SCREENSHOT");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 150, 480,
					0xcce6ff, "SCREENSHOT");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 180, 510, 0xcce6ff, "EXIT");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 700, 0xcce6ff, "MUSIC");
	if (g_m->m != 1)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 190, 730, 0xcce6ff, ">");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 185, 730, 0xcce6ff, "||");
}

void	draw_menu(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, g_m->ml[0].img);
	mlx_destroy_image(mlx->mlx_ptr, g_m->ml[1].img);
	mlx_clear_window(mlx->mlx_ptr, g_m->ml[0].win);
	g_m->ml[0].img = mlx_new_image(mlx->mlx_ptr, g_m->ml[1].w, g_m->ml[1].h);
	g_m->ml[1].img = mlx_xpm_file_to_image(mlx->mlx_ptr, "1.xpm",
										&g_m->ml[1].w, &g_m->ml[1].h);
	g_m->ml[1].addr = mlx_get_data_addr(g_m->ml[1].img, &g_m->ml[1].bpp,
										&g_m->ml[1].sl, &g_m->ml[1].en);
	g_m->ml[0].addr = mlx_get_data_addr(g_m->ml[0].img, &g_m->ml[0].bpp,
										&g_m->ml[0].sl, &g_m->ml[0].en);
	draw_background();
	mlx_put_image_to_window(mlx->mlx_ptr, g_m->ml[0].win, g_m->ml[0].img, 0, 0);
	if (g_m->ch == 0)
		draw_mcontent(mlx);
	else if (g_m->ch == 1)
		draw_ccontent(mlx);
	else if (g_m->ch == 2)
		draw_econtent(mlx);
	else if (g_m->ch == 3)
		draw_ocontent(mlx);
	mlx_hook(g_m->ml[0].win, 2, 3, hooks1, mlx);
	mlx_hook(g_m->ml[0].win, 17, (1L << 17), ft_exit, mlx);
	mlx_mouse_hook(g_m->ml[0].win, mouse_hook1, mlx);
}

void	start_loading(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_prt,
							g_m->ld[0].img, 0, 0);
	if (g_m->l == 3)
		g_m->l = 1;
	else
		g_m->l++;
	load_spin(mlx);
	mlx_do_sync(mlx->mlx_ptr);
}

void	menu1(t_mlx *mlx)
{
	menu1_init(mlx);
	g_m->ld[4].addr = mlx_get_data_addr(g_m->ld[4].img, &g_m->ld[0].bpp,
										&g_m->ld[0].sl, &g_m->ld[0].en);
	g_m->ml[0].win = mlx_new_window(mlx->mlx_ptr, g_m->ml[1].w,
									g_m->ml[1].h, "menu");
	g_m->ml[1].img = mlx_xpm_file_to_image(mlx->mlx_ptr, "1.xpm",
										&g_m->ml[1].w, &g_m->ml[1].h);
	g_m->ml[0].img = mlx_new_image(mlx->mlx_ptr, g_m->ml[1].w, g_m->ml[1].h);
	draw_menu(mlx);
}
