/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/30 16:44:24 by smagdela         ###   ########.fr       */
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
	int		ret;

	if (ft_error(argc, argv))
		return (42);
	if (argc <= 2)
		return (0);
	ret = 42;
	a = ft_init(argv, argc - 1, 'a');
	if (a == NULL)
		return (42);
	else if (ft_is_sorted(a) == 0)
	{
		ret = ft_backtracking(argv, argc);
	}
	liberator(a, NULL);
	return (ret);
}
