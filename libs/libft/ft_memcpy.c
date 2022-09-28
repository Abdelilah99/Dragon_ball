/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:28 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:34:29 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sr;

	i = 0;
	dest = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dest[i] = sr[i];
		i++;
	}
	return (dest);
}
