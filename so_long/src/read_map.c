/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:01 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/25 17:00:36 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars.map[i])
	{
		j = 0;
		while (vars.map[i][j])
		{
			if (vars.map[i][j] == '1')
				aff_wall(vars, j, i);
			else if (vars.map[i][j] == '0')
				aff_background(vars, j, i);
			else if (vars.map[i][j] == 'P')
				aff_player(vars, j, i);
			else if (vars.map[i][j] == 'C')
				aff_collect(vars, j, i);
			else if (vars.map[i][j] == 'E')
				aff_exit(vars, j, i);
			j++;
		}
		i++;
	}
}