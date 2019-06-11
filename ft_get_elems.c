/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 03:34:10 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/07 16:22:01 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_add_end_node(t_elem **p_node, char tab[4][4])
{
	t_elem		*node;

	if (!(*p_node))
	{
		if (!(*p_node = (t_elem *)malloc(sizeof(t_elem))))
			return (0);
		(*p_node)->letter = 'A';
		(*p_node)->next = NULL;
		(*p_node)->prev = NULL;
		ft_memmove((*p_node)->arr, tab, 16);
		return (1);
	}
	node = *p_node;
	while (node->next)
		node = node->next;
	if (!(node->next = (t_elem *)malloc(sizeof(t_elem))))
		return (0);
	node->next->letter = node->letter + 1;
	node->next->prev = node;
	node = node->next;
	ft_memmove(node->arr, tab, 16);
	node->next = NULL;
	return (1);
}

int			ft_is_valid(t_elem **p_node, char *line, int i)
{
	if ((i < 4 && ft_strlen(line) != 4) || (i == 4 && ft_strlen(line)))
	{
		ft_free_list(p_node);
		ft_memdel((void **)&line);
		return (0);
	}
	return (1);
}

t_elem		*ft_get_elems(int fd, t_elem **p_node)
{
	char		tab[4][4];
	int			i;
	int			linenb;
	char		*line;

	i = -1;
	linenb = 0;
	line = NULL;
	while (++i < 5 && get_next_line(fd, &line) > 0)
	{
		if (!(ft_is_valid(p_node, line, i)))
			return (NULL);
		ft_strncpy(tab[i], line, 4);
		linenb++;
		free(line);
		line = NULL;
		if (i == 3)
			ft_add_end_node(p_node, tab);
		linenb = (i == 4 ? 0 : linenb);
		i = i == 4 ? -1 : i;
	}
	ft_memdel((void **)&line);
	if (linenb != 4)
		ft_free_list(p_node);
	return (linenb == 4 ? *p_node : NULL);
}
