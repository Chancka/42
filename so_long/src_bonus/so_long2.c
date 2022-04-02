/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:33:32 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 15:42:10 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	destroy_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data.exit);
	mlx_destroy_image(vars->mlx, vars->data.collect);
	mlx_destroy_image(vars->mlx, vars->data.back);
	mlx_destroy_image(vars->mlx, vars->data.perso);
	mlx_destroy_image(vars->mlx, vars->data.wall);
	mlx_destroy_image(vars->mlx, vars->data.start);
	mlx_destroy_image(vars->mlx, vars->data.option);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	ft_free_tab(vars->map);
	free(vars->mlx);
	return ;
}

void	ft_move_count(t_vars *vars)
{
	char	*str;

	if (!vars->data.wall)
		return ;
	str = ft_itoa(vars->move_count);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data.wall, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 32, 32, 0xFFFFFF, str);
	ft_printf("Move count : %d\n", vars->move_count);
	free(str);
}

int	ft_close_cross(t_vars *vars)
{
	destroy_img(vars);
	ft_printf("you have clicked on the red cross.\n");
	exit(0);
}

int	ft_option(int button, int x, int y, t_vars *vars)
{
	int	i;
	int	j;

	i = ((int)ft_strlen(vars->map[1]) - 1) * 32;
	j = ft_strstrlen(vars->map) * 64;
	if (button == 1 && x > i && x < i + 100 && y > j - 36 && y < j + 36)
	{
		if (vars->option == 0)
		{
			vars->option = 1;
			ft_img_bonus(vars);
			image_bonus(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->data.option,
				i - 18, j - 36);
		}
		else
		{
			vars->option = 0;
			ft_img_bonus2(vars);
			image_bonus(vars);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->data.option,
				i - 18, j - 36);
		}
	}
	return (0);
}
