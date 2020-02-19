/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:41:29 by tquence           #+#    #+#             */
/*   Updated: 2019/04/08 20:23:05 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_strdup(const char *s1)
{
	int			i;
	int			len;
	char		*s2;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (s2 == 0)
		return (0);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
