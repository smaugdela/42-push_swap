/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:23:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/29 10:45:57 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

/*
static t_link	*ft_clone_parser(t_link *link)
{
	t_link	*link_clone;
	t_link	*previous_link;

	previous_link = NULL;
	while (link != NULL)
	{
		link_clone = (t_link *)malloc(1 * sizeof(t_link));
		if (link_clone == NULL)
			return (NULL);
		link_clone->value = link->value;
		link_clone->previous = previous_link;
		if (previous_link != NULL)
			previous_link->next = link_clone;
		previous_link = link_clone;
		link = link->next;
	}
	link_clone->next = NULL;
	return (lst_first(link_clone));
}

static t_stack	*ft_clone(t_stack *stack, char name)
{
	t_stack	*clone;
	t_link	*link;

	clone = (t_stack *)malloc(sizeof(t_stack));
	if (clone != NULL)
	{
		clone->len = stack->len;
		clone->name = name;
		if (stack->len == 0)
			clone->list = NULL;
		else
			clone->list = ft_clone_parser(stack->list);
	}
	return (clone);
}
*/

static void	ft_add_operation(t_stack *sol_pot)
{
	t_link	*operation;

	operation = (t_link *)malloc(1 * sizeof(t_link));
	operation->previous = lst_last(sol_pot->list);
	operation->next = NULL;
	operation->value = 0;
	if (operation->previous != NULL)
		operation->previous->next = operation;
	sol_pot->len = sol_pot->len + 1;
}

static void	ft_iter(t_stack *sol_pot)
{
	t_link	*operation;

	operation = lst_last(sol_pot->list);
	if (operation->value < 10)
		operation->value = operation->value + 1;
	else
	{
		operation->value = 0;
		while (operation != NULL)
		{
			operation = operation->previous;
			if (operation->value < 10)
			{
				operation->value = operation->value + 1;
				return (sol_pot);
			}
			else
				operation->value = 0;
		}
		ft_add_operation(sol_pot);
	}
	return (sol_pot);
}

static t_stack	*ft_gen_sol(size_t lim, t_stack *sol_pot, t_stack *c)
{
	if (sol_pot->list == NULL)
		ft_add_operation(sol_pot);
	while (sol_pot->len <= lim)
	{
		ft_iter(sol_pot);
		if (ft_constraints(sol_pot, c->len) == 1)
			return (sol_pot);
	}
	free (sol_pot);
	return (NULL);
}

int	ft_backtracking(char **argv, int argc)
{
	t_stack	*c;
	t_stack	*d;
	t_stack	*sol_pot;

	sol_pot = ft_init(NULL, 0, s);
	while (sol_pot != NULL)
	{
		c = ft_init(argv, argc - 1, 'c');
		if (c == NULL)
			return (42);
		d = ft_init(NULL, 0, d);
		if (d == NULL)
		{
			liberator(c, NULL);
			return (42);
		}
		sol_pot = ft_gen_sol(c->len * K, sol_pot, c);
		if (sol_pot->list == NULL)
		{
			liberator(sol_pot, NULL);
			liberator(c, d);
			ft_putstr_fd("Backtracking Error\n", 2);
			return (42);
		}
		if (ft_submit(c, d, sol_pot) == 1)
		{
			liberator(c, d);
			ft_execute(sol_pot);
			return (0);
		}
		liberator(c, d);
	}
	liberator(c, d);
}
