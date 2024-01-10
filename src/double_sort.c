/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:56:53 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/04 13:10:31 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	double_sort(t_stack **stack)
{
	if (is_sorted(*stack))
		return ;
	ft_swap(stack);
	ft_printf("sa\n");
}
