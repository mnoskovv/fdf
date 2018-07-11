/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:03:45 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 16:18:44 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		dooo(t_all *all)
{
	ft_bzero(all->wind->adress, SIZE_W * SIZE_H * 4);
	scale(all->list, all->add);
	draw(all->wind, all->list);
}

void		main2(t_all *all, t_add *add, t_window *wind, t_coords *list)
{
	create_window(&wind);
	wind->image = mlx_new_image(wind->mlx, SIZE_W, SIZE_H);
	wind->adress = (int *)mlx_get_data_addr(wind->image, \
			&wind->endian, &wind->size_line, &wind->bpp);
	add->k = fmin((SIZE_W / 2) / add->width, (SIZE_H / 2) / add->height);
	add->sdvig_x = 0;
	add->sdvig_y = 0;
	all->list = list;
	all->wind = wind;
	all->add = add;
	all->add->a = 0.4;
	all->add->b = 0.4;
	all->add->c = 3.2;
	dooo(all);
	mlx_put_image_to_window(wind->mlx, wind->window, wind->image, 0, 0);
	hints(all->wind);
	mlx_hook(all->wind->window, 2, 5, hadle_input_key, all);
	mlx_hook(all->wind->window, 17, 1L << 17, exit_x, all);
	mlx_loop(all->wind->mlx);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_coords	*list;
	t_add		*add;
	t_window	*wind;
	t_all		*all;

	if (argc == 2)
	{
		if (!(all = malloc(sizeof(t_all))))
			return (0);
		if (!(add = malloc(sizeof(t_add))))
			return (0);
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			exit_errors(2);
		is_valid(fd, add);
		close(fd);
		fd = open(argv[1], O_RDONLY);
		list = create_list(fd, add);
		find_next_link(list);
		wind = new_window();
		main2(all, add, wind, list);
	}
	else
		exit_errors(3);
	return (0);
}
