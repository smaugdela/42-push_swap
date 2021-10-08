/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/08 17:14:35 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Docs:
https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/
*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (ft_error(argc, argv))
		return (42);
	if (argc <= 2)
		return (0);
	a = ft_init(argv, argc - 1, 'a');
	if (a == NULL)
		return (42);
	else if (ft_is_sorted(a) == 1)
	{	
		liberator(a, NULL);
		return(0);
	}
	else if (a->len <= 5)
	{
		liberator(a, NULL);
		return (ft_backtracking(argv, argc));
	}
	else
		return (!quicksort_a(a));
	return (0);
}
