/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:14:14 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/26 19:29:30 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(t_data *data)
{
	int		disorder;
	char	*str;
	size_t	i;

	disorder = (data->disorder) * 10000;
	if (disorder == 10000)
	{
		ft_putstr_fd("100.00%\n", 2);
		return ;
	}
	str = ft_itoa(disorder);
	if (!str)
		error(data);
	i = 0;
	while (i++ < 4)
	{
		if (i - 1 == 2)
			ft_putchar_fd('.', 2);
		if (4 - ft_strlen(str) > i - 1)
			ft_putchar_fd('0', 2);
		else
			ft_putchar_fd(str[(i - 1) - (4 - ft_strlen(str))], 2);
	}
	ft_putstr_fd("%\n", 2);
	free(str);
}

static void	print_strat(t_data *data)
{
	t_strategy	data_strat;
	t_strategy	chosen_strat;

	data_strat = data->strategy;
	chosen_strat = data->bench->strategy;
	ft_putstr_fd("[bench] strategy:\t", 2);
	if (data_strat == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
	else if (data_strat == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (data_strat == COMPLEX)
		ft_putstr_fd("Medium / O(n log n)\n", 2);
	else
	{
		if (chosen_strat == SIMPLE)
			ft_putstr_fd("Adaptive / O(n^2)\n", 2);
		if (chosen_strat == MEDIUM)
			ft_putstr_fd("Adaptive / O(n√n)\n", 2);
		if (chosen_strat == COMPLEX)
			ft_putstr_fd("Adaptive / O(n log n)\n", 2);
	}
}

static void	print_total_ops(t_bench *bench)
{
	int	total;

	total = 0;
	total += bench->sa;
	total += bench->sb;
	total += bench->ss;
	total += bench->pa;
	total += bench->pb;
	total += bench->ra;
	total += bench->rb;
	total += bench->rr;
	total += bench->rra;
	total += bench->rrb;
	total += bench->rrr;
	ft_putstr_fd("[bench] total_ops:\t", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] sa:\t", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("\tsb:\t", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("\tss:\t", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("\tpa:\t", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("\tpb:\t", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra:\t", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("\trb:\t", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("\trr:\t", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("\trra:\t", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("\trrb:\t", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("\trrr:\t", 2);
	ft_putnbr_fd(bench->rrr, 2);
}

void	print_bench(t_data *data)
{
	if (!data->bench)
		return ;
	ft_putstr_fd("[bench] disorder:\t", 2);
	print_disorder(data);
	print_strat(data);
	print_total_ops(data->bench);
	print_ops(data->bench);
	ft_putchar_fd('\n', 2);
}
