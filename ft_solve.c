/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:22:20 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/29 03:22:26 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_bounds(t_elem *node, int coords, int dim)
{
	int			i;
	int			j;

	i = coords / 1000;
	j = coords % 1000;
	if (i - 1 + node->wid > dim - 1 || j - 1 + node->hei > dim - 1)
		return (0);
	return (1);
}

int			ft_try_position(t_elem *node, char *map, int coords, int dim)
{
	int			i;
	int			j;

	i = coords / 1000;
	j = coords % 1000;
	if (!(ft_check_bounds(node, coords, dim)))
		return (0);
	if ((*(map + dim * (j + node->ay) + i + node->ax) == '.')
		&& (*(map + dim * (j + node->by) + i + node->bx) == '.')
		&& (*(map + dim * (j + node->cy) + i + node->cx) == '.')
		&& (*(map + dim * (j + node->dy) + i + node->dx) == '.'))
	{
		*(map + dim * (j + node->ay) + i + node->ax) = node->letter;
		*(map + dim * (j + node->by) + i + node->bx) = node->letter;
		*(map + dim * (j + node->cy) + i + node->cx) = node->letter;
		*(map + dim * (j + node->dy) + i + node->dx) = node->letter;
		return (1);
	}
	return (0);
}

int			ft_try_elem(t_elem *node, char *map, int dim)
{
	int			i;
	int			j;
	int			coords;

	if (!(node))
		return (1);
	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim)
		{
			coords = i * 1000 + j;
			if (ft_try_position(node, map, coords, dim))
			{
				if (ft_try_elem(node->next, map, dim))
					return (1);
			}
		}
	}
	if (node->prev)
		ft_remove_piece(node->prev, map, dim);
	return (0);
}

int			ft_try_dim(t_elem **p_node, int dim)
{
	char		*map;
	t_elem		*node;

	node = *p_node;
	if (!(map = (char *)malloc((unsigned long)(dim * dim))))
		return (0);
	ft_init_map(map, dim);
	if (ft_try_elem(node, map, dim))
	{
		ft_print_square(map, dim);
		ft_free_list(p_node);
		free(map);
	}
	else
	{
		free(map);
		ft_try_dim(&node, dim + 1);
	}
	return (1);
}
