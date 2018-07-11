/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 15:09:37 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:51:30 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

# define SIZE_W 1500
# define SIZE_H 1200

typedef struct		s_coords
{
	double			x;
	double			y;
	double			z;

	double			tmp_x;
	double			tmp_y;
	double			tmp_z;

	double			z1;
	double			x1;
	double			y1;

	double			x2;
	double			y2;
	double			z2;

	double			x3;
	double			y3;

	double			x0;
	double			y0;
	double			z0;
	int				new_x;
	int				new_y;
	double			length_x;
	double			length_y;
	double			dx;
	double			dy;
	double			dz;
	double			d;
	double			length;
	unsigned int	color;
	struct s_coords	*right;
	struct s_coords	*down;
	struct s_coords	*next;
}					t_coords;

typedef struct		s_add
{
	double			a;
	double			b;
	double			c;
	double			k;
	double			sdvig_x;
	double			sdvig_y;
	int				width;
	int				height;

}					t_add;

typedef struct		s_window
{
	void			*mlx;
	void			*image;
	void			*window;
	int				*adress;
	int				endian;
	int				size_line;
	int				bpp;
}					t_window;

typedef struct		s_all
{
	t_coords		*list;
	t_add			*add;
	t_window		*wind;
}					t_all;

void				exit_errors(int flag);
int					is_valid(int fd, t_add *a);
int					len_2d_array(char **array);
t_coords			*new_elem(void);
void				remove_last(t_coords *first);
void				put_coords(int tables, int lines, char **str, t_coords *c);
t_coords			*create_list(int fd, t_add *a);
t_window			*new_window(void);
void				create_window(t_window **window);
int					find_next_link(t_coords *list);
int					find_next_link(t_coords *list);
void				scale(t_coords *begin, t_add *a);
void				connect_x(t_coords *list, t_window *wind);
void				connect_y(t_coords *list, t_window *wind);
void				connect(t_coords *list, t_coords *common, t_window *wind);
void				draw(t_window *wind, t_coords *list);
void				turn(t_coords *begin, t_add *a);
void				dooo(t_all *all);
void				handle_1(int key, t_all *all);
void				handle_2(int key, t_all *all);
void				main2(t_all *all, t_add *add, t_window *w, t_coords *list);
void				hints(t_window *wind);
int					exit_x(int key, t_all *all);
void				chahge_color(t_coords *list, unsigned int color);
void				handle_2(int key, t_all *all);
void				handle_1(int key, t_all *all);
int					hadle_input_key(int key, t_all *all);
void				create_list1(int lines_tab[3], t_add *a, t_coords *first);
void				del(char **str, char *line);
unsigned int		put_color(char *str, int base);
void				center(t_coords *begin, t_add *a);
void				is_valid2(int frs_hght[3], char **sptd, t_add *a, char *ln);

#endif
