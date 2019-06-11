/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:24:59 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/29 03:25:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_square(char *map, int dim)
{
	int			i;
	int			j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim)
		{
			ft_putchar(*(map + (j * dim) + i));
		}
		if (j <= dim)
			ft_putchar('\n');
	}
}
