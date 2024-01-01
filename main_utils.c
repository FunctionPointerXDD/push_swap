/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:27:33 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 15:59:39 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	record_op(t_stack *b, int oper)
{
	t_cmd	op;

	op = oper;
	if (op == sa)
		ft_strncat(b->record, "sa\n", 3);
	else if (op == sb)
		ft_strncat(b->record, "sb\n", 3);
	else if (op == ss)
		ft_strncat(b->record, "ss\n", 3);
	else if (op == pa)
		ft_strncat(b->record, "pa\n", 3);
	else if (op == pb)
		ft_strncat(b->record, "pb\n", 3);
	else if (op == ra)
		ft_strncat(b->record, "ra\n", 3);
	else if (op == rb)
		ft_strncat(b->record, "rb\n", 3);
	else if (op == rr)
		ft_strncat(b->record, "rr\n", 3);
	else if (op == rra)
		ft_strncat(b->record, "rra\n", 4);
	else if (op == rrb)
		ft_strncat(b->record, "rrb\n", 4);
	else if (op == rrr)
		ft_strncat(b->record, "rrr\n", 4);
}

void	free_data(t_stack *a, t_stack *b)
{
	if (a->capacity != -1)
	{
		free(a->data);
		free(b->data);
		free(a->arr);
		free(b->arr);
		free(b->record);
	}
}

int	free_split_data(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
		free(argv[i++]);
	free(argv);
	return (-1);
}

int	ft_dupl(int *num, int cnt)
{
	int	i;
	int	j;

	i = 0;
	while (i < cnt)
	{
		j = i + 1;
		while (j < cnt)
		{
			if (num[i] == num[j])
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

int	is_sort(int *data, int cnt)
{
	int	i;

	i = 0;
	cnt--;
	while (cnt--)
	{
		if (data[i] < data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
