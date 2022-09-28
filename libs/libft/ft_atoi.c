/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:32:00 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:32:01 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	condition(const char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\t' || str[i] == '\n')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				r;
	long			m;

	i = 0;
	r = 1;
	m = 0;
	i = condition(str, i);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			r = r * (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		m = (m * 10) + (str[i] - '0');
		if (m > 2147483647 && r == 1)
			return (-1);
		if (m > 2147483648 && r == -1)
			return (0);
		i++;
	}
	return ((int)(m * r));
}
