/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 15:07:10 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/22 17:46:50 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int	number_loop;

	number_loop = 0;
	while (s1[number_loop] != '\0' && s2[number_loop] != '\0'
		&& (s1[number_loop] == s2[number_loop]))
	{
		number_loop++;
	}
	return (s1[number_loop] - s2[number_loop]);
}

int	has_duplicate(t_list *stack, int number)
{
	int	*value;

	while (stack)
	{
		value = (int *)stack->content;
		if (*value == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_valid_number(const char *nptr)
{
	size_t	index;

	index = 0;
	if (nptr[index] == '-' || nptr[index] == '+')
		index++;
	if (nptr[index] == '\0')
		return (1);
	while (nptr[index])
	{
		if (nptr[index] > '9' || nptr[index] < '0')
			return (1);
		index++;
	}
	return (0);
}

int	convert_number(const char *nptr, int *result)
{
	long long	number;
	long long	limit;
	int	signal;
	int	index;

	signal = 1;
	index = 0;
	number = 0;
	if (is_valid_number(nptr))
		return (0);
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signal = -1;
		index++;
	}
	if (signal == 1)
		limit = INT_MAX;
	else
		limit = -(long long)INT_MIN;
	while (nptr[index])
	{
		if (number > (((limit - (nptr[index] - '0')) / 10)))
			return (0);
		number = (number * 10) + (nptr[index] - '0');
		index++;
	}
	number *= signal;
	*result = (int)number;
	return (1);
}

int	read_input(int argc, char **argv, t_data *data)
{
	int	index;
	int	flag_strategy;
	int	flag_benchmark;
	int	number;

	index = 1;
	flag_strategy = 0;
	flag_benchmark = 0;
	number = 0;
	if(argc < 2)
		return (0);
	while (index < argc)
	{
		if (ft_strcmp("--simple", argv[index]) == 0 && flag_strategy == 0)
		{
			data->strategy = SIMPLE;
			flag_strategy = 1;
		}
		else if (ft_strcmp("--medium", argv[index]) == 0 && flag_strategy == 0)
		{
			data->strategy = MEDIUM;
			flag_strategy = 1;
		}
		else if (ft_strcmp("--complex", argv[index]) == 0 && flag_strategy == 0)
		{
			data->strategy = COMPLEX;
			flag_strategy = 1;
		}
		else if (ft_strcmp("--adaptive", argv[index]) == 0 && flag_strategy == 0)
		{
			data->strategy = ADAPTIVE;
			flag_strategy = 1;
		}
		else if (ft_strcmp("--bench", argv[index]) == 0 && flag_benchmark == 0)
		{
			data->bench->disorder = 1;
			flag_benchmark = 1;
		}
		else if (convert_number(argv[index], &number))
		{
			if (has_duplicate(data->a, number) || !add_number(&data->a, number))
			{
				remove_stack(&data->a);
				remove_stack(&data->b);
				return (0);
			}
		}
		else
		{
			remove_stack(&data->a);
			remove_stack(&data->b);
			return (0);
		}
		index++;
	}
	return (1);
}
