/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 03:22:29 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/11 09:30:24 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int			fd;
	t_elem		*node;
	int			dim;

	node = NULL;
	if (ac != 2)
	{
		ft_putstr("usage : ./fillit tetriminos.txt\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY, 0444);
	if ((fd < 0 || read(fd, 0, 0) < 0) && ft_error_msg(1, &node))
		return (2);
	if (!(node = ft_get_elems(fd, &node)) && ft_error_msg(2, &node))
		return (2);
	if (!(ft_check_elems(&node)) && ft_error_msg(2, &node))
		return (2);
	ft_align_elems(&node);
	ft_measure_elems(&node);
	ft_get_coords(&node);
	dim = ft_isqrt(ft_count_elems(&node) * 4 + 1);
	ft_try_dim(&node, dim);
	return (0);
}
