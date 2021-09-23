/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/23 17:03:54 by smagdela         ###   ########.fr       */
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
	t_link	*link;
	int		i;

	stack.name = name;
	stack.len = len;
	if (argv == NULL || len == 0)
		stack.list = NULL;
	else
	{
		stack.list = (t_link *)malloc((len + 1) * sizeof(t_link));
		if (len == 0)
			stack.list = NULL;
		if (stack.list == NULL)
			return (stack);
		i = 0;
		link = stack.list;
		link->previous = NULL;
		while (i++ < len)
		{
			link->value = ft_atoi(argv[i]);
			link->next = link + 1;
			link->next->previous = link;
			link = link->next;
		}
		link->previous->next = NULL;
		link = NULL;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (ft_error(argc, argv))
		return (42);
	if (argc <= 2)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	if (a == NULL)
		return (42);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (b == NULL)
	{
		free(a);
		return (42);
	}
	*a = ft_init(argv, argc - 1, 'a');
	*b = ft_init(NULL, 0, 'b');
	if (a->list == NULL)
	{
		liberator(a, b);
		return (42);
	}

	ft_print_stacks(a, b);
	
	s(a);
	ft_print_stacks(a, b);

	p(b, a);
	ft_print_stacks(a, b);

	p(b, a);
	ft_print_stacks(a, b);

	s(a);
	ft_print_stacks(a, b);

	s(b);
	ft_print_stacks(a, b);

	double_s(a, b);
	ft_print_stacks(a, b);

	r(a);
	ft_print_stacks(a, b);

	r(b);
	ft_print_stacks(a, b);

	double_r(a, b);
	ft_print_stacks(a, b);

	p(a, b);
	ft_print_stacks(a, b);

	p(a, b);
	ft_print_stacks(a, b);

	p(a, b);
	ft_print_stacks(a, b);

	p(b, a);
	ft_print_stacks(a, b);

	p(b, a);
	ft_print_stacks(a, b);

	rr(a);
	ft_print_stacks(a, b);

	rr(b);
	ft_print_stacks(a, b);

	double_rr(a, b);
	ft_print_stacks(a, b);

	liberator(a, b);
	return (0);
}
