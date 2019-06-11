/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 07:41:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/29 03:21:37 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_coords(t_elem **p_node, int i, int j, int blckidx)
{
	t_elem		*node;

	node = *p_node;
	if (blckidx == 0)
	{
		node->ax = j;
		node->ay = i;
	}
	else if (blckidx == 1)
	{
		node->bx = j;
		node->by = i;
	}
	else if (blckidx == 2)
	{
		node->cx = j;
		node->cy = i;
	}
	else if (blckidx == 3)
	{
		node->dx = j;
		node->dy = i;
	}
}

void		ft_get_elem_coords(t_elem **p_node)
{
	t_elem		*node;
	int			i;
	int			j;
	int			blockidx;

	blockidx = 0;
	node = *p_node;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((node->arr)[i][j] == '#')
			{
				ft_init_coords(&node, i, j, blockidx);
				blockidx++;
			}
		}
	}
}

void		ft_get_coords(t_elem **p_node)
{
	t_elem		*node;

	node = *p_node;
	while (node)
	{
		ft_get_elem_coords(&node);
		node = node->next;
	}
}
