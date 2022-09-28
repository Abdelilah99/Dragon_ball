/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:37:09 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:37:09 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		n;
	char	*pstr;
	char	uc;

	pstr = (char *)str;
	uc = (char)c;
	n = ft_strlen(str);
	while (n >= 0)
	{
		if (pstr[n] == uc)
		{
			return (&pstr[n]);
		}
		n--;
	}
	return (NULL);
}
