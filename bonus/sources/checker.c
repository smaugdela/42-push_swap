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
	char **list;

	list = (char **)malloc(11 * sizeof(char*));
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
}

static t_bool	op_is_valid(char *op, char **op_list)
{
	int	i;

	i = 0;
	while (op_list[i] != NULL && i < 12)
	{
		if (!ft_strncmp(op_list[i], op, ft_strlen(op)))
		{
			free(op_list);
			return (1);
		}
		++i;
	}
	free(op_list);
	return (0);
}

static int	ft_opfinder(char **op_list, char *op)
{
	int	i;
	
	i = 0;
	while (i < 12 && op_list[i] != NULL)
	{
		if (ft_strncmp(op_list[i], op, ft_strlen(op)) == 0)
			return (i);
	}
	return (-1);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	**line;
	int		gnl_ret;
	char	**op_list;

	if (ft_error(argc, argv))
		return (42);
	a = ft_init(argv, argc - 1, 'a');
	if (a == NULL)
		return (42);
	b = ft_init(NULL, 0, 'b');
		return (42 * liberator(a, NULL));
	line = NULL;
	gnl_ret = get_next_line(1, line);
	op_list = op_lister();
	while ((gnl_ret == 1 || gnl_ret == 0) && (op_is_valid(*line, op_list)))
	{
		ft_execute_operation(ft_opfinder(op_list, *line), a, b);
		if (gnl_ret == 0)
			break ;
		else
			gnl_ret = get_next_line(1, line);
	}
	if (gnl_ret == -1 || *line == NULL || !op_is_valid(*line, op_list))
	{
		ft_putstr_fd("Error\n", 2);
		free(op_list);
		return (42);
	}
	else if (ft_is_sorted(a) && b->len == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(op_list);
	return (0);
}
