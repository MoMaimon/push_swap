/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:52:32 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/01 20:12:56 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_ops(t_data *data, int op)
{
	int		*number;
	t_list	*new;

	number = malloc(sizeof(int));
	if (!number)
		error(data);
	*number = op;
	new = ft_lstnew(number);
	if (!new)
		error(data);
	ft_lstadd_back(&(data->ops), new);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-1 * n);
	return (n);
}

void	do_op(char *str, int *counter)
{
	ft_putstr_fd(str, 1);
	(*counter)++;
}

void	print_ops(t_data *data, t_list *ops)
{
	while (ops)
	{
		if (*((int *) ops->content) == 1)
			do_op("pa\n", &data->bench->pa);
		else if (*((int *) ops->content) == -1)
			do_op("pb\n", &data->bench->pb);
		else if (*((int *) ops->content) == 10)
			do_op("sa\n", &data->bench->sb);
		else if (*((int *) ops->content) == 100)
			do_op("sb\n", &data->bench->sb);
		else if (*((int *) ops->content) == 110)
			do_op("ss\n", &data->bench->ss);
		else if (*((int *) ops->content) == 1000)
			do_op("ra\n", &data->bench->ra);
		else if (*((int *) ops->content) == 10000)
			do_op("rb\n", &data->bench->rb);
		else if (*((int *) ops->content) == 11000)
			do_op("rr\n", &data->bench->rr);
		else if (*((int *) ops->content) == -1000)
			do_op("rra\n", &data->bench->rra);
		else if (*((int *) ops->content) == -10000)
			do_op("rrb\n", &data->bench->rrb);
		else if (*((int *) ops->content) == -11000)
			do_op("rrr\n", &data->bench->rrr);
		ops = ops->next;
	}
}
