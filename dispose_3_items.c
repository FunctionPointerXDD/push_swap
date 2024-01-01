/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose_3_items.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:40:27 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 14:38:49 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_f1(t_stack *a, t_stack *b);
void	a_f2(t_stack *a, t_stack *b);
void	a_f3(t_stack *a, t_stack *b);
void	a_f4(t_stack *a, t_stack *b);
void	a_f5(t_stack *a, t_stack *b);
void	b_f1(t_stack *a, t_stack *b);
void	b_f2(t_stack *a, t_stack *b);
void	b_f3(t_stack *a, t_stack *b);
void	b_f4(t_stack *a, t_stack *b);
void	b_f5(t_stack *a, t_stack *b);

void	sort_b_stack(t_stack *a, t_stack *b)
{
	int	x;
	int	y;
	int	z;

	x = b->data[b->top];
	y = b->data[b->top - 1];
	z = b->data[b->top - 2];
	if (x > y && y > z)
	{
		stack_operator(a, b, pa);
		stack_operator(a, b, pa);
		stack_operator(a, b, pa);
	}
	else if (x > z && z > y)
		b_f1(a, b);
	else if (y < x && x < z)
		b_f2(a, b);
	else if (y > x && x > z)
		b_f3(a, b);
	else if (x < y && y < z)
		b_f4(a, b);
	else if (x < z && z < y)
		b_f5(a, b);
}

void	sort_a_stack(t_stack *a, t_stack *b)
{
	int	x;
	int	y;
	int	z;

	x = a->data[a->top];
	y = a->data[a->top - 1];
	z = a->data[a->top - 2];
	if (x > y && y > z)
		a_f1(a, b);
	else if (x > y && y < z && x > z)
		a_f2(a, b);
	else if (x > y && y < z && x < z)
		a_f3(a, b);
	else if (x < y && y > z && x > z)
		a_f4(a, b);
	else if (x < y && y > z && x < z)
		a_f5(a, b);
}
