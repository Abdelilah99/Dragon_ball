/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_img_logic_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:25:43 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:34 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_counter_in_windows(t_data *game, char *str)
{
	mlx_string_put(game->mlx, game->windows, game->sizetile / 3, \
		game->sizetile / 2, 0xffff0000, str);
}

int	trace_player_to_win(t_data *game, int posx, int posy, int i)
{
	int	hpng;

	hpng = game->sizetile;
	if (game->dir == 2)
		mlx_put_image_to_window(game->mlx, game->windows, \
				game->player2.png.img, hpng * posx, hpng * posy);
	else
		mlx_put_image_to_window(game->mlx, game->windows, \
				game->player.png.img, hpng * posx, hpng * posy);
	game->player.posi = i;
	game->player.posx = posx;
	game->player.posy = posy;
	return (0);
}

int	pttw_norm2(t_data *game, int posx, int posy, int index)
{
	int	sizepng;

	sizepng = game->sizetile;
	if (game->map.tile[index] != GROUND && game->map.tile[index] != WALL_1
		&& game->map.tile[index] != WALL_2 && game->map.tile[index] != WALL_3)
	{
		mlx_put_image_to_window(game->mlx, game->windows,
			game->wall.img, sizepng * posx, sizepng * posy);
	}
	if (game->map.tile[index] != GROUND && game->map.tile[index] != WALL
		&& game->map.tile[index] != WALL_2 && game->map.tile[index] != WALL_3)
	{
		mlx_put_image_to_window(game->mlx, game->windows,
			game->wall_1.img, sizepng * posx, sizepng * posy);
	}
	if (game->map.tile[index] != GROUND && game->map.tile[index] != WALL_1
		&& game->map.tile[index] != WALL && game->map.tile[index] != WALL_3)
	{
		mlx_put_image_to_window(game->mlx, game->windows,
			game->wall_2.img, sizepng * posx, sizepng * posy);
	}
	return (0);
}

int	pttw_norm(t_data *game, int posx, int posy, int index)
{
	int	sizepng;

	sizepng = game->sizetile;
	if (game->map.tile[index] != GROUND && game->map.tile[index] != WALL_1
		&& game->map.tile[index] != WALL_2 && game->map.tile[index] != WALL)
	{
		mlx_put_image_to_window(game->mlx, game->windows,
			game->wall_3.img, sizepng * posx, sizepng * posy);
	}
	if (game->map.tile[index] != WALL && game->map.tile[index] != WALL_1
		&& game->map.tile[index] != WALL_2 && game->map.tile[index] != WALL_3)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->ground.img, sizepng * posx, sizepng * posy);
	if (game->map.tile[index] == ITEM)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->item.img, sizepng * posx, sizepng * posy);
	else if (game->map.tile[index] == DOOR)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->door.img, sizepng * posx, sizepng * posy);
	else if (game->map.tile[index] == PLAYER)
		trace_player_to_win(game, posx, posy, index);
	else if (game->map.tile[index] == ENEMY)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->enemy.png.img, sizepng * posx, sizepng * posy);
	return (0);
}

int	push_tile_to_win(t_data *game)
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
		pttw_norm2(game, posx, posy, index);
		pttw_norm(game, posx, posy, index);
		posx++;
		index++;
	}
	return (0);
}
