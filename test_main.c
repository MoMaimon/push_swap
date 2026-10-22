/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_main.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 15:21:03 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 16:10:16 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// DELETE THIS BEFORE FINISH
// add ur ft_printf into libft
#include <stdio.h>

void	print_stacks(t_list *a, t_list *b)
{
	// Traverse until both stacks reach the end
	while (a != NULL || b != NULL)
	{
		// Print stack A element if it exists
		if (a != NULL && ft_lstsize(a) >= ft_lstsize(b))
		{
			printf("%d", *((int *) a->content));
			a = a->next;
		}
		// Spacing between columns
		printf("\t");
		// Print stack B element if it exists
		if (b != NULL && ft_lstsize(b) > ft_lstsize(a))
		{
			printf("%d", *((int *) b->content));
			b = b->next;
		}
		printf("\n");
	}
	// Print the footer exactly as shown in the image
	printf("_\t_\n");
	printf("a\tb\n");
}

int	main(void)
{
	t_data	*data;

	// t_list	*b;
	int	i;
	int	*num;

	int	numbers[5] =
	{
		4, 67, 3, 87, 23
	};
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->a = NULL;
	data->bench = malloc(sizeof(t_bench));
	data->bench->pa = 0;
	data->bench->pb = 0;
	data->bench->sa = 0;
	data->bench->sb = 0;
	data->bench->ss = 0;
	data->bench->ra = 0;
	data->bench->rb = 0;
	data->bench->rr = 0;
	data->bench->rra = 0;
	data->bench->rrb = 0;
	data->bench->rrr = 0;
	// b = NULL;
	i = 0;
	while (i < 5)
	{
		num = ft_calloc(1, sizeof(int));
		*num = numbers[i];
		ft_lstadd_back(&(data->a), ft_lstnew(num));
		i++;
	}
	get_disorder(data);
	printf("[bench] disorder: %f\n", data->bench->disorder);
	print_stacks(data->a, data->b);
	printf("---------------------------\n");
	print_stacks(data->a, data->b);
}
