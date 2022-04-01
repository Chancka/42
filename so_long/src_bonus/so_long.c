/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:01 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 18:04:30 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.exit);
	mlx_destroy_image(vars->mlx, vars->data.collect);
	mlx_destroy_image(vars->mlx, vars->data.back);
	mlx_destroy_image(vars->mlx, vars->data.perso);
	mlx_destroy_image(vars->mlx, vars->data.wall);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_tab(vars->map);
	free(vars->mlx);
	return ;
}

void	ft_move_count(t_vars *vars)
{
	char	*str;

	if (!vars->data.wall)
		return ;
	str = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.wall, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0xFFFFFF, str);
	printf("Move count : %d\n", vars->move_count);
	free(str);
}

int	ft_close_cross(t_vars *vars)
{
	destroy_img(vars);
	printf("you have clicked on the red cross.\n");
	exit(0);
}

void	start(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, ft_key, vars);
	mlx_hook(vars->win, 17, 0L, ft_close_cross, vars);
	mlx_loop(vars->mlx);
}

int	ft_started(int button, int x, int y, t_vars *vars)
{
	int	i;
	int	j;

	ft_printf("button %d\n", button);
	i = (int)ft_strlen(vars->map[1]) * 32;
	j = ft_strstrlen(vars->map) * 32;
	if (x < i + 120 && x > i && y < j + 60 && y > j)
	{
		if (button == 1)
		{
			image_bonus(vars);
			start(vars);
		}
	}
	return (0);
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		destroy_img(vars);
		printf("you have closed the window.\n");
		exit(0);
	}
	return (0);
}

void	start_bonus(t_vars *vars)
{
	mlx_hook(vars->win, 4, 1L<<2, ft_started, vars);
	mlx_hook(vars->win, 17, 0L, ft_close_cross, vars);
	mlx_hook(vars->win, 2, 1L << 0, ft_close, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2 || ft_isber(av[1]))
	{
		ft_putstr("usage : ./so_long map_file.ber\n");
		return (0);
	}
	vars.collect = 0;
	vars.move_count = 0;
	parse_map(av[1], &vars);
	check_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ((int)ft_strlen(vars.map[1]) - 1) * 64,
			ft_strstrlen(vars.map) * 64, "so_long");
	img(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.start,
		((int)ft_strlen(vars.map[1]) - 1) * 32, ft_strstrlen(vars.map) * 32);
	// image_bonus(&vars);
	start_bonus(&vars);
	// start(&vars);
	return (0);
}
