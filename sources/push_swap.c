/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/11 10:41:16 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*solution;

	if (ft_error(argc, argv))
		return (42);
	if (argc <= 2)
		return (0);
	a = ft_init(argv, argc - 1, 'c');
	if (a == NULL)
		return (42);
	else if (ft_is_sorted(a) == 1)
		return (!liberator(a, NULL));
	else if (a->len <= 5)
	{
		liberator(a, NULL);
		return (ft_backtracking(argv, argc));
	}
	else
	{
		solution = ft_init(NULL, 0, 's');
		quicksort_a(a, &solution);
		return (ft_execute(ft_optimize(solution), argv, argc));
	}
}
