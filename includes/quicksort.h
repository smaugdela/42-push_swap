/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:25:18 by smagdela          #+#    #+#             */
/*   Updated: 2021/10/10 15:53:38 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

# include "push_swap.h"

int		ft_is_rev_sorted(t_stack *stack);
int		median_finder(t_stack *stack);
void	ft_add_link(t_stack *stack, int value);

#endif