/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:41:11 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/29 15:32:12 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*data;
	void	*win;
	char 	**map;
	int		collec;
	int		max_collect;
	int		move_count;
	char	*move_count_char;
}				t_vars;

// int	start(int x, int y, void *param)
// {
// 	void	*mlx;
// 	t_vars	*vars;
	
// 	vars = (t_vars*)param;
// 	mlx = vars->mlx;
// 	if (!mlx)
// 		return (0);
// 	if (x < 400 && x > 220 && y < 240 && y > 180)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->data);
// 	}
// 	return (0);
// }

// int	key_hook(int keycode, t_vars *vars)
// {
// 	(void)vars;
// 	(void)keycode;
// 	mlx_destroy_image(vars->mlx, vars->img);
// 	// printf ("Hello from key_hook\n");
// 	return (0);
// }

int	started(int button, int x, int y, t_vars *vars)
{
	int		img_width;
	int		img_height;

	if (x < 400 && x > 220 && y < 240 && y > 180)
	{
		if (button == 1)
		{
			vars->data = mlx_xpm_file_to_image(vars->mlx, "./img/none.xpm", &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 220, 180);
		}
	}
	return 1;
}

int	move_count(int keycode, t_vars *vars)
{
	printf("keycode : %i\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == 119)
		vars->move_count++;
	vars->move_count_char = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 220, 180);
	mlx_string_put(vars->mlx, vars->win, 280, 220, 0xFFFFFF, vars->move_count_char);
	free(vars->move_count_char);
	vars->move_count_char = NULL;
	return (0);
}

int	start(t_vars *vars)
{
	int		img_width;
	int		img_height;
	
	vars->data = mlx_xpm_file_to_image(vars->mlx, "./img/start.xpm", &img_width, &img_height);
	if (!vars->data)
		return 0;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data, 220, 180);
	mlx_mouse_hook(vars->win, started, vars);
	return(1);
}

int	main(void)
{
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.move_count = 0;
	// if (vars.mlx)
	// 	return ;
	vars.win = mlx_new_window(vars.mlx, 640, 480, "so_long");
	start(&vars);
	mlx_hook(vars.win, 2, 1L<<0, move_count, &vars);
	mlx_loop(vars.mlx);
}

