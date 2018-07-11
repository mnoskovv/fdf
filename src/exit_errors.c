/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoskov <mnoskov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:04:14 by mnoskov           #+#    #+#             */
/*   Updated: 2018/07/08 15:59:09 by mnoskov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_errors(int flag)
{
	if (flag == 1)
		ft_putendl("invalid map!");
	else if (flag == 2)
		ft_putendl("cannot open file!");
	else if (flag == 3)
		ft_putendl("Usage : ./fdf [pathname]");
	exit(0);
}
