/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smagdela <smagdela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:44:06 by smagdela          #+#    #+#             */
/*   Updated: 2021/09/22 17:46:57 by smagdela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*lst_last(t_link *link)
{
	if (link == NULL)
		return (NULL);
	while (link->next != NULL)
	{
		link = link->next;
	}
	return (link);
}
