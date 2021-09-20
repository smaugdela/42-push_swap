/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/20 11:18:56 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Docs :

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

static int	*ft_init(int argc, char **argv)
{
	int	i;
	int	*list;

	list = (int*)malloc((argc - 1) * sizeof(int));
	if (list == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
		list[i - 1] = ft_atoi(argv[i]);
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack	stack_A;
	t_stack stack_B;
	size_t	i;

	if (ft_error(argc, argv))
		return (42);
	stack_A.list = ft_init(argc, argv);
	stack_B.list = (int*)malloc((argc - 1) * sizeof(int));
	if (stack_A.list == NULL || stack_B.list == NULL)
	{
		free(stack_A.list);
		free(stack_B.list);
		return (42);
	}
	stack_A.len = argc - 1;
	stack_B.len = 0;
	i = 0;
	while (i < stack_A.len)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(stack_A.list[i], 1);
		ft_putstr_fd("|\n", 1);
		++i;
	}
	free(stack_A.list);
	free(stack_B.list);
	return (0);
}
