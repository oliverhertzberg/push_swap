/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:52:09 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 13:21:54 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_len(t_stack **node)
{
	t_variables	t;

	t.current = *node;
	t.i = 0;
	while (t.current)
	{
		t.i++;
		t.current = t.current->next;
	}
	return (t.i);
}
