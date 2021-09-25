/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:23:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/25 12:38:56 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_clone(t_stack *stack)
{}

static int	ft_constraints(char *sol)
{
	//Renvoi 1 pour OK, 0 pour KO.
}

static char	*ft_gen_sol(size_t len)
{
	static char	*sol;
	//On se sert de len pour limiter la taille maximale de sol.
	//Renvoi NULL si atteinte de la limite;
}

void	ft_backtracking(t_stack *a, t_stack *b)
{
	t_stack *a_bis;
	char	*sol_pot;
	size_t	limit;
	size_t	i;

	limit = a->len * K;
	i = 0;
	while(i++ < limit)
	{
		a_bis = ft_clone(a);
		sol_pot = ft_gen_sol(limit);
		if (sol_pot == NULL)
		{
			liberator(a_bis, NULL);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		if (ft_submit(a_bis, b, sol_pot) == 1)
		{
			liberator(a_bis, NULL);
			ft_execute(sol_pot);
			return ;
		}
		liberator(a_bis, NULL);
	}
}
