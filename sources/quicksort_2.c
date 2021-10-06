/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:05:27 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/06 12:26:29 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

static void	ft_add_link(t_stack *stack, int value)
{
	t_link	*link;

	link = (t_link *)malloc(1 * sizeof(t_link));
    if (link == NULL)
        return ;
	link->previous = lst_last(stack->list);
	link->next = NULL;
	link->value = value;
	if (link->previous != NULL)
		link->previous->next = link;
	stack->len = stack->len + 1;
	stack->list = lst_first(link);
}

static t_stack  *ft_clone(t_stack *stack)
{
    t_stack *clone;
    t_link  *link;

    link = stack->list;
    clone = ft_init(NULL, 0, stack->name);
    while (link != NULL)
    {
        ft_add_link(clone, link->value);
        link = link->next;
    }
    return (clone);
}

static void  bubble_sort(t_stack *stack)
{
    t_link  *link;
    t_bool  sorted;
    int     tmp;

    sorted = 0;
    while (sorted == 0)
    {
        link = stack->list;
        sorted = 1;
        while (link != NULL && link->next != NULL)
        {
            if (link->value > link->next->value)
            {
                tmp = link->value;
                link->value = link->next->value;
                link->next->value = tmp;
                sorted = 0;
            }
            link = link->next;
        }
    }
}

int	median_finder(t_stack *stack)
{
    t_stack *tmp_stack;
    t_link  *link;
    size_t  med_index;
    int     median;

    tmp_stack = ft_clone(stack);
    bubble_sort(tmp_stack);
    med_index = (tmp_stack->len / 2) + (tmp_stack->len % 2);
    link = tmp_stack->list;
    while (--med_index)
        link = link->next;
    median = link->value;
    liberator(tmp_stack, NULL);
    return (median);
}

int	ft_is_rev_sorted(t_stack *stack)
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

