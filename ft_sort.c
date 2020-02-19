/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:46:39 by tquence           #+#    #+#             */
/*   Updated: 2020/02/15 20:43:50 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap_e(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	bubble_sort(int *arr, int size)
{
	int fl;
	int i;

	while (1)
	{
		i = 0;
		fl = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap_e(&arr[i], &arr[i + 1]);
				fl = 1;
			}
			i++;
		}
		if (!fl)
			break ;
	}
}

void	ft_sort(t_stack *a)
{
	t_stack *c;
	int		i;

	i = 0;
	c = (t_stack *)ft_memalloc(sizeof(t_stack));
	c->nb = (int *)ft_memalloc(sizeof(int) * a->size);
	c->size = a->size;
	while (i < a->size)
	{
		c->nb[i] = a->nb[i];
		i++;
	}
	bubble_sort(c->nb, c->size);
	if_repeat(c->nb, c->size);
	a->min = c->nb[0];
	a->max = c->nb[c->size - 1];
	a->mid = c->nb[a->size / 2];
	// free(c->nb);
	// free(c);
}

void	if_repeat(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			ft_putstr("Error");
			exit(1);
		}
		i++;
	}
}

void    ft_presort(t_stack *a, t_stack *b)
{
	while (a->size != 2)
    {
        if ((a->nb[0] == a->min) || (a->nb[0] == a->max)) {
        {
			ra(a);
			ft_putstr("ra\n");
		}
        } else
		{
            pb(a, b);
			ft_putstr("pb\n");
            if (b->nb[0] > a->mid)
            {
				rb(b);
				ft_putstr("rb\n");
			}
        }
    }
    if (a->nb[0] < a->nb[1])
    {
		ra(a);
		ft_putstr("ra\n");
	}
    pa(a, b);
	ft_putstr("pa\n");
}
