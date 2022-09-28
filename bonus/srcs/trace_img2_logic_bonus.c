/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_img2_logic_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:26:00 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:38 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	push_windows(t_data *game)
{
	push_tile_to_win(game);
	return (0);
}

int	enemy_disspear(t_data *game)
{
	int		posx;
	int		posy;
	int		index;
	int		sizepng;

	sizepng = game->sizetile;
	posx = 0;
	posy = 0;
	index = 0;
	while (game->map.tile[index])
	{
		if (posx == game->map.lenx)
		{
			posx = 0;
			posy++;
		}
		if (game->map.tile[index] == ENEMY)
			mlx_put_image_to_window(game->mlx, game->windows,
				game->ground.img, sizepng * posx, sizepng * posy);
		posx++;
		index++;
	}
	return (0);
}
