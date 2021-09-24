/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:44:06 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/24 11:50:25 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*lst_last(t_link *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}

t_link	*lst_first(t_link *list)
{
	if (list == NULL)
		return (NULL);
	while (list->previous != NULL)
	{
		list = list->previous;
	}
	return (list);
}