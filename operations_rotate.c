/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_rotate.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 13:56:15 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/01 13:57:58 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*last;

	if (!*stack || ft_lstsize(*stack) < 2)
		return (0);
	last = ft_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	return (1);
}

int	rx(t_data *data, char stack)
{
	if (stack == 'a')
	{
		if (!rotate(&(data->a)))
			return (0);
		add_to_ops(data, "ra");
	}
	else if (stack == 'b')
	{
		if (!rotate(&(data->b)))
			return (0);
		add_to_ops(data, "rb");
	}
	else
		return (rotate(&(data->b)) + rotate(&(data->a)));
	return (1);
}

void	rr(t_data *data)
{
	if (rx(data, 0))
		add_to_ops(data, "rr");
}
