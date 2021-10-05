/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:27:49 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/05 12:56:55 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

static int	median_finder(t_stack *stack)
{
	
}

static int	ft_is_rev_sorted(t_stack *stack)
{
	t_link	*link;

	if (stack == NULL)
		return (0);
	if (stack->list == NULL)
		return (1);
	link = stack->list;
	while (link->next != NULL)
	{
		if (link->value <= link->next->value)
			return (0);
		link = link->next;
	}
	return (1);
}

int quicksort_a(t_stack *a)
{
    t_stack *b;
	t_link	*link;
    int     median;
	int		r_counter;

    if (ft_is_sorted(a) == 1)
    {
        liberator(a, NULL);
        return (1);
    }
    b = ft_init(NULL, 0, 'b');
    median = median_finder(a);
	link = a->list;
	r_counter = 0;
	while (link != NULL)
	{
		if (link->value < median)
			p(b, a);
		else
		{
			r(a);
			++r_counter;
		}
		link = link->next;
	}
	while (r_counter-- > 0)
		rr(a);
	return (quicksort_a(a) && quicksort_b(b));
}

static int quicksort_b(t_stack *b)
{
    t_stack *a;
	t_link	*link;
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
    median = median_finder(b);
	link = b->list;
	r_counter = 0;
	while (link != NULL)
	{
		if (link->value >= median)
			p(a, b);
		else
		{
			r(b);
			++r_counter;
		}
		link = link->next;
	}
	while (r_counter-- > 0)
		rr(b);
	return (quicksort_a(a) && quicksort_b(b));
}
