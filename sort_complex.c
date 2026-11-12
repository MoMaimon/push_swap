/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:34:15 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/12 16:00:47 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_data *data, int lo, int size)
{
	int	pivot;
	int	pushed;
	int	rots;
	int	target;
	int	whole;

	if (check_size_b(data, size))
		return ;
	pivot = lo + size / 2;
	target = size - size / 2;
	whole = size == (int)ft_lstsize(data->b);
	pushed = 0;
	rots = 0;
	while (pushed < target)
		shift_b(data, &pivot, &pushed, &rots);
	if (!whole)
		rotate_b(data, rots);
	sort_a(data, pivot, pushed);
	sort_b(data, lo, size - pushed);
}

void	sort_a(t_data *data, int lo, int size)
{
	int	pivot;
	int	pushed;
	int	rots;
	int	target;
	int	whole;

	if (check_size_a(data, size))
		return ;
	pivot = lo + size / 2;
	target = size / 2;
	whole = size == (int)ft_lstsize(data->a);
	pushed = 0;
	rots = 0;
	while (pushed < target)
		shift_a(data, &pivot, &pushed, &rots);
	if (!whole)
		rotate_a(data, rots);
	sort_a(data, pivot, size - pushed);
	sort_b(data, lo, pushed);
}

void	complex_sort(t_data *data)
{
	sort_a(data, 0, ft_lstsize(data->a));
}
