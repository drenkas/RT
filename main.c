/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 17:37:57 by drenkas           #+#    #+#             */
/*   Updated: 2017/04/29 17:37:59 by drenkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu1.h"

void	check_arg2(t_mlx *mlx, int fd, char *line)
{
	int i;

	i = 0;
	mlx->obj = (t_obj *)malloc(sizeof(t_obj) * (mlx->col - 2 - mlx->ct_l + 1));
	g_m->col = mlx->col;
	g_m->ct_l = mlx->ct_l;
	mlx->lgh = (t_obj *)malloc(sizeof(t_obj) * (mlx->ct_l));
	mlx->ct_l = 0;
	while (get_next_line(fd, &line) != 0)
		if (record_obj(line, &mlx->obj[i], mlx))
			i++;
	g_m->i = i;
	if (g_m->obj == 1)
		add_sphere(mlx, i);
	else if (g_m->obj == 2 || g_m->obj == 3)
		add_cone(mlx, i);
	mlx->col = i + 1;
	free(line);
}

void	check_arg1(t_mlx *mlx, char *av)
{
	int		fd;
	char	*line;
	int		ch;

	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("File is not opened\n");
	while ((ch = get_next_line(fd, &line)) != 0)
	{
		arg_norm(line, mlx);
		free(line);
	}
	if (mlx->col < 2)
		ft_error("INVALID MAP \n");
	fd = close(fd);
	fd = open(av, O_RDONLY);
	check_arg2(mlx, fd, line);
}

void	check_arg(t_mlx *mlx, char *av)
{
	int		fd;
	char	*line;
	int		i;
	int		ch;

	i = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error("File is not opened\n");
	while ((ch = get_next_line(fd, &line)) != 0)
	{
		arg_norm(line, mlx);
		free(line);
	}
	if (mlx->col < 2)
		ft_error("INVALID MAP \n");
	fd = close(fd);
	fd = open(av, O_RDONLY);
	mlx->obj = (t_obj *)malloc(sizeof(t_obj) * (mlx->col - 2 - mlx->ct_l));
	mlx->lgh = (t_obj *)malloc(sizeof(t_obj) * (mlx->ct_l));
	mlx->ct_l = 0;
	while (get_next_line(fd, &line) != 0)
		if (record_obj(line, &mlx->obj[i], mlx))
			i++;
	mlx->col = i;
	free(line);
}

void	start_mlx(t_mlx *mlx, char *av)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_prt = mlx_new_window(mlx->mlx_ptr, WIDTH, HIGH, "RT by TEAM");
	mlx->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGH);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->s_l, &mlx->end);
	mlx->col = 0;
	mlx->ct_l = 0;
	mlx->hub_ch = 0;
	mlx->dev_ch = 0;
	mlx->zoom = 45;
	mlx->code = 0;
	g_m = (t_m *)malloc(sizeof(t_m) * 1);
	g_m->cam = 0;
	g_m->obj = 0;
	check_arg(mlx, av);
	g_m->av = ft_strdup(av);
	menu1(mlx);
	g_m->t = 0;
	g_m->ld[0].img = mlx_new_image(mlx->mlx_ptr, WIDTH, HIGH);
	g_m->oldt = 0;
	mlx->anti_al = 1;
	mlx->percent_refl = 0.0;
	start_bitch(mlx);
	mlx_hook(mlx->win_prt, 2, 5, ft_key_hook, mlx);
	mlx_hook(mlx->win_prt, 17, (1L << 17), ft_exit, mlx);
	mlx_loop(mlx->mlx_ptr);
}

int		main(int ac, char *av[])
{
	t_mlx	*mlx;

	if (ac != 2)
		ft_error("No files or too many! Pfg  lease give me ONE file/map !\n");
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	check_dot_rt(av[1]);
	mlx->bnw = 0;
	mlx->sepia = 0;
	mlx->percent_refr = 0.0;
	start_mlx(mlx, av[1]);
	return (0);
}
