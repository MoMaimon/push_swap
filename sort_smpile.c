/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smpile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 10:14:55 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/07 14:26:08 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <limits.h>
// #include <stdio.h>

int	max_stack(t_data data)
{
	int	max_value;

	max_value = INT_MIN;
	while (data.b != NULL)
	{
		if (max_value < *(int *) data.b->content)
			max_value = *(int *) data.b->content;
		data.b = data.b->next;
	}
	return (max_value);
}

void	rotat_stack(t_data *data)
{
	while (*(int *) data->b->content != max_stack(*data))
		rrx(data, 'b');
}

static int	find_insert_position(t_list *stack, int value, int *flag)
{
	int	count_rb;
	int	count_rrb;
	int	size;
	int	position;

	size = ft_lstsize(stack);
	if (size == 0)
	{
		*flag = 0;
		return (0);
	}
	position = find_target_position(stack, value);
	count_rb = position;
	count_rrb = (size - position) % size;
	if (count_rrb >= count_rb)
	{
		*flag = 0;
		return (count_rb);
	}
	else
	{
		*flag = 1;
		return (count_rrb);
	}
}

void	simple_sort(t_data *data)
{
	int	index;
	int	value;
	int	flag;

	while (data->a != NULL)
	{
		value = *(int *) data->a->content;
		index = find_insert_position(data->b, value, &flag);
		while (index > 0)
		{
			if (flag == 0)
				rx(data, 'b');
			else if (flag == 1)
				rrx(data, 'b');
			index--;
		}
		px(data, 'b');
	}
	rotat_stack(data);
	while (data->b != NULL)
		px(data, 'a');
}
