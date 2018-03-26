/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:29:36 by osyniegu          #+#    #+#             */
/*   Updated: 2017/12/13 19:29:36 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	reinit(t_mlx *mlx, char **av)
{
	if (g_m->p == -11)
		av[0] = ft_strdup("scenes/10.rt");
	free_arr(mlx->obj, mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGH);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_l, &mlx->end);
	mlx->col = 0;
	mlx->ct_l = 0;
	mlx->hub_ch = 0;
	mlx->dev_ch = 0;
	mlx->zoom = 45;
	mlx->code = 0;
	free(mlx->obj);
	if (g_m->obj == 0)
		check_arg(mlx, av[0]);
	else
		check_arg1(mlx, av[0]);
	if (!g_m->cam || g_m->err == 1)
		ft_error("INVALID MAP \n");
	ft_strdel(&g_m->av);
	g_m->av = ft_strdup(av[0]);
	ft_strdel(&av[0]);
	mlx->g = 0;
	draw_menu(mlx);
	start_bitch(mlx);
}

void	start_scene(t_mlx *mlx)
{
	char *av;

	av = NULL;
	if (g_m->p == -1)
		av = ft_strdup("scenes/1.rt");
	else if (g_m->p == -2)
		av = ft_strdup("scenes/2.rt");
	else if (g_m->p == -3)
		av = ft_strdup("scenes/3.rt");
	else if (g_m->p == -4)
		av = ft_strdup("scenes/4.rt");
	else if (g_m->p == -5)
		av = ft_strdup("scenes/5.rt");
	else if (g_m->p == -6)
		av = ft_strdup("scenes/6.rt");
	else if (g_m->p == -7)
		av = ft_strdup(g_m->av);
	else if (g_m->p == -8)
		av = ft_strdup("scenes/7.rt");
	else if (g_m->p == -9)
		av = ft_strdup("scenes/8.rt");
	else if (g_m->p == -10)
		av = ft_strdup("scenes/9.rt");
	reinit(mlx, &av);
}

void	add_obj(t_mlx *mlx)
{
	g_m->ch = 3;
	draw_menu(mlx);
}

void	choose_effect(t_mlx *mlx)
{
	g_m->ch = 2;
	draw_menu(mlx);
}

void	choose_scene(t_mlx *mlx)
{
	g_m->ch = 1;
	draw_menu(mlx);
}
