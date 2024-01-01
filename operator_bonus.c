/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:42:23 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/23 14:22:19 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	checker_operator(t_stack *a, t_stack *b, char *op)
{
	if (ft_memcmp(op, "sa", 3) == 0 || ft_memcmp(op, "ss", 3) == 0)
		swap_stack(a);
	if (ft_memcmp(op, "sb", 3) == 0 || ft_memcmp(op, "ss", 3) == 0)
		swap_stack(b);
	if (ft_memcmp(op, "pa", 3) == 0)
		pop_and_push(b, a);
	if (ft_memcmp(op, "pb", 3) == 0)
		pop_and_push(a, b);
	if (ft_memcmp(op, "ra", 3) == 0 || ft_memcmp(op, "rr", 3) == 0)
		rotation(a);
	if (ft_memcmp(op, "rb", 3) == 0 || ft_memcmp(op, "rr", 3) == 0)
		rotation(b);
	if (ft_memcmp(op, "rra", 3) == 0 || ft_memcmp(op, "rrr", 3) == 0)
		rev_rotation(a);
	if (ft_memcmp(op, "rrb", 3) == 0 || ft_memcmp(op, "rrr", 3) == 0)
		rev_rotation(b);
}
