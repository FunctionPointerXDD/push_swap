/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystack_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:52:10 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 15:55:55 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_empty(t_stack *s)
{
	if (s->top == -1)
		return (1);
	return (0);
}

int	is_full(t_stack *s)
{
	if (s->top == (s->capacity - 1))
		return (1);
	return (0);
}

void	init_stack(t_stack *s, int cnt)
{
	s->top = -1;
	s->size = 0;
	s->capacity = cnt - 1;
	s->data = malloc(sizeof(int) * (cnt - 1));
	if (!(s->data))
		return ;
}

void	push(t_stack *s, int item)
{
	if (is_full(s))
	{
		return ;
	}
	(s->top)++;
	s->size++;
	s->data[s->top] = item;
}

int	pop(t_stack *s)
{
	int	ret;

	if (is_empty(s))
	{
		return (0);
	}
	ret = s->data[s->top];
	(s->top)--;
	s->size--;
	return (ret);
}
