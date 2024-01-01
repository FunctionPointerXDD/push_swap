/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:53:08 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/30 18:37:37 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# define HIGH 1
# define LOW 2
# define A_STACK 1
# define B_STACK 2

typedef enum e_cmd
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
}	t_cmd;
typedef struct s_stack
{
	int		top;
	int		size;
	int		tmp;
	int		first;
	int		pivot;
	int		high;
	int		low;
	int		rotate;
	int		push;
	int		capacity;
	int		*data;
	int		*arr;
	char	*record;
}	t_stack;
int		is_empty(t_stack *s);
int		is_full(t_stack *s);
int		is_sort(int *data, int cnt);
void	init_stack(t_stack *s, int cnt);
void	push(t_stack *s, int item);
int		pop(t_stack *s);
int		init_data(int argc, char **argv, t_stack *a, t_stack *b);
int		init_data_quote_case(int argc, char **argv, t_stack *a, t_stack *b);
int		take_arg_to_stack(int argc, char **argv, t_stack *a, t_stack *b);
int		free_split_data(char **argv);
void	error_check(int ret, t_stack *a, t_stack *b);
void	swap_stack(t_stack *box);
void	pop_and_push(t_stack *x, t_stack *y);
void	rotation(t_stack *box);
void	rev_rotation(t_stack *box);
void	stack_operator(t_stack *a, t_stack *b, int op);
void	qsort_a_to_b(t_stack *a, t_stack *b, int size);
void	qsort_b_to_a(t_stack *a, t_stack *b, int size);
void	record_op(t_stack *b, int oper);
int		ft_dupl(int *num, int cnt);
void	swap(int *a, int *b);
int		partition(int arr[], int low, int high);
int		quick_select(int arr[], int low, int high, int k);
void	free_data(t_stack *a, t_stack *b);
void	sort_3_items(t_stack *a, t_stack *b);
void	sort_5_items(t_stack *a, t_stack *b, int size);
void	simple_sort(t_stack *a, t_stack *b, int size);
int		pivot_selector(t_stack *x, int size, int flag);
void	pivot_and_init_cnt(t_stack *a, t_stack *b, int size, int flag);
void	special_case(t_stack *a, t_stack *b);
void	general_sort_a(t_stack *a, t_stack *b, int size);
void	general_sort_b(t_stack *a, t_stack *b, int size);
void	arrange_stack(t_stack *a, t_stack *b, int size_a, int size_b);
void	sort_b_stack(t_stack *a, t_stack *b);
void	sort_a_stack(t_stack *a, t_stack *b);
void	small_size_sort(t_stack *a, t_stack *b, int size, int flag);
void	first_sort(t_stack *a, t_stack *b, int size);

#endif
