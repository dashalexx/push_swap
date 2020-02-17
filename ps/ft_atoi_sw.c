/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_sw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:15:24 by tquence           #+#    #+#             */
/*   Updated: 2020/02/14 17:15:26 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

int				ft_atoi_psw(const char *str)
{
	long int	a;
	long int	zn;

	a = 0;
	zn = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' && *(str + 1) != '-' && *(str + 1) != '+')
	{
		zn *= -1;
		str++;
	}
	if (*str == '+' && *(str + 1) != '-' && *(str + 1) != '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		a = (a * 10) + (*str - 48);
		str++;
	}
	if ((a > 2147483648 && zn < 0) || (a > 2147483647 && zn > 0))
		ft_putstr_er("Error\n");
	return (a * zn);
}
