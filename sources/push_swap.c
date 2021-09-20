/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/20 11:24:59 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Docs :

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

static void	liberator(int *list1, int *list2)
{
	free(list1);
	free(list2);
	list1 = NULL;
	list2 = NULL;
}

static int	*ft_init(int argc, char **argv)
{
	int	i;
	int	*list;

	list = (int *)malloc((argc - 1) * sizeof(int));
	if (list == NULL)
		return (NULL);
	i = 0;
	while (++i < argc)
		list[i - 1] = ft_atoi(argv[i]);
	return (list);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	size_t	i;

	if (ft_error(argc, argv))
		return (42);
	stack_a.list = ft_init(argc, argv);
	stack_b.list = (int *)malloc((argc - 1) * sizeof(int));
	if (stack_a.list == NULL || stack_b.list == NULL)
	{
		liberator(stack_a.list, stack_b.list);
		return (42);
	}
	stack_a.len = argc - 1;
	stack_b.len = 0;
	i = 0;
	while (i < stack_a.len)
	{
		ft_putstr_fd("|", 1);
		ft_putnbr_fd(stack_a.list[i], 1);
		ft_putstr_fd("|\n", 1);
		++i;
	}
	liberator(stack_a.list, stack_b.list);
	return (0);
}
