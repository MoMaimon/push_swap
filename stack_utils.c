/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:22:32 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/07 14:15:25 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	add_number(t_list **stack, int number)
{
	t_list	*node;
	int		*value;

	if (!stack)
		return (0);
	value = malloc(sizeof(int));
	if (!value)
		return (0);
	*value = number;
	node = ft_lstnew(value);
	if (!node)
	{
		free(value);
		return (0);
	}
	ft_lstadd_back(stack, node);
	return (1);
}

void	remove_stack(t_list **stack)
{
	if (!stack)
		return ;
	ft_lstclear(stack, free);
}

int	max(int first, int second)
{
	if (first > second)
		return (first);
	return (second);
}

void	error(t_data *data)
{
	if (data)
	{
		remove_stack(&(data->a));
		remove_stack(&(data->b));
		remove_stack(&(data->ops));
		free(data->bench);
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->strategy = ADAPTIVE;
	data->ops = NULL;
	data->bench = malloc(sizeof(t_bench));
	data->bench->enabled = 0;
	if (!data->bench)
		error(data);
}
