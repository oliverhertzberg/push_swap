/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_no_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:48:48 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 13:22:14 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrb_no_write(t_stack **b, int *return_rb)
{
	ft_reverse_rotate(b);
	*return_rb -= 1;
}
