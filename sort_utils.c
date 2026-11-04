/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   sort_utils.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 17:04:33 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/04 13:21:29 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multi_do(int (f)(t_data *, char), char stack, int times, t_data *d)
{
	int	i;

	i = 0;
	while (i++ < times)
		f(d, stack);
}

int	is_largest_closer(int largest, int nxt_largest, int size)
{
	if (largest >= size / 2)
		largest = size - largest;
	if (nxt_largest >= size / 2)
		nxt_largest = size - nxt_largest;
	return (largest <= nxt_largest);
}

int	get_largestindx(t_list *node)
{
	int	i;
	int	maxi;
	int	max;

	i = 0;
	maxi = 0;
	max = *((int *) node->content);
	while (node)
	{
		if (*((int *) node->content) > max)
		{
			max = *((int *) node->content);
			maxi = i;
		}
		i++;
		node = node->next;
	}
	return (maxi);
}

int	get_scndlargestindx(t_list *node)
{
	int	i;
	int	maxi;
	int	nxtmax;
	int	nxtmaxi;

	i = 0;
	nxtmaxi = 0;
	maxi = get_largestindx(node);
	nxtmax = *((int *) node->content);
	while (node)
	{
		if (i != maxi && *((int *) node->content) > nxtmax)
		{
			nxtmax = *((int *) node->content);
			nxtmaxi = i;
		}
		i++;
		node = node->next;
	}
	return (nxtmaxi);
}

int	sort_next_largest(t_data *data, int largest, int nxt_largest, int size)
{
	if (nxt_largest < (size + 1) / 2)
		multi_do(rx, 'b', nxt_largest, data);
	else
		multi_do(rrx, 'b', size + 1 - nxt_largest, data);
	px(data, 'a');
	size--;
	largest = get_largestindx(data->b);
	if (largest < (size + 1) / 2)
		multi_do(rx, 'b', largest, data);
	else
		multi_do(rrx, 'b', size + 1 - largest, data);
	px(data, 'a');
	sx(data, 'a');
	return (1);
}
