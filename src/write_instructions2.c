/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:53:20 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/09 22:53:53 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	write_rr(int *trb, int *tra)
{
	while (*trb > 0 && *tra > 0)
	{
		ft_printf("rr\n");
		*trb -= 1;
		*tra -= 1;
	}
}

void	write_rrr(int *trb, int *tra)
{
	while (*trb < 0 && *tra < 0)
	{
		ft_printf("rrr\n");
		*trb += 1;
		*tra += 1;
	}
}

void	write_rb(int *trb)
{
	while (*trb > 0)
	{
		ft_printf("rb\n");
		*trb -= 1;
	}
}

void	write_rrb(int *chunk_rb)
{
	while (*chunk_rb < 0)
	{
		ft_printf("rrb\n");
		*chunk_rb += 1;
	}
}
