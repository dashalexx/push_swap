/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:33:17 by tquence           #+#    #+#             */
/*   Updated: 2020/02/15 19:54:06 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H_

#define FT_PUSH_SWAP_H_

#include "libft/libft.h"
#include "stdlib.h"
#include <stdio.h>
#include <unistd.h>

typedef struct  s_stack
{
    int         *nb;
    int         size;
    int         max;
    int         min;
//    int         *step;
    int         flag;
    int         mid;
}               t_stack;

void    ft_presort(t_stack *a, t_stack *b);
void	swap_max_min(t_stack *a, t_stack *b);
void	if_repeat(int *arr, int size);
void	ft_sort(t_stack *a);
void    init_struct(char *line, t_stack *a);
int     valid_arg(char *line);
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
void	ft_swap_e(int *a, int *b);
void	finish(t_stack *a, int i);
int     find_i(t_stack *a);
int		ft_atoi_psw(const char *str);
void	ft_putstr_er(char const *s);
void	how_some(t_stack *a);
void	three(t_stack *a);
void	three2(t_stack *a);
void	five(t_stack *a, t_stack *b);
void	five2(t_stack *a, t_stack *b);
int 	is_sort(t_stack *a);
void    check(t_stack *a, t_stack *b);

#endif
