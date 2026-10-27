/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   medium.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/27 12:58:25 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/27 21:03:57 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multi_do(int(f)(t_data *, char), char stack, int times, t_data *d)
{
	int	i;

	i = 0;
	while (i++ < times)
		f(d, stack);
}

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

void	put_in_place(t_data *data, int n)
{
	unsigned int	i;
	int				number;
	int				maxi[2];
	t_list			*node;

	i = 0;
	node = data->b;
	if (!node)
	{
		px(data, 'b');
		return ;
	}
	number = *((int *)(node->content));
	maxi[0] = number;
	maxi[1] = 0;
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
	if (!node)
		multi_do(rx, 'b', maxi[1], data);
	else if (i == 0 || (unsigned int) i < ft_lstsize(data->b) / 2)
		multi_do(rx, 'b', i, data);
	else
		multi_do(rrx, 'b', ft_lstsize(data->b) - i, data);
	px(data, 'b');
	order_stack(data);
}

void	push_all(t_data *data, int size)
{
	int	i;

	i = get_largestindx(data->b);
	if (i == 0 || (unsigned int) i < ft_lstsize(data->b) / 2)
		multi_do(rx, 'b', i, data);
	else
		multi_do(rrx, 'b', ft_lstsize(data->b) - i, data);
	multi_do(px, 'a', size, data);
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
	buckets = ft_sqrt(size);
	i = buckets - 1;
	while (i >= 0)
	{
		numi = get_bindex(data, i, buckets, largest);
		while (numi != -1)
		{
			if ((unsigned int) numi < size / 2)
				multi_do(rx, 'a', numi, data);
			else
				multi_do(rrx, 'a', ft_lstsize(data->a) - numi, data);
			put_in_place(data, *((int *)(data->a->content)));
			numi = get_bindex(data, i, buckets, largest);
		}
		i -= order_stack(data);
	}
	push_all(data, size);
}
