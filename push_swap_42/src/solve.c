/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:06:47 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/01 11:48:46 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_moove(t_node *stack, int index)
{
	int	reverse;

	reverse = stack->size - index;
	if (reverse < index)
	{
		while (reverse > 0)
		{
			ft_reverse_rotate(stack);
			reverse--;
		}
	}
	else
	{
		while (index > 0)
		{
			ft_rotate(stack);
			index--;
		}
	}
}

void	ft_solve_pa(t_node *stack_a, t_node *stack_b)
{
	int	i;
	int	min;
	int	j;

	j = 0;
	while (stack_b->size)
	{
		min = stack_b->tab[0];
		i = 0;
		while (i < stack_b->size)
		{
			if (min <= stack_b->tab[i])
			{
				min = stack_b->tab[i];
				j = i;
			}
			i++;
		}
		if (j)
		{
			count_moove(stack_b, j);
		}
		ft_push(stack_b, stack_a);
	}
}

void	ft_reverse_solve(t_node *a, t_node *b, int *tab, int i)
{
	int	j;

	j = 0;
	while (j < a->size - 1)
	{
		if (a->tab[0] >= tab[i] && a->tab[0] <= tab[i + 1])
		{
			ft_push(a, b);
			j--;
		}
		else if (a->tab[0] > tab[i + 2])
			break ;
		else
		{
			ft_reverse_rotate(a);
			j++;
		}
	}
	while (j + 1)
	{
		ft_rotate(a);
		j--;
	}
	return ;
}

void	ft_solve(t_node *stack_a, t_node *stack_b, int argc)
{
	int	*tab;
	int	i;
	int	j;
	int	med;

	tab = find_percent((*stack_a), argc);
	i = nb_cut(argc - 1);
	med = i / 2;
	i--;
	while (i + 1)
	{
		j = 0;
		while (j < stack_a->size && i > med)
		{
			if (stack_a->tab[0] >= tab[i] && stack_a->tab[0] <= tab[i + 1])
				ft_push(stack_a, stack_b);
			else
				(ft_rotate(stack_a), j++);
		}
		if (med >= i)
			ft_reverse_solve(stack_a, stack_b, tab, i);
		i--;
		ft_solve_pa(stack_a, stack_b);
	}
	free(tab);
}