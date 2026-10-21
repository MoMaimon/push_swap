/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 17:59:32 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/21 20:13:34 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_data
{
	t_list		*a;
	t_list		*b;
	t_strategy	strategy;
	int			bench;
}	t_data;

int	sx(t_data data, char stack);
int	ss(t_data data);
int	px(t_data data, char stack);
int	rx(t_data data, char stack);
int	rr(t_data data);
int	rrx(t_data data, char stack);
int	rrr(t_data data);

#endif
