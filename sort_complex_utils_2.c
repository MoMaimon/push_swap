/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:19:06 by yaabed            #+#    #+#             */
/*   Updated: 2026/11/11 17:40:07 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdlib.h>
#include <limits.h>

static void select_free_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

static t_list	*copy_stack(t_list *src)
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;

	head = NULL;
	tail = NULL;
	while (src)
	{
		node = malloc(sizeof(t_list));
		if (!node)
		{
			select_free_stack(head);
			return (NULL);
		}
		node->index = src->index;
		node->content = src->content;
		node->next = NULL;
		if (!head)
			head = node;
		else
			tail->next = node;
		tail = node;
		src = src->next;
	}
	return (head);
}

int	count_rotsrr_a(t_data *data, int pivot, int size, int *pushed)
{
	int	rots;
	int	count;

	rots = 0;
	count = 0;
	while (count < size && data->a)
	{
		if (data->a->index < pivot)
		{
			px(data, 'b');
			(*pushed)++;
		}
		else
		{
			rrx(data, 'a');
			rots++;
		}
		count++;
	}
	return (rots);
}

int	count_rotsr_a(t_data *data, int pivot, int size, int *pushed)
{
	int	rots;
	int	count;

	rots = 0;
	count = 0;
	while (count < size && data->a)
	{
		if (data->a->index < pivot)
		{
			px(data, 'b');
			(*pushed)++;
		}
		else
		{
			rx(data, 'a');
			rots++;
		}
		count++;
	}
	return (rots);
}

int	count_rotsrr_b(t_data *data, int pivot, int size, int *pushed)
{
	int	rots;
	int	count;

	rots = 0;
	count = 0;
	while (count < size && data->b)
	{
		if (data->b->index >= pivot)
		{
			px(data, 'a');
			(*pushed)++;
		}
		else
		{
			rrx(data, 'b');
			rots++;
		}
		count++;
	}
	return (rots);
}

int	count_rotsr_b(t_data *data, int pivot, int size, int *pushed)
{
	int	rots;
	int	count;

	rots = 0;
	count = 0;
	while (count < size && data->b)
	{
		if (data->b->index >= pivot)
		{
			px(data, 'a');
			(*pushed)++;
		}
		else
		{
			rx(data, 'b');
			rots++;
		}
		count++;
	}
	return (rots);
}

static int	select_min(t_data *data, int pivot, int size, char stack)
{
	t_data	select;
	int		pushed;
	int		rots;

	select = *data;
	select.a = copy_stack(data->a);
	if (data->a && !select.a)
		return (INT_MAX);
	select.b = copy_stack(data->b);
	if (data->b && !select.b)
	{
		select_free_stack(select.a);
		return (INT_MAX);
	}
	pushed = 0;
	if (stack == 'a')
		rots = count_rotsr_a(&select, pivot, size, &pushed);
	else
		rots = count_rotsr_b(&select, pivot, size, &pushed);
	select_free_stack(select.a);
	select_free_stack(select.b);
	return (pushed + (rots * 2));
}

static int	select_min_reverse(t_data *data, int pivot,
		int size, char stack)
{
	t_data	select;
	int		pushed;
	int		rots;

	select = *data;
	select.a = copy_stack(data->a);
	if (data->a && !select.a)
		return (INT_MAX);
	select.b = copy_stack(data->b);
	if (data->b && !select.b)
	{
		select_free_stack(select.a);
		return (INT_MAX);
	}
	pushed = 0;
	if (stack == 'a')
		rots = count_rotsrr_a(&select, pivot, size, &pushed);
	else
		rots = count_rotsrr_b(&select, pivot, size, &pushed);
	select_free_stack(select.a);
	select_free_stack(select.b);
	return (pushed + (rots * 2));
}

char	calculat_min_ops(t_data *data, int pivot, int size, char stack)
{
	int	count_r;
	int	count_rr;

	count_r = select_min(data, pivot, size, stack);
	count_rr = select_min_reverse(data, pivot, size, stack);
	if (count_r <= count_rr)
		return ('r');
	return ('v');
}
