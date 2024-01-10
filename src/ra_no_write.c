/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_no_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:30:41 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 13:22:25 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_no_write(t_stack **a, int *return_ra)
{
	ft_rotate(a);
	*return_ra += 1;
}
