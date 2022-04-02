/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:53:46 by cboudrin          #+#    #+#             */
/*   Updated: 2022/04/02 15:43:23 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H

# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_data {
	void	*wall;
	void	*collect;
	void	*perso;
	void	*back;
	void	*exit;
	void	*start;
	void	*option;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	t_data	data;
	void	*win;
	char	**map;
	int		player_pos_x;
	int		player_pos_y;
	int		collect;
	int		max_collect;
	int		move_count;
	int		option;
}				t_vars;

int		check_map(t_vars *vars);
int		check_top_botom(t_vars *vars);
int		largeur(char *str);
void	parse_map(char *argv, t_vars *vars);
void	ft_free_tab(char **tab);
int		ft_strstrlen(char **str);
int		ft_key(int keycode, t_vars *vars);
void	image_wall(t_vars *vars);
void	image_perso(t_vars *vars);
void	image_back(t_vars *vars);
void	image_collect(t_vars *vars);
void	image_exit(t_vars *vars);
void	image_bonus(t_vars *vars);
void	img(t_vars *vars);
void	ft_move_count(t_vars *vars);
void	destroy_img(t_vars *vars);
int		check_wrong_map_char(char **map);
int		ft_isber(char *str);
void	ft_img_bonus(t_vars *vars);
void	ft_img_bonus2(t_vars *vars);
void	destroy_img(t_vars *vars);
void	ft_move_count(t_vars *vars);
int		ft_close_cross(t_vars *vars);
int		ft_option(int button, int x, int y, t_vars *vars);

#endif