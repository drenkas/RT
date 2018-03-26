/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:36:52 by osyniegu          #+#    #+#             */
/*   Updated: 2017/12/05 17:36:53 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	take_screenshot(t_mlx *mlx)
{
	system("screencapture -c -W -P screen.png");
	draw_menu(mlx);
}

void	play_music(t_mlx *mlx)
{
	if (g_m->m == 3)
		system("sh music/pause.sh");
	else if (g_m->m == 1)
		system("sh music/play.sh");
	draw_menu(mlx);
}

int		mouse_hook1(int b, int x, int y, t_mlx *mlx)
{
	if (b == 1)
	{
		gm_ch(mlx, x, y);
		if (g_m->ch == 2)
		{
			gm_ch_2(mlx, x, y);
			if (x >= 170 && y >= 710 && x <= 210 && y <= 720 ? g_m->p = 5 : 0)
			{
				g_m->ch = 0;
				back(mlx);
			}
		}
		else if (g_m->ch == 3)
		{
			gm_ch_3(mlx, x, y);
			if (x >= 170 && y >= 340 && x <= 240 && y <= 350
					? g_m->p = -7 : 0)
			{
				g_m->ch = 0;
				g_m->obj = 3;
				start_scene(mlx);
			}
		}
	}
	return (0);
}

int		hooks1(int c, t_mlx *mlx)
{
	if (c == 53)
		ft_exit(mlx);
	return (0);
}
