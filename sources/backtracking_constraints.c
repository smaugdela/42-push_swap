/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_constraints.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 09:34:09 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/30 14:57:26 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

static int	comp_check(int x, int y)
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

static int	counter(int y, t_link *op, t_bool a)
{
	int	tmp;

	while (op != NULL)
	{
		if (op->value == 0)
			++y;
		else if (op->value == 1)
			--y;
		if (y < 0)
			return (0);
		else if ((y == 0) && (op->next != NULL))
		{
			tmp = op->next->value;
			if (tmp == (1 - a) || tmp == 2 || tmp == 3 || tmp == 4
				|| tmp == (6 - a) || tmp == (8 - a) || tmp == (10 - a))
				return (0);
		}
		op = op->next;
	}
	if ((y == 0) && (a == 0))
		return (1);
	else if ((y != 0) && (a == 1))
		return (1);
	else
		return (0);
}

static t_bool	op_len(int value, t_link *start, int limit)
{
	int	counter;

	while (start != NULL)
	{
		counter = 0;
		while ((start != NULL) && (start->value == value))
		{
			++counter;
			start = start->next;
			if (counter > limit)
				return (0);
		}
		if (start != NULL)
			start = start->next;
	}
	return (1);
}

static int	optimizer(t_stack *sol_pot, size_t a)
{
	if (op_len(7, sol_pot->list, a / 2) == 0)
		return (0);
	if (op_len(8, sol_pot->list, a / 2) == 0)
		return (0);
	if (op_len(9, sol_pot->list, a / 2) == 0)
		return (0);
	if (op_len(10, sol_pot->list, a / 2) == 0)
		return (0);
	return (1);
}

//Renvoi 1 pour OK, 0 pour KO.
int	ft_constraints(t_stack *sol_pot, size_t a)
{
	t_link	*op;

	op = sol_pot->list;
	while (op->next != NULL)
	{
		op = op->next;
		if (comp_check(op->value, op->previous->value) == 0)
			return (0);
	}
	op = sol_pot->list;
	if (counter(a, op, 1) == 0)
		return (0);
	op = sol_pot->list;
	if (counter(0, op, 0) == 0)
		return (0);
	return (optimizer(sol_pot, a));
}
