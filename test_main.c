/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_main.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 15:21:03 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 15:21:03 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// DELETE THIS BEFORE FINISH
// add ur ft_printf into libft
#include <stdio.h>

void	f(void *content)
{
	printf("%s\n", (char *) content);
}

void	print_stacks(t_list *a, t_list *b)
{
	// Traverse until both stacks reach the end
	while (a != NULL || b != NULL)
	{
		// Print stack A element if it exists
		if (a != NULL && ft_lstsize(a) >= ft_lstsize(b))
		{
			printf("%s", (char *) a->content);
			a = a->next;
		}
		// Spacing between columns
		printf("\t");
		// Print stack B element if it exists
		if (b != NULL && ft_lstsize(b) > ft_lstsize(a))
		{
			printf("%s", (char *) b->content);
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
	int		i;
	char	*str;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->a = NULL;
	data->bench = NULL;
	// b = NULL;
	i = 0;
	while (i < 10)
	{
		str = ft_calloc(2, 1);
		str[0] = 48 + i;
		ft_lstadd_back(&(data->a), ft_lstnew(str));
		i++;
	}
	print_stacks(data->a, data->b);
	printf("---------------------------\n");
	// rrx(data, 'a');
	// rrx(data, 'b');
	px(data, 'b');
	px(data, 'b');
	px(data, 'b');
	px(data, 'b');
	// print_stacks(data->a, data->b);
	ss(data);
	print_stacks(data->a, data->b);
}
