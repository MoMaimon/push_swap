/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 18:10:47 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/31 17:03:38 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*lst;

	data.a = NULL;
	data.b = NULL;
	data.strategy = ADAPTIVE;
	data.bench = NULL;
	if (argc == 1)
		return (0);
	if (!read_input(argc, argv, &data))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	complex_sort(&data);
	lst = data.a;
	printf("\nA: ");
	while (lst)
	{
		printf("%d ||| %d \n",*(int *)lst->content, lst->index);
		lst = lst->next;
	}
	/*printf("\nB: ");
	lst = data.b;
	while (lst)
	{
		printf("%d ",*(int *)lst->content);
		lst = lst->next;
	}*/
	remove_stack(&data.a);
	remove_stack(&data.b);
	return (0);
}
