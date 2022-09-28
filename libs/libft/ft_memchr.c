/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:16 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:34:17 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*pstr;
	unsigned char	uc;

	i = 0;
	pstr = (unsigned char *)str;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (pstr[i] == uc)
		{
			return (&pstr[i]);
		}
		i++;
	}
	return (NULL);
}
