/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:57:08 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/31 17:08:47 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_index(t_data *data)
{
	int		count;
	t_list	*stack;
	t_list	*lst;

	count = 0;
	stack = data->a;
	while (stack != NULL)
	{
		lst = data->a;
		count = 0;
		while (lst != NULL)
		{
			if (*(int *)lst->content < *(int *)stack->content)
				count++;
			lst = lst->next;
		}
		stack->index = count;
		stack = stack->next;
	}
}
