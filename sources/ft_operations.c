/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:30:20 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/20 17:47:17 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack stack)
{
	int	tmp;

	tmp = stack.list[0];
	stack.list[0] = stack.list[1];
	stack.list[1] = tmp;
}

static void	ft_rot(t_stack stack)
{
	int	i;
	int	tmp_new;
	int	tmp_old;

	i = *stack.len - 1;
	tmp_old = stack.list[i];
	stack.list[i] = stack.list[0];
	while (--i >= 0)
	{
		tmp_new = stack.list[i];
		stack.list[i] = tmp_old;
		tmp_old = tmp_new;
	}
}

static void	ft_revrot(t_stack stack)
{
	size_t	i;
	int		tmp_new;
	int		tmp_old;

	i = 0;
	tmp_old = stack.list[i];
	stack.list[i] = stack.list[*stack.len - 1];
	while (++i < *stack.len)
	{
		tmp_new = stack.list[i];
		stack.list[i] = tmp_old;
		tmp_old = tmp_new;
	}
}

static void	ft_push(t_stack stack_1, t_stack stack_2)
{
	size_t	i;
	int		tmp_old;
	int		tmp_new;

	if (*stack_2.len == 0)
		return ;
	tmp_old = stack_1.list[0];
	stack_1.list[0] = stack_2.list[0];
	++(*stack_1.len);
	i = 0;
	while (++i < *stack_1.len)
	{
		tmp_new = stack_1.list[i];
		stack_1.list[i] = tmp_old;
		tmp_old = tmp_new;
	}
	--(*stack_2.len);
	i = 0;
	while (i < *stack_2.len)
	{
		stack_2.list[i] = stack_2.list[i + 1];
		++i;
	}
}

int	ft_operator(t_stack stack_a, t_stack stack_b, char *operation)
{
	if (ft_strncmp(operation, "sa", ft_strlen(operation)) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(operation, "sb", ft_strlen(operation)) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(operation, "ss", ft_strlen(operation)) == 0)
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (ft_strncmp(operation, "ra", ft_strlen(operation)) == 0)
		ft_rot(stack_a);
	else if (ft_strncmp(operation, "rb", ft_strlen(operation)) == 0)
		ft_rot(stack_b);
	else if (ft_strncmp(operation, "rr", ft_strlen(operation)) == 0)
	{
		ft_rot(stack_a);
		ft_rot(stack_b);
	}
	else if (ft_strncmp(operation, "rra", ft_strlen(operation)) == 0)
		ft_revrot(stack_a);
	else if (ft_strncmp(operation, "rrb", ft_strlen(operation)) == 0)
		ft_revrot(stack_b);
	else if (ft_strncmp(operation, "rrr", ft_strlen(operation)) == 0)
	{
		ft_revrot(stack_a);
		ft_revrot(stack_b);
	}
	else if (ft_strncmp(operation, "pa", ft_strlen(operation)) == 0)
		ft_push(stack_a, stack_b);
	else if (ft_strncmp(operation, "pb", ft_strlen(operation)) == 0)
		ft_push(stack_b, stack_a);
	else
		return (42);
	ft_putstr_fd(operation, 1);
	write(1, "\n", 1);
	return (0);
}
