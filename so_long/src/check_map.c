/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:26:44 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/29 15:48:33 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	check_player(char **map)
{
	int	i;
	int	y;
	int	player;

	i = 0;
	player = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'P')
				player++;
			y++;
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
	int	y;
	int	exit;

	i = 0;
	exit = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'E')
				exit++;
			y++;
		}
		i++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

int	check_map(t_vars *vars)
{
	// if (check_size(vars->map) /*|| check_wrong_map_char(str)*/)
	// {
	// 	ft_printf("Error \nWrong map size or unknown character\n");
	// 	ft_free_tab(vars->map);
	// 	exit(0);
	// }
	if (check_top_botom(vars) || check_line(vars))
	{
		ft_printf("Error \nProblem with the parsing of the map.\n");
		ft_free_tab(vars->map);
		exit(0);
	}
	if (check_collec(vars))
	{
		ft_printf("%i", vars->max_collect);
		ft_printf("Error \nWrong number of collectibles\n");
		ft_free_tab(vars->map);
		exit(0);
	}
	if (check_exit(vars->map) || check_player(vars->map))
	{
		ft_printf("Error \nYou must have only one player and one exit \n");
		ft_free_tab(vars->map);
		exit(0);
	}
	return (1);
}
