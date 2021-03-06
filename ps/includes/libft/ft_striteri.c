/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 19:11:39 by tquence           #+#    #+#             */
/*   Updated: 2019/04/29 18:42:21 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	k;

	if (s && f)
	{
		k = 0;
		while (*s != '\0')
		{
			f(k, s);
			k++;
			s++;
		}
	}
}
