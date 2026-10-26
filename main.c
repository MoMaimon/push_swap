/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:10:47 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/26 19:31:02 by mabd-elh         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_data	data;

	data.a = NULL;
	data.b = NULL;
	data.strategy = ADAPTIVE;
	data.bench = NULL;
	if (argc == 1)
		return (0);
	if (!read_input(argc, argv, &data))
		error(&data);
	get_disorder(&data);
	if (data.bench)
		init_bench(&data);
	print_stacks(data.a, data.b);
	print_bench(&data);
	remove_stack(&data.a);
	remove_stack(&data.b);
	if (data.bench)
		free(data.bench);
	return (0);
}
