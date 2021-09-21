/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/21 18:00:49 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Docs :

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

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
	t_stack	a;
	t_stack	b;

	if (ft_error(argc, argv))
		return (42);
	if (argc == 2)
		return (0);
	a = ft_init(argc, argv, argc - 1);
	b = ft_init(argc, argv, 0);
	if (a.list == NULL || b.list == NULL
		|| a.len == NULL || b.len == NULL
		|| *a.len == 0 || *b.len != 0)
	{
		liberator(a, b);
		return (42);
	}
	a.name = 'a';
	b.name = 'b';
	ft_print_stacks(a, b);
	
	ft_putstr_free(p(b, a), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(p(b, a), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(s(a), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(s(b), 1);
	ft_print_stacks(a, b);
	
	ft_putstr_free(ss(a, b), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(r(a), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(r(b), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(rr(a, b), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(p(a, b), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(p(b, a), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(revr(a), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(revr(b), 1);
	ft_print_stacks(a, b);

	ft_putstr_free(rrr(a, b), 1);
	ft_print_stacks(a, b);

	liberator(a, b);
	return (0);
}
