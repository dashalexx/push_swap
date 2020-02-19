/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:39:46 by tquence           #+#    #+#             */
/*   Updated: 2020/02/08 19:39:48 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int recount(int i, int size)
{
    if (size <= 3 || ft_abs(i) < size / 2 || !i)
        return (i);
    if (i > 0)
        return (i - size);
    return (size + i);
}

int	count_b(int i, t_stack *b)
{
	if (b->size <= 3 || !i)
		return (i);
	if (i < b->size / 2)
        return (i);
	return (i - b->size);
}


int	count_a(int b, t_stack *a)
{
	int i;
	int t;
	int tmp;

	i = 0;
	if (b < a->nb[0] && b > a->nb[a->size - 1])
		return (0);
	if (b > a->nb[0])
	{
		while (b > a->nb[i])
			i++;
	}
	else
	{
		tmp = a->size - 1;
		while (b < a->nb[tmp--])
			i--;
	}
	t = recount(i, a->size);
	return (t);
}

void	count_steps(t_stack *a, t_stack *b)
{
	int k;
	int i;
	int tmp1;
	int tmp2;

	i = 1;
	a->flag = count_a(b->nb[0], a);
	b->flag = count_b(0, b);
	k = ft_abs(a->flag) + ft_abs(b->flag);
	if (!k)
		return ;
	while (i < b->size)
	{
		tmp1 = count_a(b->nb[i], a);
		tmp2 = count_b(i, b);
		if (ft_abs(tmp1) + ft_abs(tmp2) < k)
		{
			k = ft_abs(tmp1) + ft_abs(tmp2);
			a->flag = tmp1;
			b->flag = tmp2;
		}
		i++;
	}
}

int find_i(t_stack *a)
{
	int i;

	i = 0;
	while (a->nb[i] != a->min)
			i++;
	return (i);
}

void	finish(t_stack *a, int i)
{
	if (i < a->size / 2)
	{
		while (a->min != a->nb[0])
		{
			ra(a);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while (a->min != a->nb[0])
		{
			rra(a);
			ft_putstr("rra\n");
		}
	}
}