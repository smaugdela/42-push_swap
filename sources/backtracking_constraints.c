/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_constraints.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:34:09 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/28 12:09:51 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

static int	comp_check (int x, int y)
{
	if (x == 2)
		if (y == 2 || y == 5 || y == 6)
			return (0);
	if (x == 3)
		if (y == 4 || y == 9 || y == 10)
			return (0);
	if (x == 4)
		if (y == 3 || y == 7 || y == 8)
			return (0);
	if ((x == 5 && y == 5) || (x == 5 && y == 2))
			return (0);
	if ((x == 6 && y == 6) || (x == 6 && y == 2))
			return (0);
	if ((x == 7 && y == 9) || (x == 7 && y == 4))
			return (0);
	if (x == 8)
		if (y == 10 || y == 4)
			return (0);
	if (x == 9)
		if (y == 7 || y == 3)
			return (0);
	if (x == 10)
		if (y == 8 || y == 3)
			return (0);
	return (1);
}

static int	counter(int y, t_link *op)
{
	int x;
	int tmp;

	x = y;
	while (op != NULL)
	{
		if (op->value == 0)
			++x;
		else if (op->value == 1)
			--x;
		if (x < 0)
			return (0);
		else if (x == 0 && op->next =! NULL)
		{
			tmp = op->next->value;
			if (tmp == 1 || tmp == 2 || tmp == 3 || tmp == 4 
				|| tmp == 6 || tmp == 8 || tmp == 10)
				return (0);
		}
		op = op->next;
	}
	return (1);
}

static int	push_check(t_stack *sol_pot, size_t a)
{
	int 	b;
	int		tmp;
	t_link	*op;

	b = 0;
	op = sol_pot->list;
	if (counter(a, op) == 0)
		return (0);
	op = sol_pot->list;
	if (counter(b, op) == 0)
		return (0);
	return (optimizer(sol_pot));
}

int	ft_constraints(t_stack *sol_pot, size_t a)
{
	//Renvoi 1 pour OK, 0 pour KO.
	t_link	*op;

	op = sol_pot->list;
	while (op->next != NULL)
	{
		op = op->next;
		if (comp_check(op->value, op->previous->value) == 0)
			return (0);
	}
	return (push_check(sol_pot, a));
}
