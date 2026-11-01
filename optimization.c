/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:59:44 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/01 19:26:40 by mabd-elh         ###   ########.fr       */
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

int	check_redundant(void *first, void *second, t_list *ops, t_data *data)
{
	t_list	*after;
	int		sum;

	after = ops->next->next->next;
	sum = *((int *) first) + *((int *) second);
	if (sum == 0 || sum == 20 || sum == 200)
	{
		ft_lstdelone(ops->next->next, free);
		ft_lstdelone(ops->next, free);
		ops->next = after;
		return (1);
	}
	if (sum == 110 || sum == 11000 || sum == -11000)
	{
		ft_lstdelone(ops->next->next, free);
		ft_lstdelone(ops->next, free);
		ops->next = NULL;
		if (!add_number(&ops, sum))
			error(data);
		ops->next->next = after;
		return (1);
	}
	return (0);
}

int	opt_clean(t_list *ops, t_data *data)
{
	t_list	*prev;
	int		i;

	prev = ops;
	ops = ops->next;
	i = check_redundant(prev, ops, prev, data);
	ops = ops->next;
	while (ops)
	{
		i += check_redundant(prev->next->content, ops->content, prev, data);
		ops = ops->next;
		prev = prev->next;
	}
	return (i);
}

void	optimize(t_data *data)
{
	t_list	*ops;

	ops = data->ops;
	if (!ops || ft_lstsize(ops) < 2)
		return ;
	if (ft_lstsize(ops) == 2)
	{
		check_redundant(ops->content, ops->next->content, ops, data);
		return ;
	}
	while (opt_clean(ops, data))
	{
	}
}
