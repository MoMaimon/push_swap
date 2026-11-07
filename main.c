/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:10:47 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/07 14:01:48 by mabd-elh         ###   ########.fr       */
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

	//t_list	*lst;
	init_data(&data);
	if (argc == 1)
		return (0);
	if (!read_input(argc, argv, &data))
		error(&data);
	get_disorder(&data);
	if (data.bench)
		init_bench(&data);
	medium_sort(&data);
	optimize(&data);
	print_ops(&data, data.ops);
	print_bench(&data);
	{
		write(2, "Error\n", 6);
		return (1);
	}
	get_disorder(&data);
	if (data.strategy == ADAPTIVE)
	{
		if (data.bench->disorder < 0.2)
			data.strategy = SIMPLE;
		else if (data.bench->disorder >= 0.2 && data.bench->disorder < 0.5)
			data.strategy = MEDIUM;
		else
			data.strategy = COMPLEX;
	}
	if (data.strategy == SIMPLE)
	{
		simple_sort(&data);
	}
	else if (data.strategy == MEDIUM)
	{
		return (1);
	}
	else if (data.strategy == COMPLEX)
	{
		complex_sort(&data);
	}
	if (data.bench)
	{
		print_bench(&data);
	}
	/*lst = data.a;
	printf("\nA: ");
	while (lst)
	{
	printf("%d ||| %d \n",*(int *)lst->content, lst->index);
	lst = lst->next;
	}*/
	/*printf("\nB: ");
	lst = data.b;
	while (lst)
	{
	printf("%d ",*(int *)lst->content);
	lst = lst->next;
	}*/
	remove_stack(&data.a);
	remove_stack(&data.b);
	if (data.bench)
		free(data.bench);
	return (0);
}
