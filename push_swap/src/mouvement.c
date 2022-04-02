/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:29:34 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/02 13:19:04 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_bis(t_node *list)
{
	int	temp;

	if (list->size <= 0)
		return ;
	temp = list->tab[0];
	list->tab[0] = list->tab[1];
	list->tab[1] = temp;
	ft_printf("s%c\n", list->c);
}

void	ft_swap(int	*a, int	*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_push(t_node *from, t_node *to)
{
	int	i;

	i = 1;
	if (from->size <= 0)
		return ;
	else
	{
		to->size++;
		while (i < to->size)
		{
			ft_swap(&to->tab[to->size - i], &to->tab[to->size - i - 1]);
			i++;
		}
		to->tab[0] = from->tab[0];
		i = 0;
		while (i < from->size - 1)
		{
			from->tab[i] = from->tab[i + 1];
			i++;
		}
		from->size--;
		ft_printf("p%c\n", to->c);
	}
}

void	ft_rotate(t_node *list)
{
	int	i;

	i = 0;
	if (list->size <= 0)
		return ;
	while (i < list->size - 1)
	{
		ft_swap(&list->tab[i], &list->tab[i + 1]);
		i++;
	}
	ft_printf("r%c\n", list->c);
}

void	ft_reverse_rotate(t_node *list)
{
	int	i;

	i = list->size - 1;
	if (list->size <= 0)
		return ;
	while (i > 0)
	{
		ft_swap(&list->tab[i], &list->tab[i - 1]);
		i--;
	}
	ft_printf("rr%c\n", list->c);
}
