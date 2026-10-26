/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 18:10:47 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 17:43:34 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		write(2, "Error\n", 6);
		return (1);
	}
	remove_stack(&data.a);
	remove_stack(&data.b);
	return (0);
}
