/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:34:02 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/20 17:47:35 by smagdela         ###   ########.fr       */
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
