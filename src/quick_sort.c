/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohertzbe <ohertzbe@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:12:59 by ohertzbe          #+#    #+#             */
/*   Updated: 2024/01/04 17:26:14 by ohertzbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[high]);
	return (i);
}

void	quick_sorter(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sorter(arr, low, pi - 1);
		quick_sorter(arr, pi + 1, high);
	}
}

void	quick_sort(int arr[], int N)
{
	quick_sorter(arr, 0, N - 1);
}
