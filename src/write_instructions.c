/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:51:08 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/09 23:28:45 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	write_instructions(int *chunk_rb, int *tra, int *trb)
{
	if (*chunk_rb > 0 && *tra > 0)
		write_rr(chunk_rb, tra);
	if (*chunk_rb < 0 && *tra < 0)
		write_rrr(chunk_rb, tra);
	if (*chunk_rb > 0)
		write_rb(chunk_rb);
	else if (*chunk_rb < 0)
		write_rrb(chunk_rb);
	if (*tra > 0 && *trb > 0)
		write_rr(tra, trb);
	if (*tra < 0 && *trb < 0)
		write_rrr(tra, trb);
	if (*tra > 0)
		write_ra(tra);
	else if (*tra < 0)
		write_rra(tra);
	if (*trb > 0)
		write_rb(trb);
	else if (*trb < 0)
		write_rrb(trb);
}

void	write_ra(int *tra)
{
	while (*tra > 0)
	{
		ft_printf("ra\n");
		*tra -= 1;
	}
}

void	write_rra(int *tra)
{
	while (*tra < 0)
	{
		ft_printf("rra\n");
		*tra += 1;
	}
}
