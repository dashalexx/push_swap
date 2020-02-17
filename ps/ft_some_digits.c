/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:34:56 by tquence           #+#    #+#             */
/*   Updated: 2020/02/15 20:22:33 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	how_some(t_stack *a)
{
	if (a->size == 2)
	{
		if (is_sort(a) == 0)
		{
			sa(a);
			ft_putstr("sa\n");
		}
		exit (0);
	}
	else if (a->size == 3)
	{
		three(a);
		exit (0);
	}
}

void	three2(t_stack *a)
{
		rra(a);
		ft_putstr("rra\n");
		rra(a);
		ft_putstr("rra\n");
		sa(a);
		ft_putstr("sa\n");
}

void	three(t_stack *a)
{
	if (a->nb[0] > a->nb[1] && a->nb[0] < a->nb[2])
	{
		sa(a);
		ft_putstr("sa\n");
	}
	else if (a->nb[0] > a->nb[2] && a->nb[0] < a->nb[1])
	{
		rra(a);
		ft_putstr("rra\n");
	}
	else if (a->nb[2] > a->nb[0] && a->nb[2] < a->nb[1])
	{
		rra(a);
		ft_putstr("rra\n");
		sa(a);
		ft_putstr("sa\n");
	}
	else if (a->nb[2] > a->nb[1] && a->nb[2] < a->nb[0])
	{
		ra(a);
		ft_putstr("ra\n");
	}
	else if (a->nb[1] > a->nb[2] && a->nb[1] < a->nb[0])
		three2(a);	
}

void	five(t_stack *a, t_stack *b)
{
	while (a->size != 3)
	{
		if (a->nb[0] == a->min || a->nb[0] == a->max)
		{
			pb(a, b);
			ft_putstr("pb\n");
		}
		else
	 	{
			ra(a);
			ft_putstr("ra\n");
		}
	}
	if (a->nb[0] > a->nb[1])
	{
		ra(a);
		ft_putstr("ra\n");
	}
	five2(a, b);
}

void	five2(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (is_sort(a) == 0)
		three(a);
	if (b->nb[0] > b->nb[1])
	{
		sb(b);
		ft_putstr("sb\n");
	}
	while (b->size)
	{
		pa(a, b);
		ft_putstr("pa\n");
	}
	ra(a);
	ft_putstr("ra\n");                                                                                                                                     
	exit (0);
}
