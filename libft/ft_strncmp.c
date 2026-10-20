/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strncmp.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/23 14:48:00 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/09/26 17:40:35 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	cs1;
	unsigned char	cs2;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		cs1 = (unsigned char) s1[i];
		cs2 = (unsigned char) s2[i];
		if (cs1 != cs2)
			return (cs1 - cs2);
		i++;
	}
	return (0);
}
