/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:04:33 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/03 15:28:50 by mabd-elh         ###   ########.fr       */
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
	int	second;
	int	max;

	i = 0;
	maxi = 0;
	second = 0;
	max = *((int *) node->content);
	while (node)
	{
		if (*((int *) node->content) > max)
		{
			max = *((int *) node->content);
			second = maxi;
			maxi = i;
		}
		i++;
		node = node->next;
	}
	return (second);
}
