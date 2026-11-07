/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 10:15:02 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/07 14:06:44 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		value = (int *) stack->content;
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

int	is_negativ(const char nptr)
{
	if (nptr == '-' || nptr == '+')
	{
		if (nptr == '-')
			return (-1);
	}
	return (1);
}

int	convert_number(const char *nptr, int *result)
{
	int	number;

	number = 0;
	if (is_valid_number(nptr))
		return (0);
	number = ft_atoi(nptr);
	*result = (int) number;
	return (1);
}
