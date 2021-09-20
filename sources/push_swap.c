/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/20 17:53:11 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Docs :

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

static void	liberator(t_stack stack_a, t_stack stack_b)
{
	free(stack_a.list);
	free(stack_b.list);
	free(stack_a.len);
	free(stack_b.len);
	stack_a.list = NULL;
	stack_b.list = NULL;
	stack_a.len = NULL;
	stack_b.len = NULL;
}

static t_stack	ft_init(int argc, char **argv, size_t len)
{
	t_stack	stack;
	size_t	i;

	stack.len = (size_t *)malloc(1 * sizeof(size_t));
	if (stack.len != NULL)
		*stack.len = len;
	stack.list = (int *)malloc((argc - 1) * sizeof(int));
	if (stack.list != NULL && stack.len != NULL)
	{
		i = 0;
		while (++i <= len)
			stack.list[i - 1] = ft_atoi(argv[i]);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ft_error(argc, argv))
		return (42);
	if (argc == 2)
		return (0);
	stack_a = ft_init(argc, argv, argc - 1);
	stack_b = ft_init(argc, argv, 0);
	if (stack_a.list == NULL || stack_b.list == NULL
		|| stack_a.len == NULL || stack_b.len == NULL
		|| *stack_a.len == 0 || *stack_b.len != 0)
	{
		liberator(stack_a, stack_b);
		return (42);
	}
	ft_print_stacks(stack_a, stack_b);
	
	ft_operator(stack_a, stack_b, "pb");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "pb");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "sa");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "sb");
	ft_print_stacks(stack_a, stack_b);
	
	ft_operator(stack_a, stack_b, "ss");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "ra");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "rb");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "rr");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "pa");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "pb");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "rra");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "rrb");
	ft_print_stacks(stack_a, stack_b);

	ft_operator(stack_a, stack_b, "rrr");
	ft_print_stacks(stack_a, stack_b);

	liberator(stack_a, stack_b);
	return (0);
}
