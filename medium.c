/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 12:58:25 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/07 15:07:21 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_stack(t_data *data)
{
	int	i;

	i = get_largestindx(data->b);
	if (i == 0 || (unsigned int) i < ft_lstsize(data->b) / 2)
		multi_do(rx, 'b', i, data);
	else
		multi_do(rrx, 'b', ft_lstsize(data->b) - i, data);
	return (1);
}

int	get_place(int number, t_list *node, int n)
{
	int				maxi[2];
	unsigned int	i;

	maxi[0] = number;
	maxi[1] = 0;
	i = 0;
	while (n < number && node)
	{
		if (number > maxi[0])
		{
			maxi[0] = number;
			maxi[1] = i;
		}
		i++;
		node = node->next;
		if (!node)
			break ;
		number = *((int *)(node->content));
	}
	return (i);
}

void	push_all(t_data *data, int size)
{
	int	i;
	int	nxt_largest;

	while (size--)
	{
		i = get_largestindx(data->b);
		nxt_largest = get_scndlargestindx(data->b);
		if (!is_largest_closer(i, nxt_largest, size + 1) && size > 1)
			size -= sort_next_largest(data, i, nxt_largest, size);
		else
		{
			if (i < (size + 1) / 2)
				multi_do(rx, 'b', i, data);
			else
				multi_do(rrx, 'b', size + 1 - i, data);
			px(data, 'a');
		}
	}
}

void	medium_sort(t_data *data)
{
	unsigned int	size;
	int				largest;
	int				buckets;
	int				i;
	int				numi;

	size = ft_lstsize(data->a);
	largest = get_largest(data);
	buckets = max(1, ft_sqrt(size) / 2);
	i = buckets - 1;
	while (i >= 0)
	{
		numi = get_bindex(data, i, buckets, largest);
		while (numi != -1)
		{
			if ((unsigned int) numi < ft_lstsize(data->a) / 2)
				multi_do(rx, 'a', numi, data);
			else
				multi_do(rrx, 'a', ft_lstsize(data->a) - numi, data);
			px(data, 'b');
			numi = get_bindex(data, i, buckets, largest);
		}
		i -= 1;
	}
	push_all(data, size);
}
