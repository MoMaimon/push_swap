/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 18:10:47 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/11 21:20:30 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_strat(t_data *data, t_strategy strat)
{
	if (ft_lstsize(data->a) <= 5)
	{
		complex_sort(data);
		return ;
	}
	if (strat == SIMPLE)
		simple_sort(data);
	else if (strat == MEDIUM)
		medium_sort(data);
	else if (strat == COMPLEX)
		complex_sort(data);
}

void	no_param_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		no_param_error(argv[0]);
	init_data(&data);
	if (!read_input(argc, argv, &data))
		error(&data);
	get_disorder(&data);
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
