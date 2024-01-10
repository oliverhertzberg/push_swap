/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_big_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:53:07 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 20:00:56 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_for_big_num(char *string)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	if (string[i] == '-')
		i++;
	while (string[i++])
		count++;
	if (count > 10)
		return (1);
	return (0);
}
