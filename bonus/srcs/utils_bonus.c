/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:26:09 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:43 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_str_search_char(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	if (counter > 0)
		return (counter);
	return (0);
}

int	exit_normal(t_data *game)
{
	free(game->map.tile);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->windows);
	exit (0);
}

int	exit_gameover(t_data *game)
{
	int	center_x;
	int	center_y;

	center_x = ((game->map.lenx * game->sizetile) / 2);
	center_y = ((game->map.leny * game->sizetile) / 2);
	ft_putstr("GAME OVER\n");
	mlx_string_put(game->mlx, game->windows, center_x - 100, center_y, \
	0xffff0000, "GAME OVER ");
	mlx_do_sync(game->mlx);
	usleep(750000);
	exit_normal(game);
	return (0);
}
