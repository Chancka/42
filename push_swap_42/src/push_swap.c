/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:54:38 by cboudrin          #+#    #+#             */
/*   Updated: 2022/02/28 16:10:43 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int init(t_node *a, t_node *b, int argc)
{
	a->c = 'a';
	a->tab = malloc(sizeof(int) * argc - 1);
	if (!a->tab)
		return (1);
	a->size = argc - 1;
	b->c = 'b';
	b->tab = malloc(sizeof(int) * argc - 1);
	if (!b->tab)
		return (1);
	b->size = 0;

	return (0);
}

void	insert(t_node *a, char ** argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		a->tab[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
}

int	is_sorted(t_node *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		printf("[%i] : %i\n", i, a->tab[i]);
		if (a->tab[i] > a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_node a;
	t_node b;

	if (init(&a, &b, argc))
		return (0);
	insert(&a, argv);
	// ft_printf("a[0] : %i\na[1] : %i\na[2] : %i\n", a.tab[0], a.tab[1], a.tab[2]);
	// ft_swap_bis(&a);
	// ft_printf("a[0] : %i\na[1] : %i\na[2] : %i\n", a.tab[0], a.tab[1], a.tab[2]);
	// ft_reverse_rotate(&a);
	// ft_printf("a[0] : %i\na[1] : %i\na[2] : %i\n", a.tab[0], a.tab[1], a.tab[2]);
	ft_solve(&a, &b, argc);
	if (is_sorted(&a))
		printf("prout");
}