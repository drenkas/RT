/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu1_ad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 22:56:30 by osyniegu          #+#    #+#             */
/*   Updated: 2018/01/11 22:56:31 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	dr_mc_3two(t_mlx *mlx, char **str)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 180, 330, 0xcce6ff, "-");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 210, 330, 0xcce6ff, "+");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 50, 330, 0xcce6ff, "Z");
	str[0] = ft_itoa((int)mlx->cam_pos.z);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 260, 330, 0xcce6ff, str[0]);
	ft_strdel(&str[0]);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 80, 100,
				0xcce6ff, "Anti Aliasing:");
	str[0] = ft_itoa((int)mlx->anti_al);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 310, 100, 0xcce6ff, str[0]);
	ft_strdel(&str[0]);
}

void	dr_mc_3three(t_mlx *mlx, char **str)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 290, 100, 0xcce6ff, ":");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 80, 130,
				0xcce6ff, "Reflection:");
	str[0] = ft_itoa((int)(mlx->percent_refl * 10));
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 310, 130, 0xcce6ff, str[0]);
	ft_strdel(&str[0]);
}

void	dr_mc_3(t_mlx *mlx, char **str)
{
	if (g_m->p == 69)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 330, 0x1874cd, "+");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 330, 0xcce6ff, "+");
	dr_mc_3two(mlx, str);
	if (g_m->p == -10)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 240, 100, 0x1874cd, "-");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 240, 100, 0xcce6ff, "-");
	if (g_m->p == -20)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 270, 100, 0x1874cd, "+");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 270, 100, 0xcce6ff, "+");
	dr_mc_3three(mlx, str);
	if (g_m->p == -120)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 240, 130, 0x1874cd, "-");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 240, 130, 0xcce6ff, "-");
	if (g_m->p == -130)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 270, 130, 0x1874cd, "+");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 270, 130, 0xcce6ff, "+");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 290, 130, 0xcce6ff, ":");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 230, 160, 0xcce6ff, " | ");
}

void	dr_mc_4(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 80, 160, 0xcce6ff, "GLARE:");
	if (mlx->g == 1)
	{
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 260, 160,
					0x1874cd, "ENABLE");
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 160, 160,
					0xcce6ff, "DISABLE");
	}
	else
	{
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 260, 160,
					0xcce6ff, "ENABLE");
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 160, 160,
					0x1874cd, "DISABLE");
	}
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 390,
				0xcce6ff, "CHOOSE SCENE");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 135, 420,
				0xcce6ff, "CHOOSE EFFECT");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 150, 450,
				0xcce6ff, "ADD OBJECT");
}

void	menu1_init(t_mlx *mlx)
{
	g_m->key = 0;
	g_m->l = 0;
	g_m->ch = 0;
	g_m->m = 1;
	g_m->err = 0;
	g_m->ld = (t_ml *)malloc(sizeof(t_ml) * 5);
	g_m->ml = (t_ml *)malloc(sizeof(t_ml) * 5);
	system("afplay music/soundtrack.mp3&");
	g_m->ld[0].h = 170;
	g_m->ld[0].w = 170;
	g_m->ml[1].w = 400;
	g_m->ml[1].h = 800;
	g_m->ml[0].w = 800;
	g_m->ml[0].h = 800;
	g_m->ld[1].img = mlx_xpm_file_to_image(mlx->mlx_ptr, "spin/loading.xpm",
										&g_m->ld[0].w, &g_m->ld[0].h);
	g_m->ld[2].img = mlx_xpm_file_to_image(mlx->mlx_ptr, "spin/loading1.xpm",
										&g_m->ld[0].w, &g_m->ld[0].h);
	g_m->ld[3].img = mlx_xpm_file_to_image(mlx->mlx_ptr, "spin/loading2.xpm",
										&g_m->ld[0].w, &g_m->ld[0].h);
	g_m->ld[4].img = mlx_xpm_file_to_image(mlx->mlx_ptr, "spin/loading.xpm",
										&g_m->ld[0].w, &g_m->ld[0].h);
}
