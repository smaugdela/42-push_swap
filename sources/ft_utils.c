/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:34:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/22 15:19:23 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack stack_a, t_stack stack_b)
{
	t_link	*link;

	ft_putstr_fd("Stack A : \n", 1);
	link = stack_a.list;
	while (link != NULL)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(link->value, 1);
		ft_putstr_fd("|\n", 1);
		link = link->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Stack B : \n", 1);
	link = stack_b.list;
	while (link != NULL)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(link->value, 1);
		ft_putstr_fd("|\n", 1);
		link = link->next;
	}
	ft_putchar_fd('\n', 1);
}

void	liberator(t_stack stack_a, t_stack stack_b)
{
	free(stack_a.list);
	free(stack_b.list);
	stack_a.list = NULL;
	stack_b.list = NULL;
}

/*
char	*ss(t_stack stack_1, t_stack stack_2)
{
	if (s(stack_1) == NULL)
		return (NULL);
	if (s(stack_2) == NULL)
		return (ft_append("s", stack_1.name));
	return ("ss");
}

char	*rr(t_stack stack_1, t_stack stack_2)
{
	if (r(stack_1) == NULL)
		return (NULL);
	if (r(stack_2) == NULL)
		return (ft_append("r", stack_1.name));
	return ("rr");
}

char	*rrr(t_stack stack_1, t_stack stack_2)
{
	if (revr(stack_1) == NULL)
		return (NULL);
	if (revr(stack_2) == NULL)
		return (ft_append("rr", stack_1.name));
	return ("rrr");
}
*/