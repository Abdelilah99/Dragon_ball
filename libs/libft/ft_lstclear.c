/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:33:27 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:33:28 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ls;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		ls = *lst;
		*lst = (*lst)->next;
		del(ls->content);
		free(ls);
	}
}
