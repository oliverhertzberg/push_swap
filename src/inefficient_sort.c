/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inefficient_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:27 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/08 15:25:16 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_stack *a)
{
	int	min;
	int	position;

	min = a->num;
	position = a->position;
	while (a)
	{
		if (a->num < min)
		{
			min = a->num;
			position = a->position;
		}
		a = a->next;
	}
	return (position);
}

void	min_to_b(t_stack **a, t_stack **b, int *total)
{
	int	min;

	min = find_min(*a);
	while ((*a)->position != min)
	{
		if (min > (*total / 2))
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	update_positions(a);
	*total -= 1;
}

void	inefficient_sort(t_stack **a, t_stack **b, int *total)
{
	int	leave_three;

	leave_three = *total - 2;
	while (--leave_three)
		min_to_b(a, b, total);
	triple_sort(a);
	while (*b)
		pa(a, b);
}
