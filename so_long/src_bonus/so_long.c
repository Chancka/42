/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:01 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 15:41:16 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	start(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.option,
		((int)ft_strlen(vars->map[1]) - 1) * 32 - 18,
		ft_strstrlen(vars->map) * 64 - 36);
	mlx_hook(vars->win, 2, 1L << 0, ft_key, vars);
	mlx_hook(vars->win, 4, 1L << 2, ft_option, vars);
	mlx_hook(vars->win, 17, 0L, ft_close_cross, vars);
	mlx_loop(vars->mlx);
}

int	ft_started(int button, int x, int y, t_vars *vars)
{
	int	i;
	int	j;

	i = (int)ft_strlen(vars->map[1]) * 32;
	j = ft_strstrlen(vars->map) * 32;
	if (x < i + 40 && x > i - 100 && y < j + 20 && y > j - 30)
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
		ft_printf("you have closed the window.\n");
		exit(0);
	}
	return (0);
}

void	start_bonus(t_vars *vars)
{
	mlx_hook(vars->win, 4, 1L << 2, ft_started, vars);
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
	vars.option = 0;
	parse_map(av[1], &vars);
	check_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,
			((int)ft_strlen(vars.map[1]) - 1) * 64,
			ft_strstrlen(vars.map) * 64, "so_long");
	img(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.data.start,
		((int)ft_strlen(vars.map[1]) - 1) * 32 - 80,
		ft_strstrlen(vars.map) * 32 - 40);
	start_bonus(&vars);
	return (0);
}
