/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/16 10:35:15 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Docs :

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

static int	ft_print_and_free(int *ptr)
{
	write(2, "Error\n", 6);
	free (ptr);
	return (42);
}

static int	ft_error(int argc, char **argv)
{
	int	i;
	int	j;
	int	*doubles;

	if (argc <= 1)
		return (ft_print_and_free(NULL));
	i = 0;
	doubles = (int *)malloc((argc - 1) * sizeof(int));
	if (doubles == NULL)
		return (8);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]) || argv[i][j] != '-')
				return (ft_print_and_free(doubles));
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (ft_print_and_free(doubles));
		else
		{
			*doubles = ft_atoi(argv[i]);
			++doubles;	
		}
	}
	free (doubles);
	return (0);
}

int	main(int argc, char **argv)
{
	if (ft_error(argc, argv))
		return (42);
	write(1, "List OK\n", 8);
	return (0);
}
