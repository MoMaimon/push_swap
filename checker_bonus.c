/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 15:27:33 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/11/12 15:22:28 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_and_do_op(t_data *data, char *op)
{
	if (!ft_strcmp(op, "pa\n"))
		px(data, 'a');
	else if (!ft_strcmp(op, "pb\n"))
		px(data, 'b');
	else if (!ft_strcmp(op, "ra\n"))
		rx(data, 'a');
	else if (!ft_strcmp(op, "rb\n"))
		rx(data, 'b');
	else if (!ft_strcmp(op, "rra\n"))
		rrx(data, 'a');
	else if (!ft_strcmp(op, "rrb\n"))
		rrx(data, 'b');
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(data);
	else if (!ft_strcmp(op, "rr\n"))
		rr(data);
	else if (!ft_strcmp(op, "sa\n"))
		sx(data, 'a');
	else if (!ft_strcmp(op, "sb\n"))
		sx(data, 'b');
	else if (!ft_strcmp(op, "ss\n"))
		ss(data);
}

static int	process_inp(char *argv, t_data *data, int *number)
{
	int		count_input;
	char	**input;

	input = ft_split(argv, ' ');
	if (!input)
		return (0);
	count_input = 0;
	while (input[count_input] != NULL)
	{
		if (edite_stack(input[count_input], data, number))
		{
			free_all(input);
			return (0);
		}
		count_input++;
	}
	free_all(input);
	return (1);
}

void	apply_sort(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_and_do_op(data, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		number;

	init_data(&data);
	if (argc < 2)
		error(&data);
	i = 1;
	while (i < argc)
	{
		if (!process_inp(argv[i], &data, &number))
			error(&data);
		i++;
	}
	apply_sort(&data);
	get_disorder(&data);
	if (data.disorder == 0 && !data.b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	remove_stack(&(data.a));
	remove_stack(&(data.b));
	remove_stack(&(data.ops));
	free(data.bench);
}
