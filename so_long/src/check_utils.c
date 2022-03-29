/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:27:35 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/29 16:24:46 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

// int	longueur(char *str)
// {
// 	int		fd;
// 	char	*line;
// 	int		len;

// 	fd = open(str, 0);
// 	if (fd == -1)
// 		exit(127);
// 	line = get_next_line(fd);
// 	len = ft_strlen(line);
// 	free(line);
// 	close(fd);
// 	len = len - 1;
// 	return (len);
// }

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
