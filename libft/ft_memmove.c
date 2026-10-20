/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/23 12:01:54 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/09/30 21:33:19 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	overlap;
	int		i;

	overlap = (size_t) dest - (size_t) src;
	if (overlap > 0 && overlap < n)
	{
		i = n - 1;
		while (i >= 0)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
