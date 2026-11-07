/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:06:08 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/07 14:06:13 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*lst_getbeforelast(t_list *lst)
{
	t_list	*prev;

	while (lst->next)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}

static int	rotate(t_list **stack)
{
	t_list	*before_last;

	if (!*stack || ft_lstsize(*stack) < 2)
		return (0);
	before_last = lst_getbeforelast(*stack);
	before_last->next->next = *stack;
	*stack = before_last->next;
	before_last->next = NULL;
	return (1);
}

int	rrx(t_data *data, char stack)
{
	if (stack == 'a')
	{
		if (!rotate(&(data->a)))
			return (0);
		add_to_ops(data, -1000);
	}
	else if (stack == 'b')
	{
		if (!rotate(&(data->b)))
			return (0);
		add_to_ops(data, -10000);
	}
	else
		return (rotate(&(data->b)) + rotate(&(data->a)));
	return (1);
}

void	rrr(t_data *data)
{
	if (rrx(data, 0))
		add_to_ops(data, -11000);
}
