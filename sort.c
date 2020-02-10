/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:46:39 by tquence           #+#    #+#             */
/*   Updated: 2020/02/08 17:46:41 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	bubble_sort(int *arr, size_t size)
{
	int fl;
	int i;
	int it = size - 1;

	while (1)
	{
		i = 0;
		fl = 0;
		while (i < size - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				ft_swap(&arr[i], &arr[i + 1]);
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
	int		x;
	int		flag;

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
	i = 0;
	// while (i < a->size)
	// {
	// 	printf("%d ", c->nb[i]);
	// 	i++;
	// }
}

void	if_repeat(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			ft_putstr("error");
            exit (1);
		}
		i++;
	}
}