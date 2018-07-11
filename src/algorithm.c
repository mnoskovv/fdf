/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:03:20 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 16:08:33 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				draw(t_window *wind, t_coords *list)
{
	t_coords		*start;

	start = list;
	while (start->next)
	{
		if (start->right)
			connect(start, start->right, wind);
		if (start->down)
			connect(start, start->down, wind);
		start = start->next;
	}
}

void				connect(t_coords *list, t_coords *common, t_window *wind)
{
	t_coords		*start;

	start = list;
	start->dx = (common->new_x - start->new_x >= 0 ? 1 : -1);
	start->dy = (common->new_y - start->new_y >= 0 ? 1 : -1);
	start->length_x = abs(common->new_x - start->new_x);
	start->length_y = abs(common->new_y - start->new_y);
	start->length = fmax(start->length_x, start->length_y);
	if (!start->length)
	{
		if (common->new_x >= 0 && common->new_y >= 0 && common->new_x < SIZE_W
							&& common->new_y < SIZE_H)
			wind->adress[common->new_y * SIZE_W + common->new_x] = list->color;
	}
	if (start->length_y <= start->length_x)
		connect_x(list, wind);
	else
		connect_y(list, wind);
}

void				connect_y(t_coords *list, t_window *wind)
{
	int				x;
	int				y;
	t_coords		*start;

	start = list;
	x = start->new_x;
	y = start->new_y;
	start->d = -(start->length_y);
	start->length = (start->length) + 1;
	while (start->length--)
	{
		if (x >= 0 && y >= 0 && x < SIZE_W && y < SIZE_H)
			wind->adress[y * SIZE_W + x] = list->color;
		y = y + start->dy;
		start->d = start->d + (2 * (start->length_x));
		if (start->d > 0)
		{
			(start->d) = start->d - (2 * (start->length_y));
			x = x + (start->dx);
		}
	}
}

void				connect_x(t_coords *list, t_window *wind)
{
	int				x;
	int				y;
	t_coords		*start;

	start = list;
	x = start->new_x;
	y = start->new_y;
	start->d = -(start->length_x);
	start->length = (start->length) + 1;
	while (start->length--)
	{
		if (x >= 0 && y >= 0 && x < SIZE_W && y < SIZE_H)
			wind->adress[y * SIZE_W + x] = list->color;
		x = x + start->dx;
		start->d = start->d + (2 * (start->length_y));
		if (start->d > 0)
		{
			(start->d) = start->d - (2 * (start->length_x));
			y = y + (start->dy);
		}
	}
}

unsigned int		put_color(char *str, int base)
{
	unsigned int	i;
	int				k;

	i = 0;
	k = 0;
	if (!str)
		return (0);
	while (str[k] == ' ' || (str[k] >= 9 && str[k] <= 13))
	{
		i++;
		k++;
	}
	while (str[k] && ((ft_isdigit(str[k]) || (str[k] >= 'A' && str[k] <= 'F'))
		|| (str[k] >= 'a' && str[k] <= 'f')))
	{
		i = (i * base);
		if (str[k] < 97)
			i += (str[k] - (str[k] <= 57 ? 48 : 55));
		else
			i += str[k] - 87;
		k++;
	}
	return (i);
}
