/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaabed <yaabed@student.42amman.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:38:21 by yaabed            #+#    #+#             */
/*   Updated: 2026/10/22 18:12:28 by yaabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tem;

	if (!lst || !del || !*lst)
		return ;
	tem = *lst;
	current = tem->next;
	while (current != NULL)
	{
		del(tem->content);
		free(tem);
		tem = current;
		current = current->next;
	}
	if (tem != NULL)
	{
		del(tem->content);
		free(tem);
	}
	*lst = NULL;
}
