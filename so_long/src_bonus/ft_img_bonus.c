/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:17:36 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 17:02:55 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	image_bonus(t_vars *vars)
{
	image_wall(vars);
	image_back(vars);
	image_collect(vars);
	image_exit(vars);
	image_perso(vars);
}

void	image_bonus2(t_vars *vars)
{
	image_wall(vars);
	image_exit(vars);
	image_perso(vars);
}

void	destroy_img2(t_vars *vars)
{
	if (vars->data.exit)
		mlx_destroy_image(vars->mlx, vars->data.exit);
	if (vars->data.perso)
		mlx_destroy_image(vars->mlx, vars->data.perso);
	if (vars->data.wall)
		mlx_destroy_image(vars->mlx, vars->data.wall);
	return ;
}
