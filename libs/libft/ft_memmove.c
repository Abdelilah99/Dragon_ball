/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:36 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:34:37 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pd;
	char	*ps;

	i = 0;
	pd = (char *)dst;
	ps = (char *)src;
	if (!pd && !ps)
		return (NULL);
	if (pd > ps)
		while (n-- > 0)
			pd[n] = ps[n];
	else
	{
		while (i < n)
		{
			pd[i] = ps[i];
			i++;
		}
	}
	return (dst);
}
