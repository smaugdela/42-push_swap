/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_optimizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:55:43 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/08 19:04:50 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

static int	counter_op(int x, int y)
{
	if ((y == 1 && x == 0) || (x == 1 && y == 0))
		return (1);
	if ((y == 5 && x == 5) || (x == 6 && y == 6))
		return (1);
	if ((y == 7 && x == 9) || (x == 7 && y == 9))
		return (1);
	if ((y == 8 && x == 10) || (x == 8 && y == 10))
		return (1);
	return (0);
}

static int	doubled_op(int x, int y)
{
	if ((y == 5 && x == 6) || (x == 5 && y == 6))
		return (2);
	if ((y == 7 && x == 8) || (x == 7 && y == 8))
		return (3);
	if ((y == 9 && x == 10) || (x == 9 && y == 10))
		return (4);
	return (0);
}

static void bypass(t_link *link)
{
	if (link->previous != NULL)
		link->previous->next = link->next;
	if (link->next != NULL)
		link->next->previous = link->previous;
	free(link);
}

t_stack	*ft_optimize(t_stack *solution)
{
	t_link	*link;
	int		value;
	t_bool	optimized;

	optimized = 0;
	while (optimized == 0)
	{
		optimized = 1;
		link = solution->list;
		while (link != NULL && link->next != NULL)
		{
			value = 0;
			if (counter_op(link->value, link->next->value) == 1)
			{
                link = link->next;
				bypass(link->previous);
				bypass(link);
				optimized = 0;
			}
			else
				value = doubled_op(link->value, link->next->value);
			if (value)
			{
				link->value = value;
				bypass(link->next);
				optimized = 0;
			}
			link = link->next;
		}
	}
	solution->list = lst_first(link);
	return (solution);
}
