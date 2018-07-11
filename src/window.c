/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:03 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 16:18:02 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_window		*new_window(void)
{
	t_window	*new;

	new = (t_window *)ft_memalloc(sizeof(t_window));
	new->image = NULL;
	new->window = NULL;
	new->adress = NULL;
	new->endian = 0;
	new->size_line = 0;
	new->bpp = 0;
	return (new);
}

void			create_window(t_window **window)
{
	(*window)->mlx = mlx_init();
	(*window)->window = mlx_new_window((*window)->mlx,
					SIZE_W, SIZE_H, "FDF");
}

void			hints(t_window *wind)
{
	mlx_string_put(wind->mlx, wind->window, 1200, 1050, 0xFF0000,\
		"Change of size: 1 2");
	mlx_string_put(wind->mlx, wind->window, 1200, 1075, 0xFF0000,\
		"Rotate: ^, v, ->, <-");
	mlx_string_put(wind->mlx, wind->window, 1200, 1100, 0xFF0000,\
		"Move: W, A, S, D");
	mlx_string_put(wind->mlx, wind->window, 1200, 1125, 0xFF0000,\
		"Change of color: 3, 4, 5, 6");
	mlx_string_put(wind->mlx, wind->window, 1200, 1150, 0xFF0000,\
		"Proections: NUM 1, NUM 2");
	mlx_string_put(wind->mlx, wind->window, 1200, 1175, 0xFF0000,\
		"Exit: [esc]");
}
