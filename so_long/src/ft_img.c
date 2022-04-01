/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:01:44 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 14:56:34 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	img(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->data.exit = mlx_xpm_file_to_image(vars->mlx, "./img/exit3.xpm",
			&img_width, &img_height);
	if (!vars->data.exit)
		return ;
	vars->data.collect = mlx_xpm_file_to_image(vars->mlx, "./img/coin.xpm",
			&img_width, &img_height);
	if (!vars->data.collect)
		return ;
	vars->data.back = mlx_xpm_file_to_image(vars->mlx, "./img/back.xpm",
			&img_width, &img_height);
	if (!vars->data.back)
		return ;
	vars->data.perso = mlx_xpm_file_to_image(vars->mlx, "./img/perso.xpm",
			&img_width, &img_height);
	if (!vars->data.perso)
		return ;
	vars->data.wall = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm",
			&img_width, &img_height);
	if (!vars->data.wall)
		return ;
}
