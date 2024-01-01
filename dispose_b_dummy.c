/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose_b_dummy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:30:13 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 15:18:49 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_f1(t_stack *a, t_stack *b)
{
	stack_operator(a, b, pa);
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, pa);
}

void	b_f2(t_stack *a, t_stack *b)
{
	stack_operator(a, b, pa);
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, sa);
	stack_operator(a, b, pa);
}

void	b_f3(t_stack *a, t_stack *b)
{
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, pa);
	stack_operator(a, b, pa);
}

void	b_f4(t_stack *a, t_stack *b)
{
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, sa);
	stack_operator(a, b, pa);
}

void	b_f5(t_stack *a, t_stack *b)
{
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, sb);
	stack_operator(a, b, pa);
	stack_operator(a, b, pa);
}
