/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:56:58 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/04 13:13:38 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack **node)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!node || !(*node) || !((*node)->next))
		return ;
	first_node = *node;
	second_node = (*node)->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*node = second_node;
}

void	ft_push(t_stack **push_from, t_stack **push_to)
{
	t_stack	*pushed;

	if (*push_from == NULL)
		return ;
	pushed = *push_from;
	*push_from = (*push_from)->next;
	pushed->next = *push_to;
	*push_to = pushed;
}

void	ft_rotate(t_stack **node)
{
	t_stack	*current;
	t_stack	*moved;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	moved = *node;
	*node = (*node)->next;
	current = *node;
	while (current->next != NULL)
		current = current->next;
	current->next = moved;
	moved->next = NULL;
}

void	ft_reverse_rotate(t_stack **node)
{
	t_stack	*moved;
	t_stack	*current;

	if (*node == NULL || (*node)->next == NULL)
		return ;
	current = *node;
	while (current->next->next != NULL)
		current = current->next;
	moved = current->next;
	current->next = NULL;
	moved->next = *node;
	*node = moved;
}
