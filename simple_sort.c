/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:47 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/20 15:54:31 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_items(t_stack *a, t_stack *b)
{
	int	x;
	int	y;
	int	z;

	x = a->data[a->top];
	y = a->data[a->top - 1];
	z = a->data[a->top - 2];
	if (x > y && y > z)
	{
		stack_operator(a, b, ra);
		stack_operator(a, b, sa);
	}
	else if (x > z && z > y)
		stack_operator(a, b, ra);
	else if (y < x && x < z)
		stack_operator(a, b, sa);
	else if (z < x && x < y)
		stack_operator(a, b, rra);
	else if (x < z && z < y)
	{
		stack_operator(a, b, sa);
		stack_operator(a, b, ra);
	}
}

void	sort_5_items(t_stack *a, t_stack *b, int size)
{
	ft_memcpy(a->arr, &(a->data[0]), size * sizeof(int));
	a->pivot = quick_select(a->arr, 0, size - 1, size / 2);
	while (size--)
	{
		if (a->pivot <= a->data[a->top])
			stack_operator(a, b, ra);
		else
			stack_operator(a, b, pb);
	}
	sort_3_items(a, b);
	if (b->data[b->top] < b->data[b->top - 1])
		stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, pa);
}

void	simple_sort(t_stack *a, t_stack *b, int size)
{
	if (size == 3)
		sort_3_items(a, b);
	else
		sort_5_items(a, b, size);
}
