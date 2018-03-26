/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyniegu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:55:23 by osyniegu          #+#    #+#             */
/*   Updated: 2018/01/09 14:55:23 by osyniegu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	add_sphere(t_mlx *mlx, int i)
{
	mlx->obj[i].type = ft_strdup("sphere");
	mlx->obj[i].pos.x = (double)ft_atoi("0");
	mlx->obj[i].pos.y = (double)ft_atoi("0");
	mlx->obj[i].pos.z = (double)ft_atoi("0");
	mlx->obj[i].size = (double)ft_atoi("25");
	mlx->obj[i].col.x = (double)ft_atoi("0");
	mlx->obj[i].col.y = (double)ft_atoi("200");
	mlx->obj[i].col.z = (double)ft_atoi("100");
}

void	add_cone(t_mlx *mlx, int i)
{
	if (g_m->obj == 2)
	{
		mlx->obj[i].type = ft_strdup("cone");
	}
	else
	{
		if (g_m->obj == 3)
		{
			mlx->obj[i].type = ft_strdup("cylinder");
		}
	}
	mlx->obj[i].pos.x = (double)ft_atoi("0");
	mlx->obj[i].pos.y = (double)ft_atoi("0");
	mlx->obj[i].pos.z = (double)ft_atoi("80");
	mlx->obj[i].size = (double)ft_atoi("25");
	mlx->obj[i].col.x = (double)ft_atoi("0");
	mlx->obj[i].col.y = (double)ft_atoi("200");
	mlx->obj[i].col.z = (double)ft_atoi("100");
	mlx->obj[i].rot.x = (double)ft_atoi("0.0");
	mlx->obj[i].rot.y = (double)ft_atoi("1.0");
	mlx->obj[i].rot.z = (double)ft_atoi("0.0");
}

void	load_spin(t_mlx *mlx)
{
	if (g_m->l == 1)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_prt,
								g_m->ld[1].img, 675, 675);
		mlx_do_sync(mlx->mlx_ptr);
	}
	else if (g_m->l == 2)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_prt,
								g_m->ld[2].img, 675, 675);
		mlx_do_sync(mlx->mlx_ptr);
	}
	else if (g_m->l == 3)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_prt,
								g_m->ld[3].img, 675, 675);
		mlx_do_sync(mlx->mlx_ptr);
	}
	else if (g_m->l == 4)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_prt,
								g_m->ld[4].img, 675, 675);
		mlx_do_sync(mlx->mlx_ptr);
	}
}

void	dr_mc_1(t_mlx *mlx, char **str, char **str1)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 100, 10, 0xcce6ff, "SCENE: ");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 10, 0xcce6ff, g_m->av);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 90, 40,
				0xcce6ff, "RESOLUTION: ");
	str[0] = ft_itoa(g_m->ml[0].w);
	str1[0] = ft_itoa(g_m->ml[0].h);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 210, 40, 0xcce6ff, str[0]);
	ft_strdel(&str[0]);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 250, 40, 0xcce6ff, "X");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 270, 40, 0xcce6ff, str1[0]);
	ft_strdel(&str1[0]);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 170, 210, 0xcce6ff, "CAMERA");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 100, 240, 0xcce6ff, "ROTATE");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 180, 240, 0xcce6ff, "KEYS");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 250, 240, 0xcce6ff, "POS");
	if (g_m->p == 123)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 110, 270, 0x1874cd, "-");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 110, 270, 0xcce6ff, "-");
	if (g_m->p == 124)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 270, 0x1874cd, "+");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 270, 0xcce6ff, "+");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 180, 270, 0xcce6ff, "8");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 210, 270, 0xcce6ff, "2");
}

void	dr_mc_2(t_mlx *mlx, char **str)
{
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 50, 270, 0xcce6ff, "X");
	str[0] = ft_itoa((int)mlx->cam_pos.x);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 260, 270, 0xcce6ff, str[0]);
	ft_strdel(&str[0]);
	if (g_m->p == 125)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 110, 300, 0x1874cd, "-");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 110, 300, 0xcce6ff, "-");
	if (g_m->p == 126)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 300, 0x1874cd, "+");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 140, 300, 0xcce6ff, "+");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 180, 300, 0xcce6ff, "4");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 210, 300, 0xcce6ff, "6");
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 50, 300, 0xcce6ff, "Y");
	str[0] = ft_itoa((int)mlx->cam_pos.y);
	mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 260, 300, 0xcce6ff, str[0]);
	ft_strdel(&str[0]);
	if (g_m->p == 78)
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 110, 330, 0x1874cd, "-");
	else
		mlx_string_put(mlx->mlx_ptr, g_m->ml[0].win, 110, 330, 0xcce6ff, "-");
}
