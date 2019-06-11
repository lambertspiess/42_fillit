/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 23:24:59 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/07 15:56:22 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count_elems(t_elem **p_node)
{
	int			count;
	t_elem		*node;

	count = 0;
	node = *p_node;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}

int			ft_free_list(t_elem **p_node)
{
	t_elem		*node;
	t_elem		*prev;

	node = *p_node;
	while (node)
	{
		prev = node;
		node = node->next;
		free(prev);
	}
	free(node);
	return (1);
}
