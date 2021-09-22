/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/22 15:13:23 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Docs :

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

static t_stack	ft_init(char **argv, int len, char name)
{
	t_stack	stack;
	int		i;

	stack.name = name;
	stack.len = len;
	if (argv == NULL || len == 0)
		stack.list = NULL;
	else
	{
		stack.list = (t_link *)malloc((len + 1) * sizeof(t_link));
		if (stack.list == NULL)
			return (stack);
		i = 0;
		while (++i < len)
			stack.list[i].previous = &stack.list[i - 1];
		i = 0;
		while (++i < len)
			stack.list[i - 1].next = &stack.list[i];
		stack.list[0].previous = NULL;
		stack.list[len - 1].next = NULL;
		i = -1;
		while (++i < len)
			stack.list[i].value = ft_atoi(argv[i + 1]);
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
	a = ft_init(argv, argc - 1, 'a');
	b = ft_init(NULL, 0, 'b');
	if (a.list == NULL)
	{
		liberator(a, b);
		return (42);
	}

	ft_print_stacks(a, b);
	s(a);
	ft_putstr_fd("sa\n", 1);
	ft_print_stacks(a, b);
/*
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
*/

	liberator(a, b);
	return (0);
}
