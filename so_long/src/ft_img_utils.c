/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:59:57 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 14:54:26 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	image_wall(t_vars *vars)
{
	int	i;
	int	j;

	if (!(vars->data.wall))
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data.wall,
					64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

void	image_perso(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.perso,
		vars->player_pos_x * 64, vars->player_pos_y * 64);
}

void	image_back(t_vars *vars)
{
	int	i;
	int	j;

	if (!(vars->data.back))
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.back, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

void	image_collect(t_vars *vars)
{
	int	i;
	int	j;

	if (!(vars->data.collect))
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.collect, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

void	image_exit(t_vars *vars)
{
	int	i;
	int	j;

	if (!(vars->data.exit))
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->data.exit, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}
