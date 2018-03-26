/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:58:05 by drenkas           #+#    #+#             */
/*   Updated: 2017/05/01 15:58:06 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	free_arr(t_obj *obj, t_mlx *st)
{
	int		i;

	i = 0;
	while (i < st->col)
	{
		free(obj[i].type);
		i++;
	}
	free(st->lgh);
}

int		ft_exit(t_mlx *st)
{
	system("killall afplay");
	free_arr(st->obj, st);
	mlx_destroy_image(st->mlx_ptr, st->img);
	free(st);
	ft_error("                       THE END\n");
	return (0);
}

void	zoom_cam(t_mlx *s, int code)
{
	if (code == 2)
		s->cam_pos.z -= 10;
	else if (code == 1)
		s->cam_pos.z += 10;
	else if (code == 3)
		s->cam_pos.z = 45;
	else if (code == 4 && s->bnw == 0)
		s->bnw = 1;
	else if (code == 4 && s->bnw == 1)
		s->bnw = 0;
	else if (code == 5 && s->sepia == 0)
		s->sepia = 1;
	else if (code == 5 && s->sepia == 1)
		s->sepia = 0;
	s->code = code;
	draw_menu(s);
	start_bitch(s);
}

void	ft_key_hooktwo(int key, t_mlx *st)
{
	if (key == 125)
		move_cam(st, 3);
	else if (key == 96)
		zoom_cam(st, 4);
	else if (key == 97)
		zoom_cam(st, 5);
	else if (key == 69)
		zoom_cam(st, 1);
	else if (key == 78)
		zoom_cam(st, 2);
	else if (key == 76)
		zoom_cam(st, 3);
	else if (key == 5 || key == 4)
		menu_key(st, key);
	else if (key == 0 || key == 1)
		hook_aa(st, key);
	else if (key == 12 || key == 13)
		hook_refl(st, key);
	else if (key == 15)
		hooks_refr(st, key);
	else if (g_m->obj > 0)
		move_obj(st, key);
}

int		ft_key_hook(int key, t_mlx *st)
{
	if (key == 53)
		ft_exit(st);
	else if (key == 88 && g_m->obj == 0 ? g_m->key = 1 : 0)
		move_cam(st, 5);
	else if (key == 86 && g_m->obj == 0 ? g_m->key = 1 : 0)
		move_cam(st, 6);
	else if (key == 84 && g_m->obj == 0 ? g_m->key = 1 : 0)
		move_cam(st, 7);
	else if (key == 91 && g_m->obj == 0 ? g_m->key = 1 : 0)
		move_cam(st, 8);
	else if (key == 124)
		move_cam(st, 2);
	else if (key == 123)
		move_cam(st, 1);
	else if (key == 126)
		move_cam(st, 4);
	else
		ft_key_hooktwo(key, st);
	return (0);
}
