/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_next_line_utils.c                             :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: mabd-elh <mabd-elh@student.42amman.com>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 21:15:29 by mabd-elh         #+#    #+#              */
/*   Updated: 2026/11/04 16:38:49 by mabd-elh        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_v2(char *s1, char const *s2, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	str = malloc((s1_len + len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	while (i++ < s1_len)
		str[i - 1] = s1[i - 1];
	i = 0;
	while (i < len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	str[i + s1_len] = '\0';
	free(s1);
	return (str);
}

int	sep_buffer(char **buffer, char **line, char *nl)
{
	long	len;

	len = (long) nl - (long)*buffer + 1;
	*line = ft_strjoin_v2(*line, *buffer, len);
	if (!line)
		return (0);
	ft_memcpy(*buffer, &nl[1], ft_strlen(nl));
	return (1);
}
