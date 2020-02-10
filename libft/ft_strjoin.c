/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:35:09 by tquence           #+#    #+#             */
/*   Updated: 2019/04/26 16:42:33 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*c;
	unsigned int	i;

	if (s1 && s2)
	{
		i = 0;
		if (!(c = (char *)malloc(sizeof(*c) +
						(ft_strlen(s1) + ft_strlen(s2) - 1))))
			return (0);
		while (*s1 != '\0')
		{
			c[i] = *s1;
			i++;
			s1++;
		}
		while (*s2 != '\0')
		{
			c[i] = *s2;
			i++;
			s2++;
		}
		c[i] = '\0';
		return (c);
	}
	return (0);
}
