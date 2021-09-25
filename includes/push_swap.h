/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:46:57 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/25 12:39:43 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

//Constante pour complexite limite K * n
# define K 16

typedef struct s_link
{
	int				value;
	struct s_link	*previous;
	struct s_link	*next;
}	t_link;

typedef struct s_stack
{
	char	name;
	size_t	len;
	t_link	*list;
}	t_stack;

int		ft_error(int argc, char **argv);
t_stack	*ft_init(char **argv, int len, char name);
void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
void	liberator(t_stack *stack_a, t_stack *stack_b);
t_link	*lst_last(t_link *link);
t_link	*lst_first(t_link *list);
int		ft_is_sorted(t_stack *stack);

void	op_printer(char *op, char name);
void	s(t_stack *stack);
void	r(t_stack *stack);
void	p(t_stack *stack_1, t_stack *stack_2);
void	rr(t_stack *stack);
void	double_s(t_stack *stack_1, t_stack *stack_2);
void	double_r(t_stack *stack_1, t_stack *stack_2);
void	double_rr(t_stack *stack_1, t_stack *stack_2);

void	ft_backtracking(t_stack *a, t_stack *b);
int		ft_submit(t_stack *a, t_stack *b, char *sol_pot);
void	ft_execute(char *sol);

void	ft_printer(t_stack *stack_a, t_stack *stack_b);

#endif
