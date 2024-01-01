/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:55:47 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 20:22:58 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	checker_record_op(t_stack *b, char *op)
{
	if (ft_memcmp(op, "sa\n", 4) == 0)
		ft_strncat(b->record, "sa\n", 3);
	else if (ft_memcmp(op, "sb\n", 4) == 0)
		ft_strncat(b->record, "sb\n", 3);
	else if (ft_memcmp(op, "ss\n", 4) == 0)
		ft_strncat(b->record, "ss\n", 3);
	else if (ft_memcmp(op, "pa\n", 4) == 0)
		ft_strncat(b->record, "pa\n", 3);
	else if (ft_memcmp(op, "pb\n", 4) == 0)
		ft_strncat(b->record, "pb\n", 3);
	else if (ft_memcmp(op, "ra\n", 4) == 0)
		ft_strncat(b->record, "ra\n", 3);
	else if (ft_memcmp(op, "rb\n", 4) == 0)
		ft_strncat(b->record, "rb\n", 3);
	else if (ft_memcmp(op, "rr\n", 4) == 0)
		ft_strncat(b->record, "rr\n", 3);
	else if (ft_memcmp(op, "rra\n", 4) == 0)
		ft_strncat(b->record, "rra\n", 4);
	else if (ft_memcmp(op, "rrb\n", 4) == 0)
		ft_strncat(b->record, "rrb\n", 4);
	else if (ft_memcmp(op, "rrr\n", 4) == 0)
		ft_strncat(b->record, "rrr\n", 4);
	else
		return (-1);
	return (0);
}

void	checker_free_data(t_stack *a, t_stack *b)
{
	if (a->capacity != -1)
	{
		free(a->data);
		free(b->data);
		free(b->record);
	}
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

int	bonus_is_sort(t_stack *a, t_stack *b, int cnt)
{
	int	i;

	if (b->top > -1)
		return (0);
	i = 0;
	cnt--;
	while (cnt--)
	{
		if (a->data[i] < a->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	my_checker(t_stack *a, t_stack *b, int size, int i)
{
	char	*tmp;
	char	**cmd;

	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (checker_record_op(b, tmp) < 0)
			return (bonus_free(tmp));
		free(tmp);
	}
	cmd = ft_split(b->record, '\n');
	if (!cmd)
		return (0);
	while (cmd && cmd[i])
		checker_operator(a, b, cmd[i++]);
	if (bonus_is_sort(a, b, size) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	while (i != -1)
		free(cmd[i--]);
	free(cmd);
	return (0);
}
