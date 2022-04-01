/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:27:35 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/01 18:05:27 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_top_botom(t_vars *vars)
{
	int		i;
	char	*last;
	char	*first;

	first = vars->map[0];
	last = vars->map[ft_strstrlen(vars->map) - 1];
	if (ft_strstrlen(vars->map) - 1 < 1)
		return (1);
	i = 0;
	while (first[i + 1])
	{
		if (first[i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (last[i])
	{
		if (last[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	largeur(char *str)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(str, 0);
	if (fd == -1)
		exit(127);
	line = get_next_line(fd);
	len = 0;
	while (line)
	{
		free(line);
		len++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (len);
}

int	check_wrong_map_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != 'C' && map[i][j] != 'P' &&
				map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r')
		return (1);
	if (str[i - 2] != 'e')
		return (1);
	if (str[i - 3] != 'b')
		return (1);
	return (0);
}
