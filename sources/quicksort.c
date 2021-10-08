/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:27:49 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/08 17:28:48 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

static int quicksort_b(t_stack *b, t_stack **solution)
{
    t_stack *a;
	size_t	stack_len;
    int     median;
	int		r_counter;

	a = ft_init(NULL, 0, 'c');
    if (ft_is_rev_sorted(b) == 1)
    {
		while (b->len > 0)
		{
			p(a, b);
			ft_add_link(*solution, 1);
		}
		liberator(a, b);
        return (1);
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
		liberator(a, NULL);
        return (1);
    }
    median = median_finder(b);
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
	return (quicksort_a(a, solution) && quicksort_b(b, solution));
}

int quicksort_a(t_stack *a, t_stack **solution)
{
    t_stack *b;
	size_t	stack_len;
    int     median;
	int		r_counter;

	b = ft_init(NULL, 0, 'd');
    if (ft_is_sorted(a) == 1)
    {

        liberator(a, b);
        return (1);
    }
	else if (a->len == 2)
	{
		s(a);
		ft_add_link(*solution, 5);
        liberator(a, b);
        return (1);
    }
    median = median_finder(a);
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
	return (quicksort_a(a, solution) && quicksort_b(b, solution));
}
