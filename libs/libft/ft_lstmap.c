/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:33:58 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:33:58 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*old;
	t_list	*rtn;

	rtn = NULL;
	old = lst;
	while (old)
	{
		new = ft_lstnew(f(old->content));
		if (new)
			ft_lstadd_back(&rtn, new);
		else
		{
			ft_lstclear(&rtn, del);
			return (NULL);
		}
		old = old->next;
	}
	return (rtn);
}
