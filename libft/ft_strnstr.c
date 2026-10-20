/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:57:15 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/09/29 05:03:14 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *) big);
	while (i <= len - little_len && len && big[i])
	{
		if (little[0] == big[i])
		{
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *) & big[i]);
		}
		i++;
	}
	return (0);
}
