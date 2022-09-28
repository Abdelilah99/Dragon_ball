/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:37:22 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:37:22 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	m_value(char const*s, unsigned int c, size_t n)
{
	int	m;

	m = n;
	if (n > ft_strlen(s) - c)
		m = ft_strlen(s) - c + 1;
	if (c > ft_strlen(s))
		m = 0;
	return (m);
}

char	*ft_substr(char const *s, unsigned int c, size_t n)
{
	char	*p;
	size_t	i;
	size_t	j;
	int		m;

	i = 0;
	if (!s)
		return (NULL);
	m = m_value(s, c, n);
	p = malloc(sizeof(char) * (m + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (s[i] && j < n)
	{
		if (i >= c)
		{
			p[j] = s[i];
			j++;
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}
