/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smpile_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:53:44 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/28 20:55:24 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_best_position(t_list *stack, int value)
{
	t_list	*current;
	int		position;
	int		best_position;
	int		best_value;

	current = stack;
	position = 0;
	best_position = -1;
	best_value = 0;
	while (current != NULL)
	{
		if (*(int *)current->content < value
			&& (best_position == -1
				|| *(int *)current->content > best_value))
		{
			best_value = *(int *)current->content;
			best_position = position;
		}
		position++;
		current = current->next;
	}
	return (best_position);
}

int	find_target_position(t_list *stack, int value)
{
	t_list	*current;
	int		position;
	int		max_position;
	int		max_value;
	int		best_position;

	current = stack;
	position = 0;
	max_position = 0;
	max_value = *(int *)stack->content;
	while (current != NULL)
	{
		if (*(int *)current->content > max_value)
		{
			max_value = *(int *)current->content;
			max_position = position;
		}
		position++;
		current = current->next;
	}
	best_position = find_best_position(stack, value);
	if (best_position == -1)
		return (max_position);
	return (best_position);
}
