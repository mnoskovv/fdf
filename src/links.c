/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:26 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/07 21:04:39 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				find_down_link(t_coords **list)
{
	t_coords	*p;
	t_coords	*temp;

	p = *list;
	while (p && p->y == 0)
		p = p->next;
	temp = *list;
	while (p)
	{
		temp->down = p;
		p = p->next;
		temp = temp->next;
	}
	return (0);
}

int				find_next_link(t_coords *list)
{
	t_coords	*lst;

	lst = list;
	while (lst->next)
	{
		if (lst->y == lst->next->y)
			lst->right = lst->next;
		lst = lst->next;
	}
	find_down_link(&list);
	return (0);
}
