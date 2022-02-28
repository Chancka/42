/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:32:34 by cboudrin          #+#    #+#             */
/*   Updated: 2022/02/28 16:12:15 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_solve(t_node *list)
{
	if (list->size <= 0)
		return ;
	if (list->tab[0] > list->tab[1] && list->tab[1] < list->tab[2] && list->tab[0] < list->tab[2])
		ft_swap_bis(list);
	else if (list->tab[0] > list->tab[1] && list->tab[1] > list->tab[2] && list->tab[0] > list->tab[2])
	{
		ft_swap_bis(list);
		ft_reverse_rotate(list);
	}
	else if (list->tab[0] > list->tab[1] && list->tab[1] < list->tab[2] && list->tab[0] > list->tab[2])
		ft_rotate(list);
	else if (list->tab[0] < list->tab[1] && list->tab[1] > list->tab[2] && list->tab[0] < list->tab[2])
	{
		ft_swap_bis(list);
		ft_rotate(list);
	}
	else if (list->tab[0] < list->tab[1] && list->tab[1] > list->tab[2] && list->tab[0] > list->tab[2])
		ft_reverse_rotate(list);
}

void	five_solve(t_node *a, t_node *b)
{
	if (a->size <= 0)
		return;
	three_solve(a);
}