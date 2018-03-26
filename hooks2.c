/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 22:20:05 by osyniegu          #+#    #+#             */
/*   Updated: 2018/01/11 22:20:06 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	gm_ch_5(t_mlx *mlx, int x, int y)
{
	if (x >= 140 && y >= 310 && x <= 150 && y <= 320 ? g_m->p = 126 : 0)
		ft_key_hook(88, mlx);
	if (x >= 110 && y >= 340 && x <= 120 && y <= 346 ? g_m->p = 78 : 0)
		ft_key_hook(78, mlx);
	if (x >= 140 && y >= 340 && x <= 150 && y <= 350 ? g_m->p = 69 : 0)
		ft_key_hook(69, mlx);
	if (x >= 160 && y >= 170 && x <= 230 && y <= 180
		? g_m->glare = 1 : 0)
		ft_key_hook(5, mlx);
	if (x >= 260 && y >= 170 && x <= 320 && y <= 180
		? g_m->glare = 2 : 0)
		ft_key_hook(5, mlx);
	if (x >= 150 && y >= 490 && x <= 250 && y <= 500 ? g_m->p = 1 : 0)
		take_screenshot(mlx);
	if (x >= 140 && y >= 400 && x <= 260 && y <= 410 ? g_m->p = 2 : 0)
		choose_scene(mlx);
	if (x >= 150 && y >= 460 && x <= 250 && y <= 470 ? g_m->p = 2 : 0)
		add_obj(mlx);
}

void	gm_ch_0(t_mlx *mlx, int x, int y)
{
	if (x >= 240 && y >= 110 && x <= 250 && y <= 120 ? g_m->p = -10 : 0)
		ft_key_hook(0, mlx);
	else if (x >= 270 && y >= 110 && x <= 280 && y <= 120 ? g_m->p = -20 : 0)
		ft_key_hook(1, mlx);
	if (x >= 240 && y >= 140 && x <= 250 && y <= 150 ? g_m->p = -120 : 0)
		ft_key_hook(12, mlx);
	else if (x >= 270 && y >= 140 && x <= 280 && y <= 150 ? g_m->p = -130 : 0)
		ft_key_hook(13, mlx);
	if (x >= 110 && y >= 280 && x <= 120 && y <= 286 ? g_m->p = 123 : 0)
		ft_key_hook(91, mlx);
	if (x >= 140 && y >= 280 && x <= 150 && y <= 290 ? g_m->p = 124 : 0)
		ft_key_hook(84, mlx);
	if (x >= 110 && y >= 310 && x <= 120 && y <= 316 ? g_m->p = 125 : 0)
		ft_key_hook(86, mlx);
	gm_ch_5(mlx, x, y);
}

void	gm_ch_1(t_mlx *mlx, int x, int y)
{
	g_m->obj = 0;
	if (x >= 170 && y >= 710 && x <= 210 && y <= 720 ? g_m->p = 5 : 0)
	{
		g_m->ch = 0;
		back(mlx);
	}
	if (x >= 170 && y >= 190 && x <= 240 && y <= 200 ? g_m->p = -1 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 220 && x <= 240 && y <= 230
			? g_m->p = -2 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 250 && x <= 240 && y <= 260
			? g_m->p = -3 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
}

void	gm_ch_12(t_mlx *mlx, int x, int y)
{
	if (x >= 170 && y >= 280 && x <= 240 && y <= 290
		? g_m->p = -4 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 310 && x <= 240 && y <= 320
			? g_m->p = -5 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 340 && x <= 240 && y <= 350
			? g_m->p = -6 : 0)
	{
		g_m->ch = 0;
		start_scene(mlx);
	}
	else if (x >= 170 && y >= 710 && x <= 210 && y <= 720 ? g_m->p = 5 : 0)
	{
		g_m->ch = 0;
		back(mlx);
	}
	else
		crutch_in_hooks(mlx, x, y);
}

void	gm_ch_2(t_mlx *mlx, int x, int y)
{
	if (x >= 120 && y >= 280 && x <= 270 && y <= 290 ? g_m->p = 5 : 0)
		zoom_cam(mlx, 4);
	else if (x >= 170 && y >= 310 && x <= 220 && y <= 320 ? g_m->p = 5 : 0)
		zoom_cam(mlx, 5);
}
