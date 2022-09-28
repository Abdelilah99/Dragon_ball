/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:34:44 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:34:44 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*pstr;

	pstr = (unsigned char *)str;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		pstr[i] = uc;
		i++;
	}
	return (str);
}
