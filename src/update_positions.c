/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_positions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:49:38 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/08 15:24:41 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_positions(t_stack **a)
{
	t_stack	*current;
	int		i;

	i = 1;
	current = *a;
	while (current)
	{
		current->position = i++;
		if (current->next != NULL)
			current->next->prev = current;
		current = current->next;
	}
}
