/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:37:15 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:37:16 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && chr(s1[i], set))
		i++;
	while (j > i && chr (s1[j - 1], set))
		j--;
	ptr = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!ptr)
		return (NULL);
	while (s1[i] && i < j)
	{
		ptr[k] = s1[i];
		k++;
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}
