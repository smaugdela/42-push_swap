/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:01:42 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/17 17:55:29 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Docs :

https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
https://www.jesuisundev.com/comprendre-les-algorithmes-de-tri-en-7-minutes/

*/

#include "push_swap.h"

static t_list	*ft_init(int argc, char **argv)
{
	int		i;
	int		*value;
	t_list	*list;
	
	i = argc;
	list = NULL;
	while (--i > 0)
	{
		value = (int*)malloc(sizeof(int));
		if (value == NULL)
		{
			ft_lstclear(&list, &free);
			free(value);
			return (NULL);
		}
		*value = ft_atoi(argv[i]);
		ft_lstadd_front(&list, ft_lstnew(value));
		free(value);
	}
	return (list);
}

int	main(int argc, char **argv)
{
	t_list	*stack_A;
	t_list	*start;
//	t_list	*stack_B;

	if (ft_error(argc, argv))
		return (42);
	stack_A = ft_init(argc, argv);
	if (stack_A == NULL || ft_lstsize(stack_A) != argc - 1)
	{
		write(2, "Init failed\n", 12);
		return (42);
	}
	start = stack_A;
	while (stack_A != NULL)
	{
		write(1, "|", 1);
		ft_putnbr_fd(*(int*)(stack_A->content), 1);
		write(1, "|\n", 2);
		stack_A = stack_A->next;
	}
	ft_lstclear(&start, &free);
	return (0);
}
