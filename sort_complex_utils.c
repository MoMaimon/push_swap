/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:47:58 by yaabed            #+#    #+#             */
/*   Updated: 2026/11/02 14:22:08 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stack)
{
	t_list	*lst;

	lst = stack->next;
	if (*(int *)stack->content > *(int *)lst->content)
		return (1);
	return (0);
}

int	check_size_a(t_data *data, int size)
{
	if (size <= 1)
		return (1);
	if (size == 2)
	{
		if (check_order(data->a))
			sx(data, 'a');
		return (1);
	}
	return (0);
}

void	shift_a(t_data *data, int *pivot, int *pushed, int *rots)
{
	if (data->a->index < *pivot)
	{
		px(data, 'b');
		*pushed = *pushed + 1;
	}
	else if (data->a->index >= *pivot)
	{
		rx(data, 'a');
		*rots = *rots + 1;
	}
}

int	check_size_b(t_data *data, int size)
{
	if (size <= 0)
		return (1);
	if (size == 1)
	{
		px(data, 'a');
		return (1);
	}
	if (size == 2)
	{
		if (!check_order(data->b))
			sx(data, 'b');
		px(data, 'a');
		px(data, 'a');
		return (1);
	}
	return (0);
}

void	shift_b(t_data *data, int *pivot, int *pushed, int *rots)
{
	if (data->b->index >= *pivot)
	{
		px(data, 'a');
		*pushed = *pushed + 1;
	}
	else if (data->b->index < *pivot)
	{
		rx(data, 'b');
		*rots = *rots + 1;
	}
}
