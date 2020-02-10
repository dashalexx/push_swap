/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:19:37 by tquence           #+#    #+#             */
/*   Updated: 2020/01/31 19:19:39 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

void    init_struct(char *line, t_stack *a)
{
    static int i = 0;

    // a->nb = (int *)ft_memalloc(sizeof(int) * a->size);
    while (*line)
    {
        if ((*line ==  '-' || *line == '+') && ft_isdigit(*(line + 1)) == 1)
        {
            a->nb[i] = ft_atoi(line);
            // printf("%d ", a->nb[i]);
            i++;
            line++;
            while (ft_isdigit(*line))
                line++;
        }
        else if (*line == ' ' || (*line == '\t'))
            line++;
        else if (ft_isdigit(*line))
        {
            a->nb[i] = ft_atoi(line);
            // printf("%d ", a->nb[i]);
            i++;
            line++;
            while (ft_isdigit(*line))
                line++;
        }
    }
}

int    valid_arg(char *line, t_stack *a)
{
    if ((*line ==  '-' || *line == '+') && ft_isdigit(*(line + 1)) == 1)
    {
        line++;
        while (ft_isdigit(*line) == 1)
            line++;
    }
    while (*line)
    {
        if ((*line ==  '-' || *line == '+') && ft_isdigit(*(line + 1)) == 1
        && (*(line - 1)) == ' ')
            line++;
        else if (*line == ' ' || (*line == '\t'))
            line++;
        else if (ft_isdigit(*line))
            line++;
        else
        {
            ft_putstr("error\n");
            exit (1);
        }
    }
    return (0);
}

void count_arg(char *map, t_stack *a)
{
	int		i;

	i = 0;
	if (map[0] != ' ')
		a->size++;
	while (map[i] != 0)
	{
		if ((map[i] == ' ') && ((map[i + 1] != ' ' && map[i + 1])))
			a->size++;
		i++;
	}
}

void    parse_arg(char **argv, t_stack *a)
{
    int i;
    
    i = 1;
    while (argv[i])
    {
        valid_arg(argv[i], a);
        count_arg(argv[i], a);
        i++;
    }
    a->nb = (int *)ft_memalloc(sizeof(int) * a->size);
    i = 1;
    while (argv[i])
    {
        init_struct(argv[i], a);
        i++;
    }

}

void print_stack(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->size)
    {
        printf("%d ", a->nb[i]);
        i++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;

    a = (t_stack *)ft_memalloc(sizeof(t_stack));
    if (argc > 1)
        parse_arg(argv, a);
    else
    {
        ft_putstr("error\n");
            exit (1);
    }
    b = (t_stack *)ft_memalloc(sizeof(t_stack));
    b->nb = (int *)ft_memalloc(sizeof(int) * a->size);
    ft_sort(a);
    swap_max_min(a, b);
    algos(a, b);
    print_stack(a);
    // print_stack(b);
    // pa(a, b);
    //pa(a, b);
    //printf("%d", count_steps(a, b));
    return (0);
}
