/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:33:17 by tquence           #+#    #+#             */
/*   Updated: 2020/01/30 17:33:20 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H_

#define FT_PUSH_SWAP_H_

#include "libft/libft.h"
#include "stdlib.h"
#include <stdio.h>

typedef struct  s_stack
{
    int         *nb;
    int         size;
    int         max;
    int         min;
    int         oper;
    int         flag;
}               t_stack;

void    print_stack(t_stack *a);
void	swap_max_min(t_stack *a, t_stack *b);
void	if_repeat(int *arr, int size);
void	ft_sort(t_stack *a);
void    init_struct(char *line, t_stack *a);
int     valid_arg(char *line, t_stack *a);
void    count_arg(char *map, t_stack *a);
void    push_elements(t_stack *a, t_stack *b);
void    swap_elements(t_stack *x);
void    ss(t_stack *a, t_stack *b);
void    sb(t_stack *b);
void    sa(t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rb(t_stack *b);
void    ra(t_stack *a);
void    rrr(t_stack *a, t_stack *b);
void    rrb(t_stack *b);
void    rra(t_stack *a);
void    count_steps(t_stack *a, t_stack *b);
int     count_a(int b, t_stack *a);
int     count_b(int i, t_stack *b);
void	algos(t_stack *a, t_stack *b);
int		ft_abs(int num);

#endif
