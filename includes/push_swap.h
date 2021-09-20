/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:46:57 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/20 13:58:32 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>

/*   /!\ ATTENTION Supprimer cet include ATTENTION /!\   */
typedef struct s_stack
{
	size_t	*len;
	int		*list;
}	t_stack;

int	ft_error(int argc, char **argv);
int	ft_operator(t_stack stack_a, t_stack stack_b, char *operation);

#endif
