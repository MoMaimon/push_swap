/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operations_reverse_rotate.c                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 14:06:08 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 14:21:45 by mabd-elh        ###   ########.fr        */
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
	before_last->next = NULL;
}

int	rrx(t_data *data, char stack)
{
	if (stack == 'a')
	{
		if (!rotate(&(data->a)))
			return (0);
		ft_putstr_fd("rra\n", 1);
		if (data->bench)
			data->bench->rra++;
	}
	else if (stack == 'b')
	{
		if (!rotate(&(data->b)))
			return (0);
		ft_putstr_fd("rrb\n", 1);
		if (data->bench)
			data->bench->rrb++;
	}
	else
		return (rotate(&(data->b)) + rotate(&(data->a)));
	return (1);
}

void	rrr(t_data *data)
{
	if (rrx(data, 0))
	{
		ft_putstr_fd("rrr\n", 1);
		if (data->bench)
			data->bench->rrr++;
	}
}
