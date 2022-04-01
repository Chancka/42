/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:17:36 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 17:26:45 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	image_fire(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.fire,
		vars->fire_pos_x * 64, vars->fire_pos_y * 64);
}

void	image_bonus(t_vars *vars)
{
	image_fire(vars);
	image_wall(vars);
	image_perso(vars);
	image_back(vars);
	image_collect(vars);
	image_exit(vars);
}

void	delay(int milliseconds)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < pause)
	{
		now = clock();
	}
	return ;
}

void	ft_move(t_vars *vars)
{
	int	right;
	int	left;

	right = 1;
	left = 0;
	if (right == 1)
	{
		if (vars->map[vars->fire_pos_y][vars->fire_pos_x + 1] == '0')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
				vars->fire_pos_x * 64, vars->fire_pos_y * 64);
			vars->fire_pos_x++;
		}
		if (vars->map[vars->fire_pos_y][vars->fire_pos_x + 1] == '1' || vars->map[vars->fire_pos_y][vars->fire_pos_x + 1] == 'C')
		{
			left = 1;
			right = 0;
		}
	}
	if (left == 1)
	{
		if (vars->map[vars->fire_pos_y][vars->fire_pos_x - 1] == '0')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
				vars->fire_pos_x * 64, vars->fire_pos_y * 64);
			vars->fire_pos_x--;
		}
		if (vars->map[vars->fire_pos_y][vars->fire_pos_x - 1] == '1' || vars->map[vars->fire_pos_y][vars->fire_pos_x - 1] == 'C')
		{
			left = 0;
			right = 1;
		}
	}
}

void	ft_move_fire(t_vars *vars)
{

	if (!(vars->data.fire))
		return ;
	ft_move(vars);
	if (vars->player_pos_x == vars->fire_pos_x && vars->player_pos_y == vars->fire_pos_y)
	{
		ft_printf("You lose\n");
		destroy_img(vars);
		exit(0);
	}
}
