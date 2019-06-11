/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 05:46:44 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/11 09:30:46 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_count_dots_and_hashes(char tab[4][4])
{
	int			i;
	int			j;
	int			dots;
	int			hashes;

	dots = 0;
	hashes = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tab[i][j] == '.')
				++dots;
			else if (tab[i][j] == '#')
				++hashes;
			else
				return (0);
		}
	}
	return (hashes == 4 ? 1 : 0);
}

int			ft_count_contacts(char tab[4][4], int i, int j)
{
	int			contacts;

	contacts = 0;
	if (i > 0 && tab[i - 1][j] == '#')
		++contacts;
	if (i < 3 && tab[i + 1][j] == '#')
		++contacts;
	if (j > 0 && tab[i][j - 1] == '#')
		++contacts;
	if (j < 3 && tab[i][j + 1] == '#')
		++contacts;
	return (contacts);
}

int			ft_check_shape(char tab[4][4], t_elem **p_node)
{
	int			i;
	int			j;
	int			contacts;

	contacts = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (tab[i][j] == '#')
				contacts += ft_count_contacts((*p_node)->arr, i, j);
		}
	}
	return (contacts == 6 || contacts == 8 ? 1 : 0);
}

int			ft_count_tetriminos(t_elem **p_node)
{
	int			count;
	t_elem		*node;

	node = *p_node;
	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count <= 26 ? 1 : 0);
}

int			ft_check_elems(t_elem **p_node)
{
	t_elem		*node;

	node = *p_node;
	if (!(ft_count_tetriminos(p_node)))
		return (0);
	while (node)
	{
		if (!(ft_count_dots_and_hashes(node->arr)))
			return (0);
		if (!(ft_check_shape(node->arr, &node)))
			return (0);
		if (node->next)
			node = node->next;
		else
			break ;
	}
	return (1);
}
