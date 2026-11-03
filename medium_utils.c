/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 13:03:52 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/03 15:22:07 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_data *data)
{
	int		smallest;
	t_list	*node;

	node = data->a;
	smallest = *((int *) node->content);
	node = node->next;
	while (node)
	{
		if (*((int *) node->content) < smallest)
			smallest = *((int *) node->content);
		node = node->next;
	}
	return (smallest);
}

int	get_bucket(int buckets, int largest, int num, t_data *data)
{
	long long	shifted_num;
	long long	range;
	int			bucket_no;
	int			smallest;

	smallest = get_smallest(data);
	shifted_num = (long long) num - (long long) smallest;
	range = (long long) largest - (long long) smallest + 1;
	bucket_no = (int)((buckets * shifted_num) / range);
	return (bucket_no);
}

int	get_bindex(t_data *data, int bno, int buckets, int large)
{
	unsigned int	i;
	int				tempi;
	t_list			*node;

	node = data->a;
	if (!node)
		return (-1);
	i = 0;
	while (i < (ft_lstsize(data->a) / 2))
	{
		if (get_bucket(buckets, large, *((int *) node->content), data) == bno)
			return (i);
		i++;
		node = node->next;
	}
	tempi = -1;
	while (node)
	{
		if (get_bucket(buckets, large, *((int *) node->content), data) == bno)
			tempi = i;
		i++;
		node = node->next;
	}
	return (tempi);
}

int	get_largest(t_data *data)
{
	int		largest;
	t_list	*node;

	node = data->a;
	largest = *((int *) node->content);
	node = node->next;
	while (node)
	{
		if (*((int *) node->content) > largest)
			largest = *((int *) node->content);
		node = node->next;
	}
	return (largest);
}

int	ft_sqrt(int n)
{
	int	left;
	int	right;
	int	mid;

	if (n <= 1)
		return (n);
	left = 1;
	right = n / 2;
	while (left + 1 != right && left < right)
	{
		mid = (left + right) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid > n)
			right = mid;
		else
			left = mid;
	}
	if (right * right == n)
		return (right);
	return (left);
}
