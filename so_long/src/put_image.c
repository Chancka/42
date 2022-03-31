/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:33:01 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/31 17:53:24 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	image_wall(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data.wall, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_perso(t_vars *vars)
{
	// int i;
	// int j;

	// i = 0;
	// while (i < ft_strstrlen(vars->map))
	// {
	// 	j = 0;
	// 	while (j < (int)ft_strlen(vars->map[1]) - 1)
	// 	{
	// 		if (vars->map[i][j] == 'P')
	// 			mlx_put_image_to_window(vars->mlx, vars->win, vars->data.perso, 64*j, 64*i);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.perso, vars->player_pos_x * 64, vars->player_pos_y * 64);
}

void	image_back(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_collect(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data.collect, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	image_exit(t_vars *vars)
{
	int i;
	int j;

	i = 0;
	while (i < ft_strstrlen(vars->map))
	{
		j = 0;
		while (j < (int)ft_strlen(vars->map[1]) - 1)
		{
			if (vars->map[i][j] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->data.exit, 64*j, 64*i);
			j++;
		}
		i++;
	}
}

void	img(t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->data.exit = mlx_xpm_file_to_image(vars->mlx, "exit3.xpm", &img_width, &img_height);
	if (!vars->data.exit)
		return;
	vars->data.collect = mlx_xpm_file_to_image(vars->mlx, "coin.xpm", &img_width, &img_height);
	if (!vars->data.collect)
		return;
	vars->data.back = mlx_xpm_file_to_image(vars->mlx, "back.xpm", &img_width, &img_height);
	if (!vars->data.back)
		return;
	vars->data.perso = mlx_xpm_file_to_image(vars->mlx, "perso.xpm", &img_width, &img_height);
		if (!vars->data.perso)
		return;
	vars->data.wall = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", &img_width, &img_height);
	if (!vars->data.wall)
		return;
}



void	ft_key_up(t_vars *vars)
{
	if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == '0')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_y--;
	}
	else if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == 'C')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y - 1][vars->player_pos_x] = '0';
		vars->collect++;
		vars->player_pos_y--;
	}
	else if (vars->map[vars->player_pos_y - 1][vars->player_pos_x] == 'E' && vars->collect == vars->max_collect)
	{
		ft_free_tab(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		// vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "win");
		// vars->data.win = mlx_xpm_file_to_image(vars->mlx, "win.xpm", &vars->data.width, &vars->data.height);
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->data.win, 0, 0);
		// mlx_key_hook(vars->win, ft_close, vars);
		// mlx_loop(vars->mlx);
	}
	image_perso(vars);
}

void ft_key_down(t_vars *vars)
{
	if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == '0')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_y++;
	}
	else if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == 'C')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y + 1][vars->player_pos_x] = '0';
		vars->collect++;
		vars->player_pos_y++;
	}
	else if (vars->map[vars->player_pos_y + 1][vars->player_pos_x] == 'E' && vars->collect == vars->max_collect)
	{
		ft_free_tab(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		// vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "win");
		// vars->data.win = mlx_xpm_file_to_image(vars->mlx, "win.xpm", &vars->data.width, &vars->data.height);
		// mlx_put_image_to_window(vars->mlx, vars->win, vars->data.win, 0, 0);
		// mlx_key_hook(vars->win, ft_close, vars);
		// mlx_loop(vars->mlx);
	}
	image_perso(vars);
}

void	ft_key_right(t_vars *vars)
{
	if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == '0')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_x++;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == 'C')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y][vars->player_pos_x + 1] = '0';
		vars->collect++;
		vars->player_pos_x++;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x + 1] == 'E' && vars->collect == vars->max_collect)
	{
		ft_free_tab(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		// vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "win");
		// vars->data.win = mlx_xpm_file_to_image(vars->mlx, "win.xpm", &vars->data.width, &vars->data.height);
		// mlx_put_image_to
	}
	image_perso(vars);
}

void	ft_key_left(t_vars *vars)
{
	if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == '0')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->player_pos_x--;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == 'C')
	{
		vars->map[vars->player_pos_y][vars->player_pos_x] = '0';
		mlx_put_image_to_window(vars->mlx, vars->win, vars->data.back, vars->player_pos_x * 64, vars->player_pos_y * 64);
		vars->map[vars->player_pos_y][vars->player_pos_x - 1] = '0';
		vars->collect++;
		vars->player_pos_x--;
	}
	else if (vars->map[vars->player_pos_y][vars->player_pos_x - 1] == 'E' && vars->collect == vars->max_collect)
	{
		ft_free_tab(vars->map);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
		// vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "win");
		// vars->data.win = mlx_xpm_file_to_image(vars->mlx, "win.xpm", &vars->data.width, &vars->data.height);
		// mlx_put_image
	}
	image_perso(vars);
}

int	ft_close(int keycode, t_vars *vars)
{
	// printf("%i", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if	(keycode == 119)
		ft_key_up(vars);
	if	(keycode == 115)
		ft_key_down(vars);
	if	(keycode == 97)
		ft_key_left(vars);
	if	(keycode == 100)
		ft_key_right(vars);
	if (keycode)
		printf("%i\n%i\n", vars->collect, vars->max_collect);
	return (0);
}

void test(t_vars *vars)
{
	mlx_hook(vars->win, 2, 1L<<0, ft_close, vars);
	// mlx_hook(vars->win, 2, 1L<<0, ft_key_up, vars);
	// mlx_hook(vars->win, 2, 1L<<0, ft_key_down, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars vars;

	vars.collect = 0;
	(void)ac;
	parse_map(av[1], &vars);
	check_map(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ((int)ft_strlen(vars.map[1]) -1) * 64, ft_strstrlen(vars.map) * 64, "so_long");
	img(&vars);
	image_wall(&vars);
	image_perso(&vars);
	image_back(&vars);
	image_exit(&vars);
	image_collect(&vars);
	test(&vars);
	// printf("oui");
	ft_free_tab(vars.map);
	return (0);
}

