/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose_3_items_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:26:56 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 14:38:31 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_f1(t_stack *a, t_stack *b)
{
	stack_operator(a, b, sa);
	stack_operator(a, b, pb);
	stack_operator(a, b, sa);
	stack_operator(a, b, pa);
	stack_operator(a, b, sa);
}

void	a_f2(t_stack *a, t_stack *b)
{
	stack_operator(a, b, sa);
	stack_operator(a, b, pb);
	stack_operator(a, b, sa);
	stack_operator(a, b, pa);
}

void	a_f3(t_stack *a, t_stack *b)
{
	stack_operator(a, b, sa);
}

void	a_f4(t_stack *a, t_stack *b)
{
	stack_operator(a, b, pb);
	stack_operator(a, b, sa);
	stack_operator(a, b, pa);
	stack_operator(a, b, sa);
}

void	a_f5(t_stack *a, t_stack *b)
{
	stack_operator(a, b, pb);
	stack_operator(a, b, sa);
	stack_operator(a, b, pa);
}
