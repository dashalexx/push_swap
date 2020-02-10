/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:12:15 by tquence           #+#    #+#             */
/*   Updated: 2020/02/10 16:12:17 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

int		ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	roll_a(t_stack *a)
{
	if (a->flag > 0)
	{
		while (a->flag)
		{
			ra(a);
			// ft_putstr("ra\n");
			a->flag--;
		}
	}
	else if (a->flag < 0)
	{
		while (a->flag)
		{
			rra(a);
			// ft_putstr("rra\n");
			a->flag++;
		}
	}
}

void	roll_b(t_stack *b)
{
	if (b->flag > 0)
	{
		while (b->flag)
		{
			rb(b);
			// ft_putstr("rb\n");
			b->flag--;
		}
	}
	else if (b->flag < 0)
	{
		while (b->flag)
		{
			rrb(b);
			// ft_putstr("rrb\n");
			b->flag++;
		}
	}
}

void	algos(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		// print_stack(b);
		// print_stack(a);
		// print_stack(b);
		// print_stack(a);
		count_steps(a, b);
		roll_a(a);
		roll_b(b);
		pa(a, b);
		// ft_putstr("pa\n");
	}
}
