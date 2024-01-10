/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_end_chunk.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:59:16 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/09 23:22:51 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_chunk_amt(int total)
{
	if (total >= 300)
		return (13);
	else if (total >= 160)
		return (10);
	else if (total >= 140)
		return (7);
	else if (total >= 120)
		return (5);
	else if (total >= 100)
		return (5);
	else if (total >= 80)
		return (4);
	else if (total >= 60)
		return (6);
	else if (total >= 40)
		return (2);
	else if (total >= 10)
		return (2);
	else
		return (1);
}

void	get_start_end_index(int *start, int *end, int total)
{
	t_variables	t;
	static int	s_start = 0;
	static int	iterations = 1;
	int			chunk_amt;

	chunk_amt = get_chunk_amt(total);
	t.chunk_size = total / chunk_amt;
	*start = s_start;
	s_start += t.chunk_size;
	if (iterations == get_chunk_amt(total))
		*end = total - 1;
	else
		*end = s_start - 1;
	iterations += 1;
}
