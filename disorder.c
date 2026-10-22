/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   disorder.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 15:30:55 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 15:53:00 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_disorder(t_data *data)
{
	int		mistakes;
	int		pairs;
	t_list	*a;
	t_list	*b;

	a = data->a;
	mistakes = 0;
	pairs = 0;
	while (a)
	{
		b = a->next;
		while (b)
		{
			pairs++;
			if (*((int *) a->content) > *((int *) b->content))
				mistakes++;
			b = b->next;
		}
		a = a->next;
	}
	data->bench->disorder = (float) mistakes / pairs;
}
