/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:12:55 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/28 11:24:38 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "backtracking.h"

int	ft_submit(t_stack *c, t_stack *d, t_stack *sol_pot)
{
	//Doit etre protege des stacks NULL;
	//Renvoi 1 si c est triee et d vide, 0 sinon.
	//Utilise une association de chaque caractere de sol_pot
	// avec une operation propre. Cette association ets la meme
	// que dans la fonction ft_execute.
	if (ft_is_sorted(c) == 1 && d->len == 0)
	{
		ft_print_stacks(c, d);
		return (1);
	}
}

void	ft_execute(t_stack *sol)
{
	//Lit chaque caractere de sol et execute l'operation associee.
	//L'association du caractere et de l'operation est la meme que dans ft_submit.
	liberator(sol, NULL);
}
