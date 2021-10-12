/* ************************************************************************** */
/*		                                                                      */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:44:18 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/11 12:22:01 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	**op_lister(void)
{
	char	**list;

	list = (char **)malloc(12 * sizeof(char *));
	if (list == NULL)
		return (NULL);
	list[0] = "pb\n";
	list[1] = "pa\n";
	list[2] = "ss\n";
	list[3] = "rr\n";
	list[4] = "rrr\n";
	list[5] = "sa\n";
	list[6] = "sb\n";
	list[7] = "ra\n";
	list[8] = "rb\n";
	list[9] = "rra\n";
	list[10] = "rrb\n";
	list[11] = NULL;
	return (list);
}

static void	ft_execute_operation(int index, t_stack *a, t_stack *b)
{
	if (index == 0)
		p(b, a);
	else if (index == 1)
		p(a, b);
	else if (index == 2)
		double_s(a, b);
	else if (index == 3)
		double_r(a, b);
	else if (index == 4)
		double_rr(a, b);
	else if (index == 5)
		s(a);
	else if (index == 6)
		s(b);
	else if (index == 7)
		r(a);
	else if (index == 8)
		r(b);
	else if (index == 9)
		rr(a);
	else if (index == 10)
		rr(b);
	else
		return ;
}

static int	ft_opfinder(char **op_list, char *op)
{
	int	i;

	i = 0;
	while (i < 12 && op_list[i] != NULL)
	{
		if ((ft_strlen(op_list[i]) - 1) == ft_strlen(op)
			&& ft_strncmp(op_list[i], op, ft_strlen(op_list[i]) - 1) == 0)
			return (i);
		++i;
	}
	return (-1);
}

static int	ft_checker(t_stack *a, t_stack *b)
{
	char	**op_list;
	char	*line;

	op_list = op_lister();
	while (get_next_line(0, &line) > 0)
	{
		if (ft_opfinder(op_list, line) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			free(op_list);
			free(line);
			return (42 * liberator(a, b));
		}
		ft_execute_operation(ft_opfinder(op_list, line), a, b);
		free(line);
	}
	free(op_list);
	if (line == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (42 * liberator(a, b));
	}
	free(line);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (ft_error(argc, argv))
		return (42);
	a = ft_init(argv, argc - 1, 'c');
	if (a == NULL)
		return (42);
	b = ft_init(NULL, 0, 'd');
	if (b == NULL)
		return (42 * liberator(a, NULL));
	if (ft_checker(a, b) == 0)
	{
		if ((ft_is_sorted(a)) && (b->len == 0))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
		liberator(a, b);
	}
	return (0);
}
