/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquence <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 19:19:37 by tquence           #+#    #+#             */
/*   Updated: 2020/02/15 20:44:07 by tquence          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sort(t_stack *a)
{
	int i;

	i = 0;
	while (i != a->size - 1 && (a->nb[i] < a->nb[i + 1]))
		i++;
	if (i == a->size - 1)
		return (1);
	return (0);
}

void	ft_putstr_er(char const *s)
{
        if (s)
        {
            while (*s != '\0')
            {
                write(2, s, 1);
                s++;
            }
        }
        exit(1);
}

int     ft_strlen_space(char *str)
{
    int k;

    k  = 0;
    if (*str == '-')
    {
        k++;
        str++;
    }
    while (*str != ' ' && *str != 0)
    {
        str++;
        k++;
    }
    return (k);
}

void    init_struct(char *line, t_stack *a)
{
    static int i = 0;

    while (*line)
    {
        if ((*line ==  '-' || *line == '+') && ft_isdigit(*(line + 1)) == 1)
        {
            if (ft_strlen_space(line) > 11)
                 ft_putstr_er("Error\n");
            a->nb[i] = ft_atoi_psw(line);
            i++;
            line++;
            while (ft_isdigit(*line))
                line++;
        }
        else if (*line == ' ' || (*line == '\t'))
            line++;
        else if (ft_isdigit(*line))
        {
            if (ft_strlen_space(line) > 10)
                ft_putstr_er("Error\n");
            a->nb[i] = ft_atoi_psw(line);
            i++;
            line++;
            while (ft_isdigit(*line))
                line++;
        }
    }
}

int     valid_arg(char *line)
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
            ft_putstr_er("Error\n");
    }
    return (0);
}

void count_arg(char *map, t_stack *a)
{
	int		i;

	i = 0;
	if (map[0] != ' ' && map[0] != 0)
		a->size++;
	while (map[i] != 0)
	{
		if ((map[i] == ' ') && (map[i + 1] != ' ' && map[i + 1]))
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
        valid_arg(argv[i]);
        count_arg(argv[i], a);
        i++;
    }
    if (!a->size)
        ft_putstr_er("Error\n");
    a->nb = (int *)ft_memalloc(sizeof(int) * a->size);
    i = 1;
    while (argv[i])
    {
        init_struct(argv[i], a);
        i++;
    }
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
        exit (0);
    ft_sort(a);
    how_some(a);
    b = (t_stack *)ft_memalloc(sizeof(t_stack));
    b->nb = (int *)ft_memalloc(sizeof(int) * a->size);
    ft_sort(a);
    if (is_sort(a) == 1)
        exit (0);
    if (a->size == 5)
        five(a, b);
    ft_presort(a, b);
    algos(a, b);
    i = find_i(a);
    finish(a, i);
    return (0);
}
