/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:30:20 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/23 17:02:44 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_printer(char *op, char name)
{
	ft_putstr_fd(op, 1);
	write(1, &name, 1);
	write(1, "\n", 1);
}

void	s(t_stack *stack)
{
	t_link	*link;
	int		tmp;

	if (stack->len <= 1)
		return ;
	link = stack->list;
	tmp = link->value;
	link->value = link->next->value;
	link->next->value = tmp;
	op_printer("s", stack->name);
}

void	r(t_stack *stack)
{
	t_link	*link;

	if (stack->len < 2)
		return ;
	link = stack->list;
	link->previous = lst_last(stack->list);
	stack->list = stack->list->next;
	link->previous->next = link;
	link->next->previous = NULL;
	link->next = NULL;
	op_printer("r", stack->name);
}

void	rr(t_stack *stack)
{
	t_link	*link;
	
	if (stack->len < 2)
		return ;
	link = lst_last(stack->list);
	link->previous->next = NULL;
	link->previous = NULL;
	link->next = stack->list;
	link->next->previous = link;
	stack->list = link;
	op_printer("rr", stack->name);
}

void	p(t_stack *stack_1, t_stack *stack_2)
{
	t_link	*link;

	if (stack_2->len == 0)
		return ;
	link = stack_2->list;
	if (stack_2->len == 1)
		stack_2->list = NULL;
	else
	{
		stack_2->list = stack_2->list->next;
		stack_2->list->previous = NULL;
	}
	if (stack_1->len == 0 || stack_1->list == NULL)
	{
		stack_1->list = link;
		link->next = NULL;
	}
	else
	{
		link->next = stack_1->list;
		stack_1->list->previous = link;
		stack_1->list = link;
	}
	stack_2->len = stack_2->len - 1;
	stack_1->len = stack_1->len + 1;
	op_printer("p", stack_1->name);
}
