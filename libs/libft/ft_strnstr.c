/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:37:01 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:37:02 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hstk, const char *ndl, size_t n)
{
	size_t	i;
	size_t	k;
	size_t	m;

	m = ft_strlen(ndl);
	if (ndl[0] == '\0')
		return ((char *)hstk);
	i = 0;
	k = 0;
	while (hstk[i] && i < n)
	{
		k = 0;
		if (hstk[i] == ndl[k])
		{
			while ((hstk[i + k] == ndl[k]) && ndl[k]
				&& hstk[i] && i + k < n)
			{
				if (k == m - 1)
					return ((char *)&hstk[i]);
				k++;
			}
		}
		i++;
	}
	return (NULL);
}
