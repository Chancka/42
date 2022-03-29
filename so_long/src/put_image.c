/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:01 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/29 17:44:42 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	image_wall(t_vars *vars)
{
	int i;
	int j;
	int	img_width;
	int	img_height;

	vars->data = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", &img_width, &img_height);
	if (!vars->data)
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_perso(t_vars *vars)
{
	int i;
	int j;
	int	img_width;
	int	img_height;

	vars->data = mlx_xpm_file_to_image(vars->mlx, "perso.xpm", &img_width, &img_height);
	if (!vars->data)
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_back(t_vars *vars)
{
	int i;
	int j;
	int	img_width;
	int	img_height;

	vars->data = mlx_xpm_file_to_image(vars->mlx, "back.xpm", &img_width, &img_height);
	if (!vars->data)
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_collect(t_vars *vars)
{
	int i;
	int j;
	int	img_width;
	int	img_height;

	vars->data = mlx_xpm_file_to_image(vars->mlx, "coin.xpm", &img_width, &img_height);
	if (!vars->data)
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_exit(t_vars *vars)
{
	int i;
	int j;
	int	img_width;
	int	img_height;

	vars->data = mlx_xpm_file_to_image(vars->mlx, "exit3.xpm", &img_width, &img_height);
	if (!vars->data)
		return ;
	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

int	ft_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(127);
	}
	image_wall(vars);
	image_perso(vars);
	image_back(vars);
	image_exit(vars);
	image_collect(vars);
	return (0);
}


void test(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, ((int)ft_strlen(vars->map[1]) -1) * 64, ft_strstrlen(vars->map) * 64, "so_long");
	mlx_hook(vars->win, 2, 1L<<0, ft_close, vars);
	mlx_loop(vars->mlx);

}

int	main(int ac, char **av)
{
	t_vars vars;

	(void)ac;
	parse_map(av[1], &vars);
	test(&vars);
	// printf("oui");
	ft_free_tab(vars.map);

}