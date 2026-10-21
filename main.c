/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 18:10:47 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/21 18:48:53 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// DELETE THIS BEFORE FINISH
// add ur ft_printf into libft
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	t_list *a;
	t_list *b;

	// int		algorithm; --meduim
	// int	bench;
	if (argc < 2)
		return (-1);
	// add error massage
	i = 1;
	while (i < argc)
	{
		printf("%s\n", argv[i++]);
	}
}
