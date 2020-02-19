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
			ft_putstr("ra\n");
			a->flag--;
		}
	}
	else if (a->flag < 0)
	{
		while (a->flag)
		{
			rra(a);
			ft_putstr("rra\n");
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
			ft_putstr("rb\n");
			b->flag--;
		}
	}
	else if (b->flag < 0)
	{
		while (b->flag)
		{
			rrb(b);
			ft_putstr("rrb\n");
			b->flag++;
		}
	}
}

void    roll_ab(t_stack *a, t_stack *b)
{
    if (a->flag > 0)
    {
        while (a->flag && b->flag)
        {
            rr(a, b);
			ft_putstr("rr\n");
            a->flag--;
            b->flag--;
        }
    }
    else
    {
        while (a->flag && b->flag)
        {
            rrr(a, b);
			ft_putstr("rrr\n");
            a->flag++;
            b->flag++;
        }
    }
}


void	algos(t_stack *a, t_stack *b)
{
	while (b->size)
	{
		count_steps(a, b);
		if ((a->flag > 0 && b->flag > 0) || (a->flag < 0 && b->flag < 0))
		    roll_ab(a, b);
		roll_a(a);
		roll_b(b);
		pa(a, b);
		ft_putstr("pa\n");
	}
}
