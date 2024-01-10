/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   efficient_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:07:44 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 18:23:53 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	search_for_chunk(int chunk[], int length, t_stack *a)
{
	t_variables	t;

	t.current = a;
	while (t.current)
	{
		t.i = 0;
		while (t.i < length)
		{
			if (chunk[t.i] == t.current->num)
				return (0);
			t.i++;
		}
		t.current = t.current->next;
	}
	return (1);
}

int	node_to_push(t_stack **a, t_stack *top_node, t_stack *bot_node)
{
	t_variables	t;

	if (top_node == NULL)
		return (bot_node->position);
	if (bot_node == NULL)
		return (top_node->position);
	t.top_cost = calculate_cost(a, top_node);
	t.bot_cost = calculate_cost(a, bot_node);
	if (t.top_cost <= t.bot_cost)
		return (top_node->position);
	return (bot_node->position);
}

int	sort_b(t_stack **b, t_stack **a)
{
	t_variables		t;
	static t_stack	*min = NULL;
	static t_stack	*max = NULL;

	t.return_rb = 0;
	if ((*b) == NULL)
	{
		pb_no_write(a, b);
		min = (*b);
		max = (*b);
		return (0);
	}
	else if ((*a)->num < min->num)
	{
		insert_min(a, b, min, &t.return_rb);
		min = (*b);
	}
	else if ((*a)->num > max->num)
	{
		insert_max(a, b, max, &t.return_rb);
		max = (*b);
	}
	else
		insert_num(a, b, &t.return_rb);
	return (t.return_rb);
}

int	sort_chunks(t_stack **a, t_stack **b, int sorted_copy[], int total)
{
	t_variables	t;
	static int	chunk_rb = 0;

	t.chunk_sorted = 0;
	t.start = 0;
	t.end = 0;
	get_start_end_index(&t.start, &t.end, total);
	t.length = t.end - t.start + 1;
	while (t.chunk_sorted == 0)
	{
		t.top_node = get_top_node(a, &sorted_copy[t.start], t.length);
		t.bot_node = get_bot_node(a, &sorted_copy[t.start], t.length);
		t.node_position = node_to_push(a, t.top_node, t.bot_node);
		t.return_ra = rotate_a(a, t.node_position);
		t.return_rb = sort_b(b, a);
		write_instructions(&chunk_rb, &t.return_ra, &t.return_rb);
		ft_printf("pb\n");
		update_positions(a);
		update_positions(b);
		t.chunk_sorted = search_for_chunk(&sorted_copy[t.start], t.length, *a);
	}
	chunk_rb = 0;
	chunk_rb = rotate_b(b);
	return (chunk_rb);
}

int	efficient_sort(t_stack **a, t_stack **b, int *total)
{
	t_variables	t;

	t.sorted_copy = (int *)malloc(sizeof(int) * (*total));
	if (t.sorted_copy == NULL)
		return (-1);
	get_sorted_copy(t.sorted_copy, *total, *a);
	t.chunk_amt = get_chunk_amt(*total) + 1;
	while (--t.chunk_amt > 0)
		t.final_rb = sort_chunks(a, b, t.sorted_copy, *total);
	final_rotation_b(t.final_rb);
	while (*b)
		pa(a, b);
	free (t.sorted_copy);
	return (0);
}
