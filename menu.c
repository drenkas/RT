/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:25:54 by drenkas           #+#    #+#             */
/*   Updated: 2017/06/26 19:25:55 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	free_mass(char **st, int x)
{
	int		i;

	i = 0;
	while (i <= x)
	{
		free(st[i]);
		i++;
	}
}

void	show_hub(t_mlx *st)
{
	mlx_string_put(MLX, WIN, 10, 700, 0xbcdf46, "SHOW MENU : H");
}

void	ft_menu(t_mlx *st)
{
	char *s[6];

	s[0] = ft_strdup("-----------------------------------");
	s[1] = ft_strdup("| Move CAMERA : ARROWS ->         |");
	s[2] = ft_strdup("| ZOOM : NUM+ , NUM-              |");
	s[3] = ft_strdup("| Remove zoom : NUM ENTER         |");
	s[4] = ft_strdup("| Enable glare : G                |");
	s[5] = ft_strdup("-----------------------------------");
	mlx_string_put(MLX, WIN, 10, 10, 0xbcdf46, s[0]);
	mlx_string_put(MLX, WIN, 10, 35, 0xbcdf46, s[1]);
	mlx_string_put(MLX, WIN, 10, 60, 0xbcdf46, s[2]);
	mlx_string_put(MLX, WIN, 10, 85, 0xbcdf46, s[3]);
	mlx_string_put(MLX, WIN, 10, 110, 0xbcdf46, s[4]);
	mlx_string_put(MLX, WIN, 10, 125, 0xbcdf46, s[5]);
	free_mass(s, 6);
}

int		menu_keytwo(t_mlx *st, int f)
{
	if (g_m->glare)
	{
		if (st->g == 1 && g_m->glare == 1)
			st->g = 0;
		else if (st->g == 0 && g_m->glare == 2)
			st->g = 1;
		else
			f = 1;
		g_m->glare = 0;
	}
	else
	{
		if (st->g == 1)
			st->g = 0;
		else
			st->g = 1;
	}
	return (f);
}

void	menu_key(t_mlx *st, int k)
{
	int f;

	f = 0;
	if (k == 4)
	{
		if (st->hub_ch == 1)
			st->hub_ch = 0;
		else
			st->hub_ch = 1;
	}
	else if (k == 5)
	{
		f = menu_keytwo(st, f);
	}
	if (f != 1)
	{
		draw_menu(st);
		start_bitch(st);
	}
}
