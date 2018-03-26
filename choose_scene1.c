/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_scene1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 22:14:00 by osyniegu          #+#    #+#             */
/*   Updated: 2018/01/11 22:14:00 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	draw_ccontent(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 180, 0xcce6ff, "SCENE 1");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 210, 0xcce6ff, "SCENE 2");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 240, 0xcce6ff, "SCENE 3");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 270, 0xcce6ff, "SCENE 4");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 300, 0xcce6ff, "SCENE 5");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 330, 0xcce6ff, "SCENE 6");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 360, 0xcce6ff, "SCENE 7");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 390, 0xcce6ff, "SCENE 8");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 420, 0xcce6ff, "SCENE 9");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 450, 0xcce6ff,
	"SCENE 10");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 700, 0xcce6ff, "BACK");
}

void	draw_econtent(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 120, 270, 0xcce6ff,
				"BLACK AND WHITE");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 300, 0xcce6ff, "SEPIA");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 700, 0xcce6ff, "BACK");
}

void	draw_ocontent(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 270, 0xcce6ff, "SPHERE");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 300, 0xcce6ff, "CONE");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 330, 0xcce6ff,
				"CYLINDER");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 700, 0xcce6ff, "BACK");
}

void	back(t_mlx *mlx)
{
	draw_menu(mlx);
}
