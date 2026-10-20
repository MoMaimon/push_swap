/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:26:27 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/01 19:48:34 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, char const *set)
{
	if (ft_strchr(set, c))
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*str;

	left = 0;
	if (!s1 || !set)
		return (NULL);
	if (!s1[0])
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	right = ft_strlen(s1) - 1;
	while (s1[left] && is_inset(s1[left], set))
		left++;
	while (right >= left && is_inset(s1[right], set))
		right--;
	str = malloc(right - left + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[left], right - left + 2);
	return (str);
}
