/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 05:20:28 by lspiess           #+#    #+#             */
/*   Updated: 2019/06/07 15:01:06 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_error_msg(int no, t_elem **p_node)
{
	if (no == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	if (no == 2)
	{
		ft_putstr("error\n");
		ft_free_list(p_node);
	}
	return (1);
}
