/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:58:21 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 15:50:01 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_key_up(t_vars *vars)
{
	if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == '0')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_y--;
	}
	else if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == 'C')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y - 1][vars->player_pos_x] = '0';
		vars->collect++;
		vars->player_pos_y--;
	}
	else if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == 'E' &&
		vars->collect == vars->max_collect)
	{
		vars->move_count++;
		destroy_img(vars);
		exit(0);
	}
}

void	ft_key_down(t_vars *vars)
{
	if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == '0')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_y++;
	}
	else if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == 'C')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y + 1][vars->player_pos_x] = '0';
		vars->collect++;
		vars->player_pos_y++;
	}
	else if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == 'E' &&
		vars->collect == vars->max_collect)
	{
		vars->move_count++;
		destroy_img(vars);
		exit(0);
	}
}

void	ft_key_right(t_vars *vars)
{
	if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == '0')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_x++;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == 'C')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y][vars->player_pos_x + 1] = '0';
		vars->collect++;
		vars->player_pos_x++;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == 'E' &&
		vars->collect == vars->max_collect)
	{
		vars->move_count++;
		destroy_img(vars);
		exit(0);
	}
}

void	ft_key_left(t_vars *vars)
{
	if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == '0')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_x--;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == 'C')
	{
		vars->move_count++;
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back,
			vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y][vars->player_pos_x - 1] = '0';
		vars->collect++;
		vars->player_pos_x--;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == 'E' &&
		vars->collect == vars->max_collect)
	{
		vars->move_count++;
		destroy_img(vars);
		exit(0);
	}
}

int	ft_key(int keycode, t_vars *vars)
{
	if (keycode != 65307 && keycode != 119 && keycode != 115 && keycode != 97
		&& keycode != 100 && keycode != 113)
		return (0);
	if (keycode == 65307)
	{
		ft_printf("you have closed the window.\n");
		destroy_img(vars);
		exit(0);
	}
	if (keycode == 119)
		ft_key_up(vars);
	if (keycode == 115)
		ft_key_down(vars);
	if (keycode == 97)
		ft_key_left(vars);
	if (keycode == 100)
		ft_key_right(vars);
	image_perso(vars);
	ft_move_count(vars);
	return (0);
}
