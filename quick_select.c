/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:15 by chansjeo          #+#    #+#             */
/*   Updated: 2024/01/01 13:00:15 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
		++j;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

int	quick_select(int arr[], int low, int high, int k)
{
	int	pi;

	if (low >= high)
		return (arr[low]);
	else
	{
		pi = partition(arr, low, high);
		if (pi == k)
			return (arr[pi]);
		else if (pi < k)
			return (quick_select(arr, pi + 1, high, k));
		else
			return (quick_select(arr, low, pi - 1, k));
	}
}
