/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:35:22 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:35:22 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dptr_len(char *str, char c)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j] && str[j] == c)
			j++;
		if (str[j] && str[j] != c)
		{
			i++;
			while (str[j] && str[j] != c)
				j++;
		}
	}
	return (i);
}

static char	*splt(char *s, char c)
{
	size_t	i;
	char	*ps;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	ps = (char *)malloc(sizeof(char) * (i + 1));
	if (!ps)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		ps[i] = s[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}

char	**ft_split(char const*s, char c)
{
	size_t		i;
	char		**dptr;
	char		*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	dptr = malloc(sizeof(char *) * (dptr_len(str, c) + 1));
	if (!dptr)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			dptr[i] = splt(str, c);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	dptr[i] = NULL;
	return (dptr);
}
