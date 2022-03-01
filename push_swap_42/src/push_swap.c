/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:54:38 by cboudrin          #+#    #+#             */
/*   Updated: 2022/03/01 13:36:13 by cboudrin         ###   ########.fr       */
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

void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void	ft_putstr_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_error(str[i]);
		i++;
	}
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}
int	insert(t_node *a, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		if (ft_is_digit(argv[j]))
		{
			if (ft_atoi_l(argv[j]) > 2147483647 || ft_atoi_l(argv[j]) < -2147483648)
				{
					free(a->tab);
					ft_putstr_error("Error\n");
					return (1);
				}
			a->tab[i] = ft_atoi(argv[j]);
		}
		else
		{
			free(a->tab);
			ft_putstr_error("Error\n");
			return (1);
		}
		i++;
		j++;
	}
	return (0);
}

int	is_sorted(t_node *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
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
	if (insert(&a, argv) || is_sorted(&a))
		return (0);
	if (check_doubles(&a))
	{
		free(a.tab);
		ft_putstr_error("Error\n");
		return (0);
	}
	ft_solve_all(&a, &b);
}