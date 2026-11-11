/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_shift.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:11:06 by yaabed            #+#    #+#             */
/*   Updated: 2026/11/11 17:14:43 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	shift_rr_a(t_data *data, int *pivot, int *pushed, int *rots)
{
	if (data->a->index < *pivot)
	{
		px(data, 'b');
		*pushed = *pushed + 1;
	}
	else if (data->a->index >= *pivot)
	{
		rrx(data, 'a');
		*rots = *rots + 1;
	}
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

void	shift_rr_b(t_data *data, int *pivot, int *pushed, int *rots)
{
	if (data->b->index >= *pivot)
	{
		px(data, 'a');
		*pushed = *pushed + 1;
	}
	else if (data->b->index < *pivot)
	{
		rrx(data, 'b');
		*rots = *rots + 1;
	}
}
