/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 22:26:20 by tquence           #+#    #+#             */
/*   Updated: 2020/02/15 20:30:24 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_push_swap.h"

void    valid_command(char *str)
{
    while (*str)
    {
        if (*str == ' ')
            ft_putstr_er("Error\n");
        str++;
    }
}

void    command(char *line, t_stack *a, t_stack *b)
{
    if (!(ft_strcmp(line, "sa")))
        sa(a);
    else if (!(ft_strcmp(line, "sb")))
        sb(b);
    else if (!(ft_strcmp(line, "pa")))
        pa(a, b);
    else if (!(ft_strcmp(line, "pb")))
        pb(a, b);
    else if (!(ft_strcmp(line, "ra")))
        ra(a);
    else if (!(ft_strcmp(line, "rb")))
        rb(b);
    else if (!(ft_strcmp(line, "rr")))
        rr(a, b);
    else if (!(ft_strcmp(line, "rra")))
        rra(a);
    else if (!(ft_strcmp(line, "rrb")))
        rrb(b);
    else if (!(ft_strcmp(line, "rrr")))
        rrr(a, b);
	else
		ft_putstr_er("Error\n");
}

void    check(t_stack *a, t_stack *b)
{
    char    *line;

    while (get_next_line(STDIN_FILENO, &line))
    {
        valid_command(line);
		command(line, a, b);
    }        
	if (is_sort(a) == 1)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
