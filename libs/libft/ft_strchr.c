/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:35:28 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:35:29 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		m;
	char	*pstr;
	char	uc;

	i = 0;
	pstr = (char *)str;
	uc = (char)c;
	m = ft_strlen(pstr) + 1;
	while (i < m)
	{
		if (pstr[i] == uc)
		{
			return (&pstr[i]);
		}
		i++;
	}
	return (NULL);
}
