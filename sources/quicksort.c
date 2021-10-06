/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:27:49 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/06 17:34:51 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

static int quicksort_b(t_stack *b)
{
    t_stack *a;
	size_t	stack_len;
    int     median;
	int		r_counter;

	a = ft_init(NULL, 0, 'a');
    if (ft_is_rev_sorted(b) == 1)
    {
		while (b->len > 0)
			p(a, b);
        liberator(a, b);
        return (1);
    }
	else if (b->len == 2)
	{
		s(b);
		while (b->len > 0)
			p(a, b);
        liberator(a, NULL);
        return (1);
    }
    median = median_finder(b);
	stack_len = b->len;
	r_counter = 0;
	while (stack_len-- && b->list != NULL)
	{
		if (b->list->value >= median)
			p(a, b);
		else
		{
			r(b);
			++r_counter;
		}
	}
	while (r_counter-- > 0)
		rr(b);
	return (quicksort_a(a) && quicksort_b(b));
}

int quicksort_a(t_stack *a)
{
    t_stack *b;
	size_t	stack_len;
    int     median;
	int		r_counter;

    if (ft_is_sorted(a) == 1)
    {
        liberator(a, NULL);
        return (1);
    }
	else if (a->len == 2)
	{
		s(a);
        liberator(a, NULL);
        return (1);
    }
    b = ft_init(NULL, 0, 'b');
    median = median_finder(a);
	r_counter = 0;
	stack_len = a->len;
	while (stack_len-- && a->list != NULL)
	{
		if (a->list->value < median)
			p(b, a);
		else
			r(a);
			++r_counter;
	}
	while (r_counter-- > 0)
		rr(a);
	return (quicksort_a(a) && quicksort_b(b));
}
