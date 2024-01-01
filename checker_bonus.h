/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansjeo <chansjeo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:20:58 by chansjeo          #+#    #+#             */
/*   Updated: 2023/12/28 20:23:15 by chansjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int		top;
	int		size;
	int		tmp;
	int		capacity;
	int		*data;
	char	*record;
}	t_stack;
int		is_empty(t_stack *s);
int		is_full(t_stack *s);
int		bonus_is_sort(t_stack *a, t_stack *b, int cnt);
void	init_stack(t_stack *s, int cnt);
void	push(t_stack *s, int item);
int		pop(t_stack *s);
int		init_data(int argc, char **argv, t_stack *a, t_stack *b);
int		init_data_quote_case(int argc, char **argv, t_stack *a, t_stack *b);
int		take_arg_to_stack(int argc, char **argv, t_stack *a, t_stack *b);
int		error_check(int ret, t_stack *a, t_stack *b);
int		main(int argc, char *argv[]);
void	swap_stack(t_stack *box);
void	pop_and_push(t_stack *x, t_stack *y);
void	rotation(t_stack *box);
void	rev_rotation(t_stack *box);
void	checker_operator(t_stack *a, t_stack *b, char *op);
int		checker_record_op(t_stack *b, char *oper);
int		ft_dupl(int *num, int cnt);
int		my_checker(t_stack *a, t_stack *b, int argc, int i);
void	checker_free_data(t_stack *a, t_stack *b);
int		free_split_data(char **argv);
int		bonus_free(char *data);

#endif
