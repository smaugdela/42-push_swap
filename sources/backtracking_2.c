/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:12:55 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/30 12:29:59 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

static void	associator(int value, t_stack *stack_1, t_stack *stack_2)
{
	if (value == 0)
		p(stack_2, stack_1);
	else if (value == 1)
		p(stack_1, stack_2);
	else if (value == 2)
		double_s(stack_1, stack_2);
	else if (value == 3)
		double_r(stack_1, stack_2);
	else if (value == 4)
		double_rr(stack_1, stack_2);
	else if (value == 5)
		s(stack_1);
	else if (value == 6)
		s(stack_2);
	else if (value == 7)
		r(stack_1);
	else if (value == 8)
		r(stack_2);
	else if (value == 9)
		rr(stack_1);
	else if (value == 10)
		rr(stack_2);
}

//Renvoi 1 si c est triee et d vide, 0 sinon.
//Utilise une association de chaque int de sol_pot
// avec une operation propre. Cette association est la meme
// que dans la fonction ft_execute.
int	ft_submit(t_stack *c, t_stack *d, t_stack *sol_pot)
{
	t_link	*operation;

	operation = sol_pot->list;
	while (operation != NULL)
	{
		associator(operation->value, c, d);
		operation = operation->next;
	}
	if (ft_is_sorted(c) == 1 && d->len == 0)
	{
		ft_print_stacks(c, d);
		return (1);
	}
	return (0);
}

//Lit chaque int de sol et execute l'operation associee.
//L'association du int et de l'operation est la meme que dans ft_submit.
int	ft_execute(t_stack *sol, char **argv, int argc)
{
	t_stack	*a;
	t_stack	*b;
	t_link	*operation;

	a = ft_init(argv, argc - 1, 'a');
	if (a == NULL)
		return (42);
	b = ft_init(NULL, 0, 'd');
	if (b == NULL)
	{
		liberator(a, NULL);
		return (42);
	}
	operation = sol->list;
	while (operation != NULL)
	{
		associator(operation->value, a, b);
		operation = operation->next;
	}
	liberator(a, b);
	liberator(sol, NULL);
	return (0);
}
