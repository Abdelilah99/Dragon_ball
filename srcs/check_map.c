/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:51:31 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:51:32 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	save_only_first_position(t_data *game, int counter)
{
	int	lenmap;
	int	i;

	i = 1;
	lenmap = ft_strlen(game->map.tile) - 1;
	while (lenmap > 0 && counter > i)
	{
		if (game->map.tile[lenmap] == PLAYER)
		{
			game->map.tile[lenmap] = GROUND;
			i++;
		}
		lenmap--;
	}
	return (0);
}

int	check_minimum_required(t_data *game)
{
	int	c;
	int	e;
	int	p;

	c = ft_str_search_char(game->map.tile, ITEM);
	e = ft_str_search_char(game->map.tile, DOOR);
	p = ft_str_search_char(game->map.tile, PLAYER);
	if (c <= 0)
		game->error = ERROR_MAP_NO_ITEM;
	else if (p == 0)
		game->error = ERROR_MAP_NO_PLAYER;
	else if (p > 1)
	{
		game->error = ERROR_WARNING_PLAYER;
		save_only_first_position(game, p);
	}
	else if (e <= 0)
		game->error = ERROR_MAP_NO_EXIT;
	if (game->error != NO_ERROR)
		write_error_type(game);
	return (0);
}

int	norm_cwcm(t_data *game, int i, int posx, int posy)
{
	if (((posy == 1) || (posx == 1) || (posy == game->map.leny) \
		|| (posx == game->map.lenx))
		&& game->map.tile[i] != WALL && game->map.tile[i] != WALL_1
		&& game->map.tile[i] != WALL_2 && game->map.tile[i] != WALL_3)
		return (1);
	return (0);
}

int	check_wall_close_map(t_data *game, int i)
{
	int	posx;
	int	posy;

	posx = 1;
	posy = 1;
	game->map.leny = (int)ft_strlen(game->map.tile) / game->map.lenx;
	while (game->map.tile[i])
	{
		if (norm_cwcm(game, i, posx, posy) == 1)
		{
			game->error = ERROR_MAP_WALL;
			write_error_type(game);
		}
		if (posx == game->map.lenx)
		{
			posx = 1;
			posy++;
		}
		else
			posx++;
		i++;
	}
	return (0);
}

int	check_chars_is_valid(t_data *game)
{
	int	i;

	i = 0;
	game->error = NO_ERROR;
	while (game->map.tile[i])
	{
		if (WALL == game->map.tile[i] || WALL_3 == game->map.tile[i])
			i++;
		else if (WALL_1 == game->map.tile[i] || WALL_2 == game->map.tile[i])
			i++;
		else if (GROUND == game->map.tile[i] || PLAYER == game->map.tile[i])
			i++;
		else if (ITEM == game->map.tile[i])
			i++;
		else if (DOOR == game->map.tile[i])
			i++;
		else
		{
			game->error = ERROR_MAP_CHAR_NO_VALID;
			break ;
		}
	}
	if (game->error != NO_ERROR)
		write_error_type(game);
	return (0);
}
