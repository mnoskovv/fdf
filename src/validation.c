/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:42 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 17:02:21 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		free_arr(char **splitted)
{
	int		i;

	i = 0;
	while (splitted[i])
		ft_strdel(&(splitted[i++]));
	free(splitted);
}

int			len_2d_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

static int	check_nums(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		if (array[i] && ft_atoi(array[i]) == 0 && array[i][0] != '0')
			return (0);
		else
			i++;
	}
	return (1);
}

void		is_valid2(int fst_h[3], char **sptd, t_add *a, char *line)
{
	while (get_next_line(fst_h[2], &line) > 0)
	{
		sptd = ft_strsplit(line, ' ');
		if (len_2d_array(sptd) != fst_h[0])
		{
			free_arr(sptd);
			free(line);
			exit_errors(1);
		}
		if (check_nums(sptd) == 0)
		{
			free_arr(sptd);
			free(line);
			exit_errors(1);
		}
		free_arr(sptd);
		free(line);
		fst_h[1]++;
	}
	a->width = fst_h[0];
	a->height = fst_h[1];
}

int			is_valid(int fd, t_add *a)
{
	int		first_height[3];
	char	*line;
	char	**splitted;

	line = NULL;
	first_height[0] = 0;
	first_height[1] = 0;
	first_height[2] = fd;
	get_next_line(fd, &line);
	if (!line)
		exit_errors(1);
	first_height[1]++;
	if (!line)
		exit_errors(2);
	splitted = ft_strsplit(line, ' ');
	first_height[0] = len_2d_array(splitted);
	if (check_nums(splitted) == 0)
	{
		free_arr(splitted);
		exit_errors(1);
	}
	free(line);
	free_arr(splitted);
	is_valid2(first_height, splitted, a, line);
	return (1);
}
