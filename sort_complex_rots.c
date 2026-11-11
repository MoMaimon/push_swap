/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_rots.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 17:25:08 by yaabed            #+#    #+#             */
/*   Updated: 2026/11/11 17:27:52 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data, int rots)
{
	while (rots > 0)
	{
		rrx(data, 'a');
		rots--;
	}
}

void	rotate_rr_a(t_data *data, int rots)
{
	while (rots > 0)
	{
		rx(data, 'a');
		rots--;
	}
}

void	rotate_b(t_data *data, int rots)
{
	while (rots > 0)
	{
		rrx(data, 'b');
		rots--;
	}
}

void	rotate_rr_b(t_data *data, int rots)
{
	while (rots > 0)
	{
		rx(data, 'b');
		rots--;
	}
}
