/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_sa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:57:03 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/04 13:12:21 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra_sa(t_stack **a)
{
	ft_reverse_rotate(a);
	ft_swap(a);
	ft_printf("rra\n");
	ft_printf("sa\n");
}
