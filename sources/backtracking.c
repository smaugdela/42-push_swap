/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:23:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/05 15:37:56 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

static void	ft_add_operation(t_stack *sol_pot)
{
	t_link	*operation;

	operation = (t_link *)malloc(1 * sizeof(t_link));
	if (operation == NULL)
		return ;
	operation->previous = lst_last(sol_pot->list);
	operation->next = NULL;
	operation->value = 0;
	if (operation->previous != NULL)
		operation->previous->next = operation;
	sol_pot->len = sol_pot->len + 1;
	sol_pot->list = lst_first(operation);
}

static t_stack	*ft_iter(t_stack *sol_pot)
{
	t_link	*operation;

	operation = lst_last(sol_pot->list);
	if (operation->value < 10)
		operation->value = operation->value + 1;
	else
	{
		while (operation != NULL)
		{
			if (operation->value < 10)
			{
				operation->value = operation->value + 1;
				return (sol_pot);
			}
			else
				operation->value = 0;
			operation = operation->previous;
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
		sol_pot = ft_iter(sol_pot);
		if (ft_constraints(sol_pot, c->len) == 1)
			return (sol_pot);
	}
	liberator(sol_pot, NULL);
	return (NULL);
}

static int	ft_backtracking_aux(t_stack *c, t_stack *d, t_stack **sol_pot)
{
	*sol_pot = ft_gen_sol(c->len * K, *sol_pot, c);
	if (sol_pot == NULL)
		return (42);
	else if ((*sol_pot)->list == NULL)
	{
		liberator(*sol_pot, NULL);
		liberator(c, d);
		ft_putstr_fd("Backtracking Error\n", 2);
		return (42);
	}
	if (ft_submit(c, d, *sol_pot) == 1)
	{
		liberator(c, d);
		return (0);
	}
	liberator(c, d);
	return (42);
}

int	ft_backtracking(char **argv, int argc)
{
	t_stack	*c;
	t_stack	*d;
	t_stack	*sol_pot;

	sol_pot = ft_init(NULL, 0, 's');
	while (sol_pot != NULL)
	{
		c = ft_init(argv, argc - 1, 'c');
		if (c == NULL)
		{
			liberator(sol_pot, NULL);
			return (42);
		}
		d = ft_init(NULL, 0, 'd');
		if (d == NULL)
		{
			liberator(c, sol_pot);
			return (42);
		}
		if (ft_backtracking_aux(c, d, &sol_pot) == 0)
			return (ft_execute(sol_pot, argv, argc));
	}
	liberator(sol_pot, NULL);
	return (42);
}
