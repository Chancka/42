/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:26:44 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 14:19:58 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_line(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		if (vars->map[i][0] != '1')
			return (1);
		while (vars->map[i][j])
			j++;
		if (vars->map[i][j - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_collec(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	vars->max_collect = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'C')
				vars->max_collect++;
			j++;
		}
		i++;
	}
	if (vars->max_collect <= 0)
		return (1);
	return (0);
}

int	check_player(t_vars *vars)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'P')
			{
				player++;
				vars->player_pos_x = j;
				vars->player_pos_y = i;
			}	
			j++;
		}
		i++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

int	check_map(t_vars *vars)
{
	if (check_wrong_map_char(vars->map))
	{
		ft_printf("Error \nUnknown character\n");
		ft_free_tab(vars->map);
		exit(0);
	}
	if (check_top_botom(vars) || check_line(vars))
	{
		ft_printf("Error \nProblem with the parsing of the map.\n");
		ft_free_tab(vars->map);
		exit(0);
	}
	if (check_collec(vars))
	{
		ft_printf("Error \nWrong number of collectibles\n");
		ft_free_tab(vars->map);
		exit(0);
	}
	if (check_exit(vars->map) || check_player(vars))
	{
		ft_printf("Error \nYou must have only one player and one exit \n");
		ft_free_tab(vars->map);
		exit(0);
	}
	return (1);
}
