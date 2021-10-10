/* ************************************************************************** */
/*			                                                                  */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:27:49 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/08 18:56:11 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

static void	qsb_aux(t_stack *b, t_stack *a, t_stack **solution, int median)
{
	size_t	stack_len;
	int		r_counter;

	stack_len = b->len;
	r_counter = 0;
	while (stack_len-- && b->list != NULL)
	{
		if (b->list->value >= median)
		{
			p(a, b);
			ft_add_link(*solution, 1);
		}
		else
		{
			r(b);
			ft_add_link(*solution, 8);
			++r_counter;
		}
	}
	while (r_counter-- > 0)
	{
		rr(b);
		ft_add_link(*solution, 10);
	}
}

static int	quicksort_b(t_stack *b, t_stack **solution)
{
	t_stack	*a;

	a = ft_init(NULL, 0, 'c');
	if (ft_is_rev_sorted(b) == 1)
	{
		while (b->len > 0)
		{
			p(a, b);
			ft_add_link(*solution, 1);
		}
		return (liberator(a, b));
	}
	else if (b->len == 2)
	{
		s(b);
		ft_add_link(*solution, 6);
		while (b->len > 0)
		{
			p(a, b);
			ft_add_link(*solution, 1);
		}
		return (liberator(a, b));
	}
	qsb_aux(b, a, solution, median_finder(b));
	return (quicksort_a(a, solution) && quicksort_b(b, solution));
}

static void	qsa_aux(t_stack *a, t_stack *b, t_stack **solution, int median)
{
	size_t	stack_len;
	int		r_counter;

	r_counter = 0;
	stack_len = a->len;
	while (stack_len-- && a->list != NULL)
	{
		if (a->list->value < median)
		{
			p(b, a);
			ft_add_link(*solution, 0);
		}
		else
		{
			r(a);
			ft_add_link(*solution, 7);
			++r_counter;
		}	
	}
	while (r_counter-- > 0)
	{
		rr(a);
		ft_add_link(*solution, 9);
	}
}

int	quicksort_a(t_stack *a, t_stack **solution)
{
	t_stack	*b;

	b = ft_init(NULL, 0, 'd');
	if (ft_is_sorted(a) == 1)
		return (liberator(a, b));
	else if (a->len == 2)
	{
		s(a);
		ft_add_link(*solution, 5);
		return (liberator(a, b));
	}
	qsa_aux(a, b, solution, median_finder(a));
	return (quicksort_a(a, solution) && quicksort_b(b, solution));
}
