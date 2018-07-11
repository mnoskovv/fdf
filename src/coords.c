/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:03:25 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 16:56:39 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coords			*new_elem(void)
{
	t_coords		*lst;

	if (!(lst = (t_coords*)malloc(sizeof(t_coords))))
		return (NULL);
	lst->next = NULL;
	lst->right = NULL;
	lst->down = NULL;
	return (lst);
}

void				put_coords(int tables, int lines, char **str, t_coords *c)
{
	char			*p;

	c->x = tables;
	c->tmp_x = tables;
	c->y = lines;
	c->tmp_y = lines;
	c->z = ft_atoi(str[tables]);
	c->tmp_z = ft_atoi(str[tables]);
	if ((p = ft_strchr(str[tables], ',')))
		c->color = put_color(p + 3, 16);
	else
		c->color = 0xFFFFFF;
}

void				del(char **str, char *line)
{
	int				i;

	i = -1;
	while (str[++i])
		ft_strdel(&(str[i]));
	free(str);
	free(line);
}

void				create_list1(int lines_tables[3], t_add *a, t_coords *first)
{
	char			*line;
	char			**str;

	line = 0;
	while (get_next_line(lines_tables[2], &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		lines_tables[0] = 0;
		while (lines_tables[0] < a->width)
		{
			put_coords(lines_tables[0], lines_tables[1], str, first);
			if (lines_tables[0] == a->width - 1 &&
				lines_tables[1] == a->height - 1)
				first->next = NULL;
			else
				first->next = new_elem();
			first = first->next;
			lines_tables[0]++;
		}
		lines_tables[1]++;
		del(str, line);
	}
}

t_coords			*create_list(int fd, t_add *a)
{
	int				lines_tables[3];
	t_coords		*first;
	t_coords		*begin;

	first = new_elem();
	begin = first;
	lines_tables[0] = 0;
	lines_tables[1] = 0;
	lines_tables[2] = fd;
	create_list1(lines_tables, a, first);
	lines_tables[0] = 0;
	return (begin);
}
