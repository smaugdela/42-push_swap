/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:33:40 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/29 10:38:57 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKTRACKING_H
# define BACKTRACKING_H

# include "push_swap.h"

//Constante pour complexite limite K * n
# define K 16

int		ft_submit(t_stack *c, t_stack *d, t_stack *sol_pot);
void	ft_execute(t_stack *sol_pot);
int		ft_constraints(t_stack *sol_pot, size_t a);

#endif
