/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 13:23:37 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/28 08:57:58 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_clone(t_stack *stack, char name)
{
	t_stack	*clone;
	t_link	*link;
	t_link	*link_clone;
	t_link	*previous_link;

	clone = (t_stack *)malloc(sizeof(t_stack));
	if (clone != NULL)
	{
	clone->len = stack->len;
	clone->name = name;
		if (stack->len == 0)
			clone->list = NULL;
		else
		{
			link = stack->list;
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
			clone->list = lst_first(link_clone);
		}
	}
	return (stack);
}

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
	t_stack *c;
	t_stack *d;
	char	*sol_pot;
	size_t	limit;
	size_t	i;

	limit = a->len * K;
	i = 0;
	while(i++ < limit)
	{
		c = ft_clone(a, 'c');
		d = ft_clone(b, 'd');
		sol_pot = ft_gen_sol(limit);
		if (sol_pot == NULL)
		{
			liberator(c, d);
			ft_putstr_fd("Backtracking Error\n", 2);
			return ;
		}
		if (ft_submit(c, d, sol_pot) == 1)
		{
			liberator(c, d);
			ft_execute(sol_pot);
			return ;
		}
		liberator(c, d);
	}
}
