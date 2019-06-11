/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:47:00 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 17:58:22 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	long	i;
	char	*s2;

	i = (long)(ft_strlen(s1) + 1);
	if (!(s2 = (char *)malloc(sizeof(char) * (unsigned long)i)))
		return (0);
	s2[i - 1] = '\0';
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	return (s2);
}
