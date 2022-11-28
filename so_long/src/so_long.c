/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:01 by cboudrin          #+#    #+#             */
/*   Updated: 2022/10/14 18:33:50 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	ft_printf("Move count : %d\n", vars->move_count);
}

int	ft_close_cross(t_vars *vars)
{
	destroy_img(vars);
	ft_printf("you have clicked on the red cross.\n");
	exit(0);
}

void	start(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L << 0, ft_key, vars);
	mlx_hook(vars->win, 17, 0L, ft_close_cross, vars);
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
	(void)ac;
	parse_map(av[1], &vars);
	check_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ((int)ft_strlen(vars.map[1]) - 1) * 64,
			ft_strstrlen(vars.map) * 64, "so_long");
	img(&vars);
	image_wall(&vars);
	image_perso(&vars);
	image_back(&vars);
	image_exit(&vars);
	image_collect(&vars);
	start(&vars);
	return (0);
}
