/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspiess <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:46:22 by lspiess           #+#    #+#             */
/*   Updated: 2019/05/14 17:58:42 by lspiess          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_l(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char					*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	unsigned long	j;
	char			*sc;

	if (!s1 || !s2)
		return (NULL);
	if (!(sc = (char *)malloc(sizeof(char) * (ft_l(s1) + ft_l(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sc[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		sc[j] = s2[i];
		i++;
		j++;
	}
	sc[j] = '\0';
	return (sc);
}
