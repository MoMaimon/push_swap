/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 17:59:32 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/10/27 20:02:31 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
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
	float		disorder;
	t_bench		*bench;
}	t_data;

int		sx(t_data *data, char stack);
void	ss(t_data *data);
int		px(t_data *data, char stack);
int		rx(t_data *data, char stack);
void	rr(t_data *data);
int		rrx(t_data *data, char stack);
void	rrr(t_data *data);
void	get_disorder(t_data *data);
void	print_bench(t_data *data);
void	remove_stack(t_list **stack);
int		add_number(t_list **stack, int value);
int		read_input(int argc, char **argv, t_data *data);
int		convert_number(const char *nptr, int *result);
int		has_duplicate(t_list *stack, int number);
int		ft_strcmp(const char *s1, const char *s2);
void	error(t_data *data);
void	init_bench(t_data *data);
int		get_bindex(t_data *data, int bno, int buckets, int largest);
int		get_largest(t_data *data);
int		get_bucket(int buckets, int largest, int num);
int		ft_sqrt(int n);
void	medium_sort(t_data *data);
int		get_largestindx(t_list *node);

#endif
