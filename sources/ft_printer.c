/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:21:22 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/25 12:11:42 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printer(t_stack *a, t_stack *b)
{
	s(a);
	ft_print_stacks(a, b);
	p(b, a);
	ft_print_stacks(a, b);
	p(b, a);
	ft_print_stacks(a, b);
	s(a);
	ft_print_stacks(a, b);
	s(b);
	ft_print_stacks(a, b);
	double_s(a, b);
	ft_print_stacks(a, b);
	r(a);
	ft_print_stacks(a, b);
	r(b);
	ft_print_stacks(a, b);
	double_r(a, b);
	ft_print_stacks(a, b);
	p(a, b);
	ft_print_stacks(a, b);
	p(a, b);
	ft_print_stacks(a, b);
	p(a, b);
	ft_print_stacks(a, b);
	p(b, a);
	ft_print_stacks(a, b);
	p(b, a);
	ft_print_stacks(a, b);
	rr(a);
	ft_print_stacks(a, b);
	rr(b);
	ft_print_stacks(a, b);
	double_rr(a, b);
	ft_print_stacks(a, b);
}