/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:47:45 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/22 18:32:38 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *box)
{
	int	tmp;

	if (box->top > 0)
	{
		tmp = box->data[box->top];
		box->data[box->top] = box->data[box->top - 1];
		box->data[box->top - 1] = tmp;
	}
}

void	pop_and_push(t_stack *x, t_stack *y)
{
	int	num;

	if (x->top != -1)
	{
		num = pop(x);
		push(y, num);
	}
}

void	rotation(t_stack *box)
{
	int	tmp;
	int	num;

	if (box->top != -1)
	{
		tmp = box->data[box->top];
		num = box->top;
		while (num > 0)
		{
			box->data[num] = box->data[num - 1];
			num--;
		}
		box->data[0] = tmp;
	}
}

void	rev_rotation(t_stack *box)
{
	int	tmp;
	int	num;

	if (box->top != -1)
	{
		num = 0;
		tmp = box->data[0];
		while (num != box->top)
		{
			box->data[num] = box->data[num + 1];
			num++;
		}
		box->data[box->top] = tmp;
	}
}

void	stack_operator(t_stack *a, t_stack *b, int oper)
{
	t_cmd	op;

	record_op(b, oper);
	op = oper;
	if (op == sa || op == ss)
		swap_stack(a);
	if (op == sb || op == ss)
		swap_stack(b);
	if (op == pa)
		pop_and_push(b, a);
	if (op == pb)
		pop_and_push(a, b);
	if (op == ra || op == rr)
		rotation(a);
	if (op == rb || op == rr)
		rotation(b);
	if (op == rra || op == rrr)
		rev_rotation(a);
	if (op == rrb || op == rrr)
		rev_rotation(b);
}
