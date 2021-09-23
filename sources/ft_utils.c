/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:34:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/23 17:31:36 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *stack_1, t_stack *stack_2)
{
	t_link	*link;

	op_printer("Stack ", stack_1->name);
	link = stack_1->list;
	while (link != NULL)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(link->value, 1);
		ft_putstr_fd("|\n", 1);
		link = link->next;
	}
	ft_putchar_fd('\n', 1);
	op_printer("Stack ", stack_2->name);
	link = stack_2->list;
	while (link != NULL)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(link->value, 1);
		ft_putstr_fd("|\n", 1);
		link = link->next;
	}
	ft_putstr_fd("----------\n", 1);
}

void	liberator(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->list);
	free(stack_b->list);
	stack_a->list = NULL;
	stack_b->list = NULL;
	free(stack_a);
	free(stack_b);
	stack_a = NULL;
	stack_b = NULL;
}

void	double_s(t_stack *stack_1, t_stack *stack_2)
{
	t_link	*link;
	int		tmp;

	if (stack_1->len <= 1 || stack_2->len <= 1)
		return ;
	link = stack_1->list;
	tmp = link->value;
	link->value = link->next->value;
	link->next->value = tmp;
	link = stack_2->list;
	tmp = link->value;
	link->value = link->next->value;
	link->next->value = tmp;
	op_printer("ss", '\0');
}

void	double_r(t_stack *stack_1, t_stack *stack_2)
{
	t_link	*link;

	if (stack_1->len < 2 || stack_2->len < 2)
		return ;
	link = stack_1->list;
	link->previous = lst_last(stack_1->list);
	stack_1->list = stack_1->list->next;
	link->previous->next = link;
	link->next->previous = NULL;
	link->next = NULL;
	link = stack_2->list;
	link->previous = lst_last(stack_2->list);
	stack_2->list = stack_2->list->next;
	link->previous->next = link;
	link->next->previous = NULL;
	link->next = NULL;
	op_printer("rr", '\0');
}

void	double_rr(t_stack *stack_1, t_stack *stack_2)
{
	t_link	*link;
	
	if (stack_1->len < 2)
		return ;
	link = lst_last(stack_1->list);
	link->previous->next = NULL;
	link->previous = NULL;
	link->next = stack_1->list;
	link->next->previous = link;
	stack_1->list = link;
	link = lst_last(stack_2->list);
	link->previous->next = NULL;
	link->previous = NULL;
	link->next = stack_2->list;
	link->next->previous = link;
	stack_2->list = link;
	op_printer("rrr", '\0');
}
