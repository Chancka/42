/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:01:44 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 15:32:25 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	img(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->data.exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit3.xpm",
			&img_width, &img_height);
	vars->data.collect = mlx_xpm_file_to_image(vars->mlx, "./img/coin.xpm",
			&img_width, &img_height);
	vars->data.back = mlx_xpm_file_to_image(vars->mlx, "./img/back.xpm",
			&img_width, &img_height);
	vars->data.perso = mlx_xpm_file_to_image(vars->mlx, "./img/perso.xpm",
			&img_width, &img_height);
	vars->data.wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm",
			&img_width, &img_height);
	vars->data.start = mlx_xpm_file_to_image(vars->mlx, "./img/start.xpm",
			&img_width, &img_height);
	vars->data.option = mlx_xpm_file_to_image(vars->mlx, "./img/option.xpm",
			&img_width, &img_height);
}

void	ft_img_bonus(t_vars *vars)
{
	int	img_width;
	int	img_height;

	if (vars->data.exit)
		mlx_destroy_image(vars->mlx, vars->data.exit);
	vars->data.exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit2.xpm",
			&img_width, &img_height);
	if (vars->data.perso)
		mlx_destroy_image(vars->mlx, vars->data.perso);
	vars->data.perso = mlx_xpm_file_to_image(vars->mlx, "./img/perso2.xpm",
			&img_width, &img_height);
	if (vars->data.wall)
		mlx_destroy_image(vars->mlx, vars->data.wall);
	vars->data.wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall2.xpm",
			&img_width, &img_height);
}

void	ft_img_bonus2(t_vars *vars)
{
	int	img_width;
	int	img_height;

	if (vars->data.exit)
		mlx_destroy_image(vars->mlx, vars->data.exit);
	vars->data.exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm",
			&img_width, &img_height);
	if (vars->data.perso)
		mlx_destroy_image(vars->mlx, vars->data.perso);
	vars->data.perso = mlx_xpm_file_to_image(vars->mlx, "./img/perso.xpm",
			&img_width, &img_height);
	if (vars->data.wall)
		mlx_destroy_image(vars->mlx, vars->data.wall);
	vars->data.wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm",
			&img_width, &img_height);
}
