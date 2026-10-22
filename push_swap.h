/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 17:59:32 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/22 16:11:15 by mabd-elh        ###   ########.fr        */
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

typedef struct s_bench
{
	float		disorder;
	t_strategy	strategy;
	int			sa;
	int			sb;
	int			ss;
	int			pa;
	int			pb;
	int			ra;
	int			rb;
	int			rr;
	int			rra;
	int			rrb;
	int			rrr;
}	t_bench;

typedef struct s_data
{
	t_list		*a;
	t_list		*b;
	t_strategy	strategy;
	t_bench		*bench;
}	t_data;

int		sx(t_data *data, char stack);
void	ss(t_data *data);
void	px(t_data *data, char stack);
int		rx(t_data *data, char stack);
void	rr(t_data *data);
int		rrx(t_data *data, char stack);
void	rrr(t_data *data);
void	get_disorder(t_data *data);

#endif
