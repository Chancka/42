/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:46 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/31 16:59:36 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data {
	void	*wall;
	void	*collect;
	void	*perso;
	void	*back;
	void	*exit;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	t_data	data;
	void	*win;
	char 	**map;
	int		player_pos_x;
	int		player_pos_y;
	int		collect;
	int		max_collect;
	int		move_count;
	char	*move_count_char;
}				t_vars;

int	check_map(t_vars *vars);
int	check_top_botom(t_vars *vars);
int	longueur(char *str);
int	largeur(char *str);
void	parse_map(char *argv, t_vars *vars);
void	ft_free_tab(char **tab);
int	ft_strstrlen(char **str);



#endif