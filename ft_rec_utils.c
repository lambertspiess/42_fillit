/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:11:31 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/23 17:11:21 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_map(char *p, int dim)
{
	int			i;
	int			j;

	i = -1;
	while (++i < dim)
	{
		j = -1;
		while (++j < dim)
		{
			if (i < dim && j < dim)
				*(p + (i * dim) + j) = '.';
		}
	}
}

int			ft_remove_piece(t_elem *node, char *map, int dim)
{
	int			i;
	int			j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim)
		{
			if (*(map + (j * dim) + i) == node->letter)
				*(map + (j * dim) + i) = '.';
		}
	}
	return (0);
}

int			ft_is_present(t_elem *node, char *map, int dim)
{
	int			i;
	int			j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim)
		{
			if (*(map + j * dim + i) == node->letter)
				return (1);
		}
	}
	return (0);
}
