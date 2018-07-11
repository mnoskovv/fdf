/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:09 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 16:14:26 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			center(t_coords *begin, t_add *a)
{
	t_coords	*start;

	start = begin;
	while (begin)
	{
		begin->x0 = a->width / 2;
		begin->y0 = a->height / 2;
		begin->z0 = (begin->tmp_z / 2);
		begin = begin->next;
	}
	begin = start;
}

void			turn(t_coords *begin, t_add *a)
{
	center(begin, a);
	while (begin)
	{
		begin->x1 = begin->x;
		begin->y1 = begin->y0 + (begin->y - begin->y0) * cos(a->a)
			+ (begin->z0 - begin->z) * sin(a->a);
		begin->z1 = begin->z0 + (begin->y - begin->y0) *
			sin(a->a) + (begin->z - begin->z0) * cos(a->a);
		begin->x2 = begin->x0 + (begin->x1 - begin->x0) *
			cos(a->b) + (begin->z1 - begin->z0) * sin(a->b);
		begin->y2 = begin->y1;
		begin->z2 = begin->z0 + (begin->x0 - begin->x1) *
			sin(a->b) + (begin->z1 - begin->z0) * cos(a->b);
		begin->x3 = begin->x0 + (begin->x2 - begin->x0) *
			cos(a->c) + (begin->y0 - begin->y2) * sin(a->c);
		begin->y3 = begin->y0 + (begin->x2 - begin->x0) *
			sin(a->c) + (begin->y2 - begin->y0) * cos(a->c);
		begin = begin->next;
	}
}

void			scale(t_coords *begin, t_add *a)
{
	int			width_map;
	int			height_map;
	t_coords	*start;

	start = begin;
	width_map = a->width;
	height_map = a->height;
	turn(begin, a);
	begin = start;
	while (begin)
	{
		begin->new_x = (SIZE_W / 2) + (width_map / 2 -
			begin->x3) * a->k + a->sdvig_x;
		begin->new_y = (SIZE_H / 2) + (height_map / 2 -
			begin->y3) * a->k + a->sdvig_y;
		begin = begin->next;
	}
	begin = start;
}
