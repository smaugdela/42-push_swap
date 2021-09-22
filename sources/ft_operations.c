/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:30:20 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/22 15:18:21 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack stack)
{
	t_link	*link;
	int		tmp;

	if (stack.len <= 1)
		return ;
	link = stack.list;
	tmp = link->value;
	link->value = link->next->value;
	link->next->value = tmp;
}

/*
char	*r(t_stack stack)
{
	int	i;
	int	tmp_new;
	int	tmp_old;

	if (stack.len < 2)
		return (NULL);
	i = stack.len - 1;
	tmp_old = stack.list[i];
	stack.list[i] = stack.list[0];
	while (--i >= 0)
	{
		tmp_new = stack.list[i];
		stack.list[i] = tmp_old;
		tmp_old = tmp_new;
	}
	return (ft_append("r", stack.name));
}

char	*revr(t_stack stack)
{
	size_t	i;
	int		tmp_new;
	int		tmp_old;

	if (stack.len < 2)
		return (NULL);
	i = 0;
	tmp_old = stack.list[i];
	stack.list[i] = stack.list[stack.len - 1];
	while (++i < stack.len)
	{
		tmp_new = stack.list[i];
		stack.list[i] = tmp_old;
		tmp_old = tmp_new;
	}
	return (ft_append("rr", stack.name));
}

char	*p(t_stack stack_1, t_stack stack_2)
{
	size_t	i;
	int		tmp_old;
	int		tmp_new;

	if (stack_2.len <= 0)
		return (NULL);
	tmp_old = stack_1.list[0];
	stack_1.list[0] = stack_2.list[0];
	++(stack_1.len);
	i = 0;
	while (++i < stack_1.len)
	{
		tmp_new = stack_1.list[i];
		stack_1.list[i] = tmp_old;
		tmp_old = tmp_new;
	}
	--(stack_2.len);
	i = 0;
	while (i < stack_2.len)
	{
		stack_2.list[i] = stack_2.list[i];
		++i;
	}
	return (ft_append("p", stack_1.name));
}
*/