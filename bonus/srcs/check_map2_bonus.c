/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:24:21 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:33:57 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_chars_is_valid2(t_data *game)
{
	int	i;

	i = 0;
	while (game->map.tile[i])
	{
		if (WALL == game->map.tile[i] || WALL_1 == game->map.tile[i])
			i++;
		else if (WALL_2 == game->map.tile[i] || WALL_3 == game->map.tile[i])
			i++;
		else if (GROUND == game->map.tile[i])
			i++;
		else if (PLAYER == game->map.tile[i])
			i++;
		else if (ITEM == game->map.tile[i])
			i++;
		else if (DOOR == game->map.tile[i])
			i++;
		else if (ENEMY == game->map.tile[i])
			i++;
		else
		{
			game->error = ERROR_MAP_CHAR_NO_VALID;
			break ;
		}
	}
}

int	check_chars_is_valid(t_data *game)
{
	game->error = NO_ERROR;
	check_chars_is_valid2(game);
	if (game->error != NO_ERROR)
		write_error_type(game);
	return (0);
}
