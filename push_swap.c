/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:27:08 by tquence           #+#    #+#             */
/*   Updated: 2020/01/30 17:27:09 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void    ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
}

void    sb(t_stack *b)
{
    sa(b);
}

void    sa(t_stack *a)
{
    int c;
    int i;

    i = 0;
    if (a->size >= 2)
    {
        c = a->nb[0];
        a->nb[0] = a->nb[1];
        a->nb[1] = c;
    }
    else
        return ;
    // while (i < a->size)
    // {
    //     printf("%d ", a->nb[i]);
    //     i++;
    // }
}

void    pb(t_stack *a, t_stack *b)
{
    pa(b, a);
}

void    pa(t_stack *a, t_stack *b)
{
    int i;
    int j;
    // int i = a->size - 1;
    // while (i)
    // {
    //     a->nb[i + 1] = a->nb[i];
    //     i--;
    // }
    // a->size++;
    // if (!b->size)
    //     return ;
    // while (i < b->size - 1)
    // {
    //     b->nb[i] = b->nb[i + 1];
    //     i++;
    // }
    // b->size--;
    i = 0;
    j = a->size;
    if (b->size != 0)
    {        
        while (j >= 1)
        {
            a->nb[j] = a->nb[j - 1];
            j--;
        }
        a->nb[i] = b->nb[i];
        a->size++;
        while (i < b->size - 1)
        {
            b->nb[i] = b->nb[i + 1];
            i++;
        }
        b->size--;
     }
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    ra(b);
}

void    rb(t_stack *b)
{
    ra(b);
}

void    ra(t_stack *a)
{
    int i;
    int c;

    i = 0;
    if (a->size != 0)
    {
        c = a->nb[0];
        while (i < a->size - 1)
        {
            a->nb[i] = a->nb[i + 1];
            i++;
        }
        a->nb[a->size - 1] = c; 
        // c = a->nb[i];
        // while (i < a->size - 1)
        // {
        //     a->nb[i] = a->nb[i + 1];
        //     i++;
        // }
        // a->nb[i] = c;
        // i = 0;
    }
}

void    rrr(t_stack *a, t_stack *b)
{
    ra(a);
    ra(b);
}

void    rrb(t_stack *b)
{
    ra(b);
}

void    rra(t_stack *a)
{
    int i;
    int c;

    if (a->size != 0)
    {
        i = a->size;
        c = a->nb[a->size - 1];
        while (i >= 1)
        {
            a->nb[i] = a->nb[i - 1];
            i--;
        }
        i = 0;
        a->nb[i] = c;
        // while (i < x->size)
        // {
        //     printf("%d", x->nb[i]);
        //     i++;
        // }
    }
    // printf(" ");
}

// void    swap_steps(t_stack *a, t_stack *b, int command)
// {
//     if (command == SA)
//         swap_elements(a);
//     else if (command == SB)
//         swap_elements(b);
//     else if (command == SS)
//     {
//         swap_elements(a);
//         swap_elements(b);
//     }
//     if (command == PA)
//         push_elements(a, b);
//     else if (command == PB)
//         push_elements(b, a);
//     else if (command == RA)
//         rotate_elements(a);
//     else if (command == RB)
//         rotate_elements(b);
//     else if (command == RR)
//     {
//         rotate_elements(a);
//         rotate_elements(b);
//     }
//     else if (command == RRA)
//         reverse_rotate(a);
//     else if (command == RRB)
//         reverse_rotate(b);
//     else if (command == RRR)
//     {
//         reverse_rotate(a);
//         reverse_rotate(b);
//     }
// }
