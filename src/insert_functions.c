/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:56:46 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/09 23:24:21 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insert_num(t_stack **a, t_stack **b, int *trb)
{
	t_variables	t;

	t.current = *b;
	t.max = get_max(*b);
	t.num = (*a)->num;
	t.rb = 0;
	while (t.current)
	{
		if ((t.current->num > t.num) && (t.current->num < t.max->num))
			t.max = t.current;
		t.current = t.current->next;
	}
	t.len_stack = stack_len(b);
	if (t.max->position < (t.len_stack / 2))
		t.rb = 1;
	t.last = get_last(*b);
	while (t.last != t.max->num)
	{
		if (t.rb == 1)
			rb_no_write(b, trb);
		else
			rrb_no_write(b, trb);
		t.last = get_last(*b);
	}
	pb_no_write(a, b);
}

void	insert_max(t_stack **a, t_stack **b, t_stack *max, int *trb)
{
	t_variables	t;

	t.len_stack = stack_len(b);
	t.rb = 0;
	if (max->position < t.len_stack / 2)
		t.rb = 1;
	while ((*b)->num != max->num)
	{
		if (t.rb == 1)
			rb_no_write(b, trb);
		else
			rrb_no_write(b, trb);
	}
	pb_no_write(a, b);
}

void	insert_min(t_stack **a, t_stack **b, t_stack *min, int *trb)
{
	t_variables	t;
	int			last;

	t.len_stack = stack_len(b);
	last = get_last(*b);
	t.rb = 0;
	if (min->position < t.len_stack / 2)
		t.rb = 1;
	while (last != min->num)
	{
		if (t.rb == 1)
			rb_no_write(b, trb);
		else
			rrb_no_write(b, trb);
		last = get_last(*b);
	}
	pb_no_write(a, b);
}
