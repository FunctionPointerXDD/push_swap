/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:52:41 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 15:48:04 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	qsort_b_to_a(t_stack *a, t_stack *b, int size)
{
	int	size_a;
	int	size_b;
	int	i;
	int	j;
	int	push;

	if (size < 4)
	{
		small_size_sort(a, b, size, B_STACK);
		return ;
	}
	pivot_and_init_cnt(a, b, size, B_STACK);
	general_sort_b(a, b, size);
	size_a = a->rotate;
	size_b = b->rotate;
	i = size_a;
	j = size_b;
	push = a->push;
	qsort_a_to_b(a, b, push - size_a);
	arrange_stack(a, b, i, j);
	qsort_a_to_b(a, b, size_a);
	qsort_b_to_a(a, b, size_b);
}

void	qsort_a_to_b(t_stack *a, t_stack *b, int size)
{
	int	size_a;
	int	size_b;
	int	push;

	if (size < 4)
	{
		small_size_sort(a, b, size, A_STACK);
		return ;
	}
	pivot_and_init_cnt(a, b, size, A_STACK);
	if (a->first)
		first_sort(a, b, size);
	else
		general_sort_a(a, b, size);
	size_a = a->rotate;
	size_b = b->rotate;
	push = b->push;
	if (a->first)
		size_b = b->push - b->rotate;
	if (!a->first)
		arrange_stack(a, b, size_a, size_b);
	a->first = 0;
	qsort_a_to_b(a, b, size_a);
	qsort_b_to_a(a, b, size_b);
	qsort_b_to_a(a, b, push - size_b);
}

void	general_sort_a(t_stack *a, t_stack *b, int size)
{
	while (size--)
	{
		a->tmp = a->data[a->top];
		if (a->high <= a->tmp)
		{
			stack_operator(a, b, ra);
			a->rotate++;
		}
		else
		{
			stack_operator(a, b, pb);
			b->push++;
			if (a->low <= a->tmp)
			{
				if (size > 0 && a->data[a->top] >= a->high)
				{
					special_case(a, b);
					size--;
				}
				else
					stack_operator(a, b, rb);
				b->rotate++;
			}
		}
	}
}

void	general_sort_b(t_stack *a, t_stack *b, int size)
{
	while (size--)
	{
		b->tmp = b->data[b->top];
		if (b->low >= b->tmp)
		{
			stack_operator(a, b, rb);
			b->rotate++;
		}
		else
		{
			stack_operator(a, b, pa);
			a->push++;
			if (b->high >= b->tmp)
			{
				stack_operator(a, b, ra);
				a->rotate++;
			}
		}
	}
}

void	arrange_stack(t_stack *a, t_stack *b, int size_a, int size_b)
{
	int	i;
	int	j;

	i = size_a;
	j = size_b;
	if (size_a > size_b)
	{
		while (j--)
			stack_operator(a, b, rrr);
		stack_operator(a, b, rra);
	}
	else if (size_a == size_b)
	{
		while (i--)
			stack_operator(a, b, rrr);
	}
	else
	{
		while (i--)
			stack_operator(a, b, rrr);
		stack_operator(a, b, rrb);
	}
}
