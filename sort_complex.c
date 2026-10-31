/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:34:15 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/31 17:58:18 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	check_order(t_list *stack)
{
	t_list	*lst;

	lst = stack->next;
	if (*(int *)stack->content > *(int *)lst->content)
		return (1);
	return (0);
}

void	sort_b(t_data *data, int lo, int size)
{
	int		pivot;
	int		pushed;
	int		rots;
	int		count;

	if (size <= 0)
		return ;
	if (size == 1)
	{
		px(data, 'a');
		return ;
	}
	if (size == 2)
	{
		if (!check_order(data->b))
			sx(data,'b');
		px(data, 'a');
		px(data, 'a');
		return ;
	}
	pivot = lo + size / 2;
	pushed = 0;
	rots = 0;
	count = 0;
	while (count < size)
	{
		if (data->b->index >= pivot)
		{
			px(data, 'a');
			pushed++;
		}
		else if (data->b->index < pivot)
		{
			rx(data,'b');
			rots++;
		}
		count++;
	}
	while (rots > 0)
	{
		rrx(data,'b');
		rots--;
	}
	sort_a(data, pivot, pushed);
	sort_b(data, lo, size - pushed);
}

void	sort_a(t_data *data, int lo, int size)
{
	int		pivot;
	int		pushed;
	int		rots;
	int		count;

	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (check_order(data->a))
			sx(data,'a');
		return ;
	}
	pivot = lo + size / 2;
	pushed = 0;
	rots = 0;
	count = 0;
	while (count < size)
	{
		if (data->a->index < pivot)
		{
			px(data, 'b');
			pushed++;
		}
		else if (data->a->index  >= pivot)
		{
			rx(data,'a');
			rots++;
		}
		count++;
	}
	while (rots > 0)
	{
		rrx(data,'a');
		rots--;
	}
	sort_a(data, pivot, size - pushed);
	sort_b(data, lo, pushed);
}

void	complex_sort(t_data *data)
{
	sort_a(data, 0, ft_lstsize(data->a));
}
