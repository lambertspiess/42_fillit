/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_measure_elems.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:21:38 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/29 03:24:54 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_get_wid(t_elem *node)
{
	int			i;
	int			j;
	int			wid;

	wid = 0;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4 && j < 4)
		{
			if ((node->arr)[i][j] == '#')
			{
				wid++;
				j++;
				i = -1;
			}
		}
	}
	return (wid);
}

int			ft_get_hei(t_elem *node)
{
	int			i;
	int			j;
	int			hei;

	hei = 0;
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 4 && j < 4)
		{
			if ((node->arr)[j][i] == '#')
			{
				hei++;
				j++;
				i = -1;
			}
		}
	}
	return (hei);
}

void		ft_measure_elems(t_elem **p_node)
{
	t_elem		*node;

	node = *p_node;
	while (node)
	{
		node->wid = ft_get_wid(node);
		node->hei = ft_get_hei(node);
		node = node->next;
	}
}
