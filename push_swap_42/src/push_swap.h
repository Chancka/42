/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:51:10 by cboudrin          #+#    #+#             */
/*   Updated: 2022/02/28 15:48:43 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "printf/ft_printf.h"

typedef struct s_node
{
	int		*tab;
	int		size;
	char	c;
}	t_node;

void	ft_swap(int	*a, int	*b);

void	ft_push(t_node *from, t_node *to);

void	ft_swap_bis(t_node *list);

void	ft_rotate(t_node *list);

void	ft_reverse_rotate(t_node *list);

int	*find_percent(t_node stack, int argc);

int	nb_cut(int size);

void	ft_solve(t_node *stack_a, t_node *stack_b, int argc);

void	four_solve(t_node *a, t_node *b);

void	three_solve(t_node *list);

int	is_sorted(t_node *a);

#endif