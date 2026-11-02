/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   optimization.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/01 13:59:44 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/02 20:41:50 by mabd-elh        ###   ########.fr        */
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

int	check_redundant(void *first, void *second, t_list **temp, t_data *data)
{
	int	sum;

	sum = *((int *) first) + *((int *) second);
	if (sum == 0 || sum == 20 || sum == 200)
		return (1);
	if (sum == 110 || sum == 11000 || sum == -11000)
	{
		if (!add_number(temp, sum))
			error(data);
		return (1);
	}
	return (0);
}

int	opt_clean(t_list *ops, t_data *data)
{
	t_list	*temp;
	int		i;

	ops = ops;
	i = 0;
	temp = NULL;
	while (ops && ops->next)
	{
		if (check_redundant(ops->content, ops->next->content, &temp, data))
		{
			i++;
			ops = ops->next;
		}
		else
		{
			if (!add_number(&temp, *(int *) ops->content))
				error(data);
		}
		ops = ops->next;
	}
	if (ops && !add_number(&temp, *(int *) ops->content))
		error(data);
	ft_lstclear(&data->ops, free);
	data->ops = temp;
	return (i);
}

void	optimize(t_data *data)
{
	t_list	*ops;

	ops = data->ops;
	if (!ops || ft_lstsize(ops) < 2)
		return ;
	while (opt_clean(ops, data))
	{
		ops = data->ops;
	}
}
