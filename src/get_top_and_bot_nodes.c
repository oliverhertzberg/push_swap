/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_top_and_bot_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:47:53 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 13:19:28 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_top_node(t_stack **a, int sorted_copy[], int length)
{
	t_variables	t;

	t.current = *a;
	while (t.current)
	{
		t.i = 0;
		while (t.i < length)
		{
			if (t.current->num == sorted_copy[t.i])
				return (t.current);
			t.i++;
		}
		t.current = t.current->next;
	}
	return (NULL);
}

t_stack	*get_bot_node(t_stack **a, int sorted_copy[], int length)
{
	t_variables	t;

	t.current = get_last_node(*a);
	while (t.current->num != (*a)->num)
	{
		t.i = 0;
		while (t.i < length)
		{
			if (t.current->num == sorted_copy[t.i])
				return (t.current);
			t.i++;
		}
		t.current = t.current->prev;
	}
	return (NULL);
}
