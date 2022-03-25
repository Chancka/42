/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:58:46 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/25 16:59:49 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

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

#endif