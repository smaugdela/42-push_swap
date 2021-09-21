/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:46:57 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/21 18:00:46 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>

typedef struct s_stack
{
	char	name;
	size_t	*len;
	int		*list;
}	t_stack;

int		ft_error(int argc, char **argv);
void	ft_print_stacks(t_stack stack_a, t_stack stack_b);
void	liberator(t_stack stack_a, t_stack stack_b);
char	*ft_append(char	*str, char c);
char	*s(t_stack stack);
char	*r(t_stack stack);
char	*p(t_stack stack_1, t_stack stack_2);
char	*revr(t_stack stack);
char	*ss(t_stack stack_1, t_stack stack_2);
char	*rr(t_stack stack_1, t_stack stack_2);
char	*rrr(t_stack stack_1, t_stack stack_2);
void	ft_putstr_free(char *s, int fd);

#endif
