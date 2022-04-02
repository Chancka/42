/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:32:34 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/23 15:25:12 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_solve(t_node *list)
{
	if (list->size <= 0)
		return ;
	if (list->tab[0] > list->tab[1] && list->tab[1] < list->tab[2]
		&& list->tab[0] < list->tab[2])
		ft_swap_bis(list);
	else if (list->tab[0] > list->tab[1] && list->tab[1] > list->tab[2]
		&& list->tab[0] > list->tab[2])
	{
		ft_swap_bis(list);
		ft_reverse_rotate(list);
	}
	else if (list->tab[0] > list->tab[1] && list->tab[1] < list->tab[2]
		&& list->tab[0] > list->tab[2])
		ft_rotate(list);
	else if (list->tab[0] < list->tab[1] && list->tab[1] > list->tab[2]
		&& list->tab[0] < list->tab[2])
	{
		ft_swap_bis(list);
		ft_rotate(list);
	}
	else if (list->tab[0] < list->tab[1] && list->tab[1] > list->tab[2]
		&& list->tab[0] > list->tab[2])
		ft_reverse_rotate(list);
}

int	find_median(int *argv, int argc)
{
	int	median;
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * argc);
	if (!tab)
		return (0);
	while (i < argc)
	{
		tab[i] = argv[i];
		i++;
	}
	tab = array_sort(tab, argc);
	if (argc % 2 == 0)
		median = tab[(argc / 2) - 1];
	else
		median = tab[(argc / 2)];
	free(tab);
	return (median);
}

void	five_solve(t_node *a, t_node *b)
{
	int	median;
	int	i;

	i = 0;
	median = find_median(a->tab, a->size);
	while (i < a->size)
	{
		if (a->tab[0] < median)
			ft_push(a, b);
		else
		{
			ft_rotate(a);
			i++;
		}
	}
	three_solve(a);
	if (b->size > 1)
	{
		if (b->tab[0] < b->tab[1])
			ft_swap_bis(b);
	}
	while (b->size)
		ft_push(b, a);
}

void	solve_two(t_node *a)
{
	ft_swap_bis(a);
}

void	ft_solve_all(t_node *a, t_node *b)
{
	if (a->size == 2)
		solve_two(a);
	else if (a->size == 3)
		three_solve(a);
	else if (a->size == 4 || a->size == 5)
		five_solve(a, b);
	else if (a->size > 5)
		ft_solve(a, b, a->size + 1);
}
