/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:44:06 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/25 11:28:21 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*lst_last(t_link *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

t_link	*lst_first(t_link *list)
{
	if (list == NULL)
		return (NULL);
	while (list->previous != NULL)
	{
		list = list->previous;
	}
	return (list);
}

static t_link	*ft_parser(char **argv, int len)
{
	t_link	*link;
	t_link	*previous_link;

	previous_link = NULL;
	while (len-- > 0 && ++argv != NULL)
	{
		link = (t_link *)malloc(1 * sizeof(t_link));
		if (link == NULL)
			return (NULL);
		link->value = ft_atoi(*argv);
		link->previous = previous_link;
		if (previous_link != NULL)
			previous_link->next = link;
		previous_link = link;
	}
	link->next = NULL;
	return (lst_first(link));
}

t_stack	*ft_init(char **argv, int len, char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack != NULL)
	{
		stack->name = name;
		stack->len = len;
		if (len == 0)
			stack->list = NULL;
		else
			stack->list = ft_parser(argv, len);
	}
	return (stack);
}

int	ft_is_sorted(t_stack *stack)
{
	t_link	*link;

	link = stack->list;
	
	while (link->next != NULL)
	{
		if(link->value >= link->next->value)
			return (0);
		link = link->next;
	}
	return (1);
}
