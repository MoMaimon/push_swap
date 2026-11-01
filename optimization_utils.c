/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   optimization_utils.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/01 13:52:32 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/01 13:55:23 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_ops(t_data *data, char *op)
{
	char	*str;
	t_list	*new;

	str = ft_strdup(op);
	if (!str)
		error(data);
	new = ft_lstnew(str);
	if (!new)
		error(data);
	ft_lstadd_back(&(data->ops), new);
}
