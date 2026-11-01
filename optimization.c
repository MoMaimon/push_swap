/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   optimization.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/01 13:59:44 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/01 14:42:48 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra <-> rra
// rb <-> rrb
// rr <-> rrr
// ra + rb = rr
// rra + rrb = rrr
// pa <-> pb
// sa <-> sa
// sb <-> sb
// sa + sb = ss

void	optimize(t_data *data)
{
	t_list	*ops;

	ops = data->ops;
	if (!ops || !ops->content)
		return ;
	while (opt_clean(ops))
	{
	}
}

int	is_redundant(char *first, char *second)
{
}

int	opt_clean(t_list *ops)
{
	char	*prev;
	int		i;

	prev = (char *) ops->content;
	ops = ops->next;
	i = 0;
	while (ops)
	{
	}
}
