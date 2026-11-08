/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:10:47 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/08 18:44:30 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_list *a, t_list *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL && ft_lstsize(a) >= ft_lstsize(b))
		{
			printf("%d", *((int *) a->content));
			a = a->next;
		}
		printf("\t");
		if (b != NULL && ft_lstsize(b) > ft_lstsize(a))
		{
			printf("%d", *((int *) b->content));
			b = b->next;
		}
		printf("\n");
	}
	printf("_\t_\n");
	printf("a\tb\n");
	printf("---------------------------\n");
}

void	choose_strat(t_data *data, t_strategy strat)
{
	if (strat == SIMPLE)
		simple_sort(data);
	else if (strat == MEDIUM)
		medium_sort(data);
	else if (strat == COMPLEX)
		complex_sort(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	init_data(&data);
	if (!read_input(argc, argv, &data))
		error(&data);
	get_disorder(&data);
	if (data.bench->enabled)
		init_bench(&data);
	get_disorder(&data);
	if (data.strategy == ADAPTIVE)
		choose_strat(&data, data.bench->strategy);
	else
		choose_strat(&data, data.strategy);
	optimize(&data);
	print_ops(&data, data.ops);
	if (data.bench->enabled)
		print_bench(&data);
	remove_stack(&(data.a));
	remove_stack(&(data.b));
	remove_stack(&(data.ops));
	free(data.bench);
	return (0);
}
