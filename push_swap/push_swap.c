/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <cboudrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:02:56 by cboudrin          #+#    #+#             */
/*   Updated: 2022/02/23 14:40:40 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	*split_args(char **argv)
{
	int	i;
	char **tab;
	int *tab2;
	
	i = 0;
	tab = malloc(sizeof(char **));
	tab2 = malloc(sizeof(int *));
	tab = ft_split(argv[1], ' ');
	while (tab[i])
	{
		tab2[i] = ft_atoi(tab[i]);
		i++;
	}
	// printf("%i", i);
	free(tab);
	return (tab2);
}

int	len_tab(char **argv)
{
	int	i;
	char **tab;
	
	i = 0;
	tab = malloc(sizeof(char **));
	tab = ft_split(argv[1], ' ');
	while (tab[i])
	{
		i++;
	}
	return (i);
}

t_stack	*node_init(int value)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	node->num = value;
	node->next  = NULL;
	node->prev  = NULL;
	return (node);
}

t_stack *node_push(t_stack *root, int next_value)
{
    while (root->next != NULL)
		root = root->next;
    root->next = node_init(next_value);
    root->next->prev = root;
}

int node_len(t_stack *root)
{
    int count;

	count = 0;
    while (root->next != NULL)
	{
        root = root->next;
        ++count;
    }
    return count;
}

void	ft_sa(t_stack *stack_a)
{
	t_stack	*temp;

	temp = node_init(stack_a->num);
	// printf("%i\n", temp->num);
	// printf("%i", stack_a->num);
	stack_a->num = stack_a->next->num;
	stack_a->next->num = temp->num;
}

int main(int argc, char **argv)
{
	int *tab;
	int	i;
	t_stack *stack_a;

	i = 0;
	if (argc == 2)
	{
		tab = malloc(sizeof(int) * (len_tab(argv) + 1));
		tab = split_args(argv);
		stack_a = node_init(tab[i]);
		while (++i < len_tab(argv))
			node_push(stack_a, tab[i]);
		printf("avant : \n%i\n", stack_a->num);
    	while (stack_a->next != NULL)
		{
	        stack_a = stack_a->next;
			printf("%i\n", stack_a->num);
		}
		while (stack_a->prev != NULL)
	        stack_a = stack_a->prev;
		ft_sa(stack_a);
		printf("apres : \n%i\n", stack_a->num);
		while (stack_a->next != NULL)
		{
	        stack_a = stack_a->next;
			printf("%i\n", stack_a->num);
		}

	}
}