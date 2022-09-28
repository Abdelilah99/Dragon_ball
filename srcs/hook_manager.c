/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:51:45 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:51:45 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	dadado(t_data *game)
{
	int			w;
	int			h;
	char		*relative_path;
	t_data2		img;

	relative_path = "./srcs/png/winner.png";
	img.lx = (game->map.lenx * 64 - 728) / 2;
	img.ly = (game->map.leny * 64 - 455) / 2;
	img.img = mlx_png_file_to_image(game->mlx, relative_path, &w, &h);
	mlx_put_image_to_window(game->mlx, game->windows, img.img, img.lx, img.ly);
}

void	player_move_counter(t_data *game)
{
	game->player.countmove++;
	ft_putnbr(game->player.countmove);
	ft_putchar('\n');
}

int	collision_management(t_data *game, int target)
{
	int	nb_item;

	nb_item = ft_str_search_char(game->map.tile, ITEM);
	if (game->map.tile[target] != WALL && game->map.tile[target] != WALL_1
		&& game->map.tile[target] != WALL_2 && game->map.tile[target] != WALL_3
		&& game->map.tile[target] != DOOR)
	{
		game->map.tile[game->player.posi] = GROUND;
		game->map.tile[target] = PLAYER;
		push_tile_to_win(game);
		player_move_counter(game);
	}
	else if (game->map.tile[target] == DOOR)
	{
		if (nb_item <= 0)
		{
			player_move_counter(game);
			dadado(game);
			game->st = 5;
		}
	}
	return (0);
}

int	key_hook(int kc, t_data *game)
{
	int	target;

	target = 0;
	if (kc == touch_up || kc == touch_w)
		target = game->player.posi - game->map.lenx;
	else if (kc == touch_down || kc == touch_s)
		target = game->player.posi + game->map.lenx;
	else if (kc == touch_right || kc == touch_d)
		target = game->player.posi + 1;
	else if (kc == touch_left || kc == touch_a)
		target = game->player.posi - 1;
	else if (kc == touch_o)
	{
		game->st = 6;
		push_tile_to_win(game);
	}
	else if (kc == touch_esc || kc == touch_f)
		exit_normal(game);
	if (game->st == 6)
		collision_management(game, target);
	return (0);
}
