/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_swap.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 12:50:07 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/01 13:58:36 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*second;

	if (!(*stack) || !(*stack)->next)
		return (0);
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = (*stack);
	*stack = second;
	return (1);
}

int	sx(t_data *data, char stack)
{
	if (stack == 'a')
	{
		if (!swap(&(data->a)))
			return (0);
		add_to_ops(data, "sa");
	}
	else if (stack == 'b')
	{
		if (!swap(&(data->b)))
			return (0);
		add_to_ops(data, "sb");
	}
	else
		return (swap(&(data->b)) + swap(&(data->a)));
	return (1);
}

void	ss(t_data *data)
{
	if (sx(data, 0))
		add_to_ops(data, "ss");
}
