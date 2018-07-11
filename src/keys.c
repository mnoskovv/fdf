/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:03:32 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 16:07:07 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			exit_x(int key, t_all *all)
{
	(void)all;
	(void)key;
	exit(0);
	return (0);
}

void		chahge_color(t_coords *list, unsigned int color)
{
	while (list)
	{
		list->color = color;
		list = list->next;
	}
}

void		handle_2(int key, t_all *all)
{
	(void)key;
	dooo(all);
	mlx_put_image_to_window(all->wind->mlx, all->wind->window,
		all->wind->image, 0, 0);
	hints(all->wind);
}

void		handle_1(int key, t_all *all)
{
	if (key == 83)
	{
		all->add->a = 0;
		all->add->b = 0;
		all->add->c = 0;
	}
	else if (key == 84)
	{
		all->add->a = 0;
		all->add->b = 1.61;
		all->add->c = 0;
	}
	else if (key == 85)
		all->add->c = 0;
	else if (key == 20)
		chahge_color(all->list, 0x00FF00);
	else if (key == 21)
		chahge_color(all->list, 0xFFFF12);
	else if (key == 22)
		chahge_color(all->list, 0xFF0000);
	else if (key == 23)
		chahge_color(all->list, 0x0000FF);
	else if (key == 24)
		chahge_color(all->list, 0xFF00FF);
}

int			hadle_input_key(int key, t_all *all)
{
	if (key == 53)
		exit_x(key, all);
	else if (key == 18)
		all->add->k += 5;
	else if (key == 19 && all->add->k > 5)
		all->add->k -= 5;
	else if (key == 2)
		all->add->sdvig_x += 3;
	else if (key == 0)
		all->add->sdvig_x -= 3;
	else if (key == 1)
		all->add->sdvig_y += 3;
	else if (key == 13)
		all->add->sdvig_y -= 3;
	else if (key == 125)
		all->add->a += 0.07;
	else if (key == 126)
		all->add->a -= 0.07;
	else if (key == 124)
		all->add->b += 0.07;
	else if (key == 123)
		all->add->b -= 0.07;
	handle_1(key, all);
	handle_2(key, all);
	return (0);
}
