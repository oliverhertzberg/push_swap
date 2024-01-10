/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:19 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/06 01:13:46 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	triple_sort(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	if (is_sorted(*a))
		return ;
	x = (*a)->num;
	y = (*a)->next->num;
	z = (*a)->next->next->num;
	if (x < y && x < z)
		rra_sa(a);
	else if (z > x && z > y)
		sa(a);
	else if (y > x && y > z && x > z)
		rra(a);
	else if (z < y && z < x)
		ra_sa(a);
	else
		ra(a);
}
