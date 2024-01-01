/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:08:09 by chansjeo          #+#    #+#             */
/*   Updated: 2024/01/01 18:10:10 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	take_arg_to_stack(int argc, char **argv, t_stack *a, t_stack *b)
{
	long	num;

	while (*argv != 0)
	{
		a->tmp = 0;
		if ((*(*argv + 1) && **argv == '-') || (*(*argv + 1) && **argv == '+'))
			a->tmp++;
		while (*(*argv + a->tmp) != '\0')
		{
			if (!ft_isdigit(*(*argv + a->tmp++)))
				return (-1);
		}
		num = ft_atol(*argv);
		if (num > 2147483647 || num < -2147483648 || a->tmp > 11)
			return (-1);
		push(b, num);
		argv++;
	}
	while (argc--)
	{
		num = pop(b);
		push(a, num);
	}
	return (0);
}

int	init_data_quote_case(int argc, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	argv = ft_split(argv[1], ' ');
	if (!argv || !*argv)
	{
		a->capacity = -1;
		return (free_split_data(argv));
	}
	i = 0;
	while (argv[i] != 0)
		i++;
	argc = i + 1;
	init_stack(a, argc);
	init_stack(b, argc);
	if (take_arg_to_stack(argc - 1, argv, a, b) < 0)
		return (free_split_data(argv));
	free_split_data(argv);
	b->record = ft_calloc(10000000, sizeof(char));
	if (!b->record)
		return (0);
	if (ft_dupl(a->data, argc - 1) == 1)
		return (-1);
	if (is_sort(a->data, argc - 1))
		return (-2);
	return (0);
}

int	init_data(int argc, char **argv, t_stack *a, t_stack *b)
{
	if (argc == 2)
		return (init_data_quote_case(argc, argv, a, b));
	init_stack(a, argc);
	init_stack(b, argc);
	if (take_arg_to_stack(argc - 1, argv + 1, a, b) < 0)
		return (-1);
	b->record = ft_calloc(10000000, sizeof(char));
	if (!b->record)
		return (-1);
	if (ft_dupl(a->data, argc - 1) == 1)
		return (-1);
	if (is_sort(a->data, argc - 1))
		return (-2);
	return (0);
}

void	error_check(int ret, t_stack *a, t_stack *b)
{
	if (ret == -1)
	{
		free_data(a, b);
		write(2, "Error\n", 6);
	}
	else if (ret == -2)
		free_data(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	int		ret;

	if (argc == 1)
		return (0);
	ret = init_data(argc, argv, &a, &b);
	if (ret < 0)
	{
		error_check(ret, &a, &b);
		return (-1);
	}
	if (a.size == 3 || a.size == 5)
		simple_sort(&a, &b, a.size);
	else
		qsort_a_to_b(&a, &b, a.size);
	ft_printf("%s", b.record);
	free_data(&a, &b);
	return (0);
}
