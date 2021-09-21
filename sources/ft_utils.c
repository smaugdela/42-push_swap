/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:34:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/21 18:00:52 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack stack_a, t_stack stack_b)
{
	size_t	i;

	ft_putstr_fd("Stack A : \n", 1);
	i = 0;
	while (i < *stack_a.len)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(stack_a.list[i], 1);
		ft_putstr_fd("|\n", 1);
		++i;
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Stack B : \n", 1);
	i = 0;
	while (i < *stack_b.len)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(stack_b.list[i], 1);
		ft_putstr_fd("|\n", 1);
		++i;
	}
	ft_putchar_fd('\n', 1);
}

void	liberator(t_stack stack_a, t_stack stack_b)
{
	free(stack_a.list);
	free(stack_b.list);
	free(stack_a.len);
	free(stack_b.len);
	stack_a.list = NULL;
	stack_b.list = NULL;
	stack_a.len = NULL;
	stack_b.len = NULL;
}

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
