/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:32:16 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:32:17 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t n)
{
	char	*str;

	if (nb == SIZE_MAX)
		return (NULL);
	str = malloc(nb * n);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (nb * n));
	return ((void *)str);
}
