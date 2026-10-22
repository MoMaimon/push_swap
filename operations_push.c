/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_push.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 13:45:12 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 13:55:03 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_list **stack1, t_list **stack2)
{
	t_list	*second;

	if (!*stack2)
		return (0);
	second = *stack2;
	*stack2 = (*stack2)->next;
	second->next = *stack1;
	*stack1 = second;
	return (1);
}

void	px(t_data *data, char stack)
{
	if (stack == 'a')
	{
		if (!push(&(data->a), &(data->b)))
			return ;
		ft_putstr_fd("pa\n", 1);
		if (data->bench)
			data->bench->pa++;
	}
	else if (stack == 'b')
	{
		if (!push(&(data->b), &(data->a)))
			return ;
		ft_putstr_fd("pb\n", 1);
		if (data->bench)
			data->bench->pb++;
	}
}
