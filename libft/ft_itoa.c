/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabd-elh <mabd-elh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:38:46 by mabd-elh          #+#    #+#             */
/*   Updated: 2026/09/28 20:36:16 by mabd-elh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilen(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	temp;

	temp = n;
	len = ilen(temp);
	if (n < 0)
	{
		len++;
		temp *= -1;
	}
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (temp / 10)
	{
		str[len - 1] = (temp % 10) + '0';
		temp /= 10;
		len--;
	}
	str[len - 1] = (temp % 10) + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
