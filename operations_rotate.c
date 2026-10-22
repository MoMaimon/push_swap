/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_rotate.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 13:56:15 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 14:04:12 by mabd-elh        ###   ########.fr        */
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
}

int	rx(t_data *data, char stack)
{
	if (stack == 'a')
	{
		if (!rotate(&(data->a)))
			return (0);
		ft_putstr_fd("ra\n", 1);
		if (data->bench)
			data->bench->ra++;
	}
	else if (stack == 'b')
	{
		if (!rotate(&(data->b)))
			return (0);
		ft_putstr_fd("rb\n", 1);
		if (data->bench)
			data->bench->rb++;
	}
	else
		return (rotate(&(data->b)) + rotate(&(data->a)));
	return (1);
}

void	rr(t_data *data)
{
	if (rx(data, 0))
	{
		ft_putstr_fd("rr\n", 1);
		if (data->bench)
			data->bench->rr++;
	}
}
