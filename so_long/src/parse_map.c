/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:52:13 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 14:54:47 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	parse_map(char *argv, t_vars *vars)
{
	char	*ret;
	int		i;
	int		fd;
	int		size;

	size = largeur(argv);
	i = 0;
	fd = open(argv, 0);
	vars->map = malloc(sizeof(char *) * (size + 1));
	if (!vars->map)
		return ;
	ret = get_next_line(fd);
	while (ret)
	{
		vars->map[i] = ret;
		ret = get_next_line(fd);
		i++;
	}
	vars->map[i] = NULL;
	free(ret);
	close(fd);
}
