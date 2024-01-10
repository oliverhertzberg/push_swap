/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions_and_cost.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:38:59 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/09 23:20:33 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_max(t_stack *node)
{
	t_variables	t;

	t.max = node;
	t.current = node;
	while (t.current)
	{
		if (t.current->num > t.max->num)
			t.max = t.current;
		t.current = t.current->next;
	}
	return (t.max);
}

int	get_last(t_stack *node)
{
	t_variables	t;

	t.current = node;
	if (node->next == NULL)
		return (node->num);
	while (t.current->next)
		t.current = t.current->next;
	return (t.current->num);
}

t_stack	*get_last_node(t_stack *node)
{
	t_variables	t;

	t.current = node;
	while (t.current && t.current->next)
		t.current = t.current->next;
	return (t.current);
}

void	get_sorted_copy(int *arr, int N, t_stack *a)
{
	t_variables	t;

	t.i = 0;
	while (a)
	{
		arr[t.i++] = a->num;
		a = a->next;
	}
	quick_sort(arr, N);
}

int	calculate_cost(t_stack **a, t_stack *node)
{
	t_variables	t;

	t.ra = 0;
	t.len_stack = stack_len(a);
	if (node->position < (t.len_stack / 2))
		t.ra = 1;
	if (t.ra == 1)
		t.cost = node->position - 1;
	else
		t.cost = t.len_stack - node->position + 1;
	return (t.cost);
}
