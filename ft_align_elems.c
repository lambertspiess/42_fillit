/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_align_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 09:28:34 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/29 03:22:17 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_measure_gap_vert(t_elem **p_node)
{
	int			i;
	int			j;
	int			vert;

	i = -1;
	vert = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (((*p_node)->arr)[i][j] == '#')
				return (vert);
		}
		vert++;
	}
	return (vert);
}

int			ft_measure_gap_horz(t_elem **p_node)
{
	int			i;
	int			j;
	int			horz;

	i = -1;
	horz = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (((*p_node)->arr)[j][i] == '#')
				return (horz);
		}
		horz++;
	}
	return (horz);
}

void		ft_translate(t_elem **p_node, int vert, int horz)
{
	int			i;
	int			j;

	if (vert == 0 && horz == 0)
		return ;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (((*p_node)->arr)[i][j] == '#')
			{
				((*p_node)->arr)[i - vert][j - horz] = '#';
				((*p_node)->arr)[i][j] = '.';
			}
		}
	}
}

void		ft_align_elems(t_elem **p_node)
{
	int			vert;
	int			horz;
	t_elem		*node;

	node = *p_node;
	while (node)
	{
		vert = ft_measure_gap_vert(&node);
		horz = ft_measure_gap_horz(&node);
		ft_translate(&node, vert, horz);
		node = node->next;
	}
}
