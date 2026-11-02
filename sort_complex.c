/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:34:15 by yaabed            #+#    #+#             */
/*   Updated: 2026/11/02 14:18:15 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_b(t_data *data, int lo, int size)
{
	int		pivot;
	int		pushed;
	int		rots;
	int		count;

	if (check_size_b(data, size))
		return ;
	pivot = lo + size / 2;
	pushed = 0;
	rots = 0;
	count = 0;
	while (count < size)
	{
		shift_b(data, &pivot, &pushed, &rots);
		count++;
	}
	while (rots > 0)
	{
		rrx(data, 'b');
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

	if (check_size_a(data, size))
		return ;
	pivot = lo + size / 2;
	pushed = 0;
	rots = 0;
	count = 0;
	while (count < size)
	{
		shift_a(data, &pivot, &pushed, &rots);
		count++;
	}
	while (rots > 0)
	{
		rrx(data, 'a');
		rots--;
	}
	sort_a(data, pivot, size - pushed);
	sort_b(data, lo, pushed);
}

void	complex_sort(t_data *data)
{
	sort_a(data, 0, ft_lstsize(data->a));
}
