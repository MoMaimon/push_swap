/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_swap.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 12:50:07 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 13:08:10 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*second;

	if (!(*stack)->next)
		return (0);
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack);
	*stack = second;
	return (1);
}

int	sx(t_data data, char stack)
{
	int	flag;

	if (stack == 'a')
	{
		if (swap(&data.a))
			ft_putstr_fd("sa\n", 1);
	}
	else if (stack == 'b')
	{
		if (swap(&data.b))
			ft_putstr_fd("sb\n", 1);
	}
	else
	{
		flag = 0;
		flag += swap(&data.a);
		flag += swap(&data.b);
		if (flag > 0)
			ft_putstr_fd("ss\n", 1);
	}
}
