/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:51:50 by drenkas           #+#    #+#             */
/*   Updated: 2017/12/08 16:51:53 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "menu1.h"

float	*sum_color(float *sum_tab, float *color)
{
	sum_tab[0] += ft_clamp(color[0], 0.0, 1.0);
	sum_tab[1] += ft_clamp(color[1], 0.0, 1.0);
	sum_tab[2] += ft_clamp(color[2], 0.0, 1.0);
	return (sum_tab);
}

float	*res_color(float *sum_tab, double count, float *color)
{
	color[0] = sum_tab[0] / count;
	color[1] = sum_tab[1] / count;
	color[2] = sum_tab[2] / count;
	return (color);
}

void	hook_aa(t_mlx *st, int key)
{
	if (key == 0)
	{
		if (st->anti_al > 1)
		{
			st->anti_al /= 2;
			draw_menu(st);
			start_bitch(st);
		}
	}
	else if (key == 1)
	{
		if (st->anti_al < 16)
		{
			st->anti_al *= 2;
			draw_menu(st);
			start_bitch(st);
		}
	}
}

void	move_camtwo(t_mlx *s, int code)
{
	if (code == 3)
	{
		s->fuck = s->cam_pos.y;
		s->cam_pos.y = s->cam_pos.y * cosf(RT) + s->cam_pos.z * sinf(RT);
		s->cam_pos.z = s->fuck * (-sinf(RT)) + s->cam_pos.z * cosf(RT);
	}
	else if (code == 4)
	{
		s->fuck = s->cam_pos.y;
		s->cam_pos.y = s->cam_pos.y * cosf(RT) + s->cam_pos.z * sinf(-RT);
		s->cam_pos.z = s->fuck * (-sinf(-RT)) + s->cam_pos.z * cosf(RT);
	}
	else if (code == 5)
		s->cam_pos.x += 10;
	else if (code == 6)
		s->cam_pos.x -= 10;
	else if (code == 8)
		s->cam_pos.y += 10;
	else if (code == 7)
		s->cam_pos.y -= 10;
}

void	move_cam(t_mlx *s, int code)
{
	if (code == 2)
	{
		s->fuck = s->cam_pos.x;
		s->cam_pos.x = s->cam_pos.x * cosf(RT) + s->cam_pos.z * sinf(-RT);
		s->cam_pos.z = s->fuck * (-sinf(-RT)) + s->cam_pos.z * cosf(RT);
	}
	else if (code == 1)
	{
		s->fuck = s->cam_pos.x;
		s->cam_pos.x = s->cam_pos.x * cosf(RT) + s->cam_pos.z * sinf(RT);
		s->cam_pos.z = s->fuck * (-sinf(RT)) + s->cam_pos.z * cosf(RT);
	}
	else
		move_camtwo(s, code);
	s->code = code;
	draw_menu(s);
	start_bitch(s);
}
