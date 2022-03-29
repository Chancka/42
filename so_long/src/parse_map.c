/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:52:13 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/29 16:08:15 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// int	check_size(char **str)
// {
// 	int	len;
// 	int	i;

// 	i = 0;
// 	len = ft_strlen(str[0]);
// 	while (str[i])
// 	{
// 		if (len != ft_strlen(str[i]))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int	check_wall(char **str, char *map)
// {
// 	int	i;
// 	int	j;
// 	int	i_max;
// 	int	j_max;

// 	i_max = largeur(map) - 1;
// 	j_max = longueur(map) - 1;
// 	i = 0;
// 	while (str[i])
// 	{
// 		j = 0;
// 		while (j < ft_strlen(str[i]) - 1)
// 		{
// 			if (str[0][j] != '1' || str[i_max][j] != '1')
// 				return (1);
// 			else if (str[i][j_max] != '1' || str[i][0] != '1')
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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


// int main(int argc, char **argv)
// {
// 	t_vars	vars;

// 	parse_map(argv[1], &vars);
// 	check_map(&vars, argv[1]);
// 	ft_free_tab(vars.map);
// 	// free((int*)vars.max_collect);
// }