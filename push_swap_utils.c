/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:28:19 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/23 15:54:55 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivot_and_init_cnt(t_stack *a, t_stack *b, int size, int flag)
{
	if (flag == A_STACK)
	{
		a->high = pivot_selector(a, size, HIGH);
		a->low = pivot_selector(a, size, LOW);
	}
	else
	{
		b->high = pivot_selector(b, size, HIGH);
		b->low = pivot_selector(b, size, LOW);
	}
	a->rotate = 0;
	b->rotate = 0;
	a->push = 0;
	b->push = 0;
}

void	special_case(t_stack *a, t_stack *b)
{
	stack_operator(a, b, rr);
	a->rotate++;
}

int	pivot_selector(t_stack *x, int size, int flag)
{
	int	high;
	int	low;

	ft_memcpy(x->arr, &(x->data[x->top - size + 1]), size * sizeof(int));
	if (flag == HIGH)
	{
		if (size % 3 == 2)
			high = size * 2 / 3 + 2;
		else if (size % 3 == 1)
			high = size * 2 / 3 + 1;
		else
			high = size * 2 / 3;
		x->pivot = quick_select(x->arr, 0, size - 1, high - 1);
	}
	else
	{
		if (size % 3 == 2)
			low = size * 1 / 3 + 2;
		else if (size % 3 == 1)
			low = size * 1 / 3 + 1;
		else
			low = size * 1 / 3;
		x->pivot = quick_select(x->arr, 0, size - 1, low - 1);
	}
	return (x->pivot);
}

void	small_size_sort(t_stack *a, t_stack *b, int size, int flag)
{
	if (flag == A_STACK)
	{
		if (size == 2)
		{
			if (a->data[a->top] > a->data[a->top - 1])
				stack_operator(a, b, sa);
		}
		else if (size == 3)
			sort_a_stack(a, b);
	}
	else
	{
		if (size == 1)
			stack_operator(a, b, pa);
		else if (size == 2)
		{
			if (b->data[b->top] < b->data[b->top - 1])
				stack_operator(a, b, sb);
			stack_operator(a, b, pa);
			stack_operator(a, b, pa);
		}
		else if (size == 3)
			sort_b_stack(a, b);
	}
}

void	first_sort(t_stack *a, t_stack *b, int size)
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
			if (a->low > a->tmp)
			{
				stack_operator(a, b, rb);
				b->rotate++;
			}
		}
	}
}
