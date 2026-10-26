/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 19:30:30 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/26 19:33:50 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_data *data)
{
	data->bench->pa = 0;
	data->bench->pb = 0;
	data->bench->sa = 0;
	data->bench->sb = 0;
	data->bench->ss = 0;
	data->bench->ra = 0;
	data->bench->rb = 0;
	data->bench->rr = 0;
	data->bench->rra = 0;
	data->bench->rrb = 0;
	data->bench->rrr = 0;
	data->bench->strategy = data->strategy;
	if (data->strategy == ADAPTIVE)
	{
		if (data->disorder < 0.2)
			data->bench->strategy = SIMPLE;
		else if (data->disorder < 0.5)
			data->bench->strategy = MEDIUM;
		else
			data->bench->strategy = COMPLEX;
	}
}
