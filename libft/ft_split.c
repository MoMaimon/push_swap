/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 13:52:21 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/10/01 19:03:45 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 1;
	if (!str[i])
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static char	*get_word(char *s, char c)
{
	char	*sep;
	char	*str;
	size_t	len;

	sep = ft_strchr(s, c);
	if (sep)
		len = (long) sep - (long) s + 1;
	else
		len = ft_strlen(s) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len);
	return (str);
}

static int	make_arr(char **arr, char *s, char c)
{
	int		i;
	int		j;
	char	*temp_str;

	i = 0;
	j = 0;
	if (s[i])
	{
		temp_str = get_word(&s[i++], c);
		if (!temp_str)
			return (0);
		arr[j++] = temp_str;
	}
	while (s[i++])
	{
		if (s[i - 1] != c && s[(i - 1) - 1] == c)
		{
			temp_str = get_word(&s[i - 1], c);
			if (!temp_str)
				return (0);
			arr[j++] = temp_str;
		}
	}
	arr[j] = 0;
	return (1);
}

static void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	*trimmed_str;
	int		words;
	char	**arr;
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	trimmed_str = ft_strtrim(s, set);
	if (!trimmed_str)
		return (NULL);
	words = count_words(trimmed_str, c);
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
	{
		free(trimmed_str);
		return (NULL);
	}
	if (!make_arr(arr, trimmed_str, c))
	{
		free_all(arr);
		free(trimmed_str);
		return (NULL);
	}
	free(trimmed_str);
	return (arr);
}
