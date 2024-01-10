/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:43:26 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:02 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	final_rotation_b(int trb)
{
	while (trb > 0)
	{
		ft_printf("rb\n");
		trb--;
	}
	while (trb < 0)
	{
		ft_printf("rrb\n");
		trb++;
	}
}

int	rotate_b(t_stack **b)
{
	t_variables	t;

	t.len_stack = stack_len(b);
	t.max = get_max(*b);
	t.rb = 0;
	t.return_rb = 0;
	if (t.max->position < t.len_stack / 2)
		t.rb = 1;
	while ((*b)->num != t.max->num)
	{
		if (t.rb == 1)
			rb_no_write(b, &t.return_rb);
		else
			rrb_no_write(b, &t.return_rb);
	}
	return (t.return_rb);
}

int	rotate_a(t_stack **a, int node_position)
{
	t_variables	t;

	t.return_ra = 0;
	t.ra = 0;
	if (node_position == 1)
		return (0);
	t.len_stack = stack_len(a);
	if (node_position < (t.len_stack / 2))
	{
		t.ra = 1;
		t.rotate_amt = node_position - 1;
	}
	else
		t.rotate_amt = t.len_stack - node_position + 1;
	while (t.rotate_amt > 0)
	{
		if (t.ra == 1)
			ra_no_write(a, &t.return_ra);
		else
			rra_no_write(a, &t.return_ra);
		t.rotate_amt--;
	}
	return (t.return_ra);
}
