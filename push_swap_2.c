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
#include <stdio.h>

void	swap_max_min(t_stack *a, t_stack *b)
{
	int i;

	i = a->size;
	while (i--)
	{
		if (a->nb[0] != a->min && a->nb[0] != a->max)
		{
			pb(a, b);
			//ft_putstr("pb\n");
			continue ;
		}
		//ft_putstr("ra\n");
	 	ra(a);
	}
	if (a->nb[0] < a->nb[1])
		//ft_putstr("ra\n");
		 ra(a);
	// b->size = a->size -2;
	// a->size -= 2;
}

int	count_b(int i, t_stack *b)
{
	if (!b->size)
		return (0);
	// if (i > b->size / 2 - 1)
	// 	return (i - b->size + 1);
	return (i);
}

int recount(int i, int size)
{
	if (size <= 3 || ft_abs(i) < size / 2 || !i)
		return (i);
	if (i > 0)
		return (i - size);
	return (size + i);
}

int	count_a(int b, t_stack *a)
{
	int i;
	int t;
	int tmp;

	i = 0;
	// if (b == -12)
	// 	return -1;
		//print_stack(a);
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
		//i = a->size - 1;
		while (b < a->nb[tmp--])
			i--;
	}
	// if (b == 13)
	// {	
	// 	print_stack(a);
	// 	printf("%d", i);
	// }
	t = recount(i, a->size);
	if (b == -12)
	{
		printf("%d\n", b);
		printf("%d %d %d\n", i, t, a->size);
		print_stack(a);
	}
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
		
		//printf("\n%d %d\n", b->nb[i], a->flag);
		i++;
	}
	//print_stack(b);
	// printf("\n");
}