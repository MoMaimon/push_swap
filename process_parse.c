/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:18:59 by yaabed            #+#    #+#             */
/*   Updated: 2026/11/02 11:33:01 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_arg(char *arg, t_data *data, int *flags, int *number)
{
	if (is_strategy(arg))
		return (parse_strategy(arg, data, &flags[0]));
	if (ft_strcmp("--bench", arg) == 0 && !flags[1])
	{
		data->bench = malloc(sizeof(t_bench));
		if (!data->bench)
			return (0);
		flags[1] = 1;
		return (1);
	}
	return (!edite_stack(arg, data, number));
}

int	process_input(char *argv, t_data *data, int *flags, int *number)
{
	int		count_input;
	char	**input;

	input = ft_split(argv, ' ');
	if (!input)
		return (0);
	count_input = 0;
	while (input[count_input] != NULL)
	{
		if (!process_arg(input[count_input], data, flags, number))
		{
			free_all(input);
			return (0);
		}
		count_input++;
	}
	free_all(input);
	return (1);
}
