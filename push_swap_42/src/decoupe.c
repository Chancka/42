/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoupe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:45:23 by cboudrin          #+#    #+#             */
/*   Updated: 2022/02/28 14:50:58 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*array_sort(int *tab, int size)
{
	int	count;
	int	i;
	int	tmp;

	count = 0;
	while (count < size)
	{
		i = 0;
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		count++;
	}
	return (tab);
}

int	nb_cut(int size)
{
	if (size <= 20)
		return (3);
	if (size <= 100)
		return (5);
	if (size <= 200)
		return (6);
	if (size <= 300)
		return (8);
	if (size <= 400)
		return (10);
	if (size <= 600)
		return (7);
	return (12);
}

int	*fill_tab(t_node stack, int ac)
{
	int	*tab;
	int	i;

	tab = malloc(sizeof(int) * ac);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < stack.size)
	{
		tab[i] = stack.tab[i];
		i++;
	}
	return (tab);
}

int	*find_percent(t_node stack, int argc)
{
	int	*tab;
	int	i;
	int	*ret;	

	i = 1;
	tab = fill_tab(stack, argc);
	ret = malloc(sizeof(int) * nb_cut(argc - 1) + 4);
	if (!ret)
		return (NULL);
	tab = array_sort(tab, argc - 1);
	while (i < nb_cut(argc - 1))
	{
		ret[i] = tab[(argc - 1) / nb_cut(argc) * i];
		i++;
	}
	ret[0] = tab[0];
	ret[i] = tab[argc - 2];
	free(tab);
	return (ret);
}