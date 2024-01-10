/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_pointer_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:05:12 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/10 18:11:32 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_double_pointer_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
	{
		free (array);
		return ;
	}
	while (array[i])
		free(array[i++]);
	free (array);
}
