/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:24:53 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:17 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	dadado(t_data *game)
{
	int		w;
	int		h;
	char	*relative_path;
	t_data2	img;

	img.lx = (game->map.lenx * 64 - 789) / 2;
	img.ly = (game->map.leny * 64 - 479) / 2;
	relative_path = "./srcs/png/Finish.png";
	img.img = mlx_png_file_to_image(game->mlx, relative_path, &w, &h);
	mlx_put_image_to_window(game->mlx, game->windows, img.img, img.lx, img.ly);
}

void	dadadodi(t_data *game)
{
	int		w;
	int		h;
	char	*relative_path;
	t_data2	img;

	img.lx = (game->map.lenx * 64 - 789) / 2;
	img.ly = (game->map.leny * 64 - 479) / 2;
	relative_path = "./srcs/png/gameover.png";
	img.img = mlx_png_file_to_image(game->mlx, relative_path, &w, &h);
	mlx_put_image_to_window(game->mlx, game->windows, img.img, img.lx, img.ly);
}

void	player_move_counter(t_data *game)
{
	game->player.countmove++;
	ft_putnbr(game->player.countmove);
	ft_putchar('\n');
	put_counter_in_windows(game, ft_itoa(game->player.countmove));
}

int	norm_cm(t_data *game, int target)
{
	if (game->map.tile[target] != WALL && game->map.tile[target] != DOOR \
		&& game->map.tile[target] != ENEMY && game->map.tile[target] != WALL_1
		&& game->map.tile[target] != WALL_2 && game->map.tile[target] != WALL_3)
	{
		game->map.tile[game->player.posi] = GROUND;
		game->map.tile[target] = PLAYER;
		push_tile_to_win(game);
		return (1);
	}
	return (0);
}

int	collision_management(t_data *game, int target)
{
	int	nb_item;

	nb_item = ft_str_search_char(game->map.tile, ITEM);
	if (norm_cm(game, target) == 1)
	{
		player_move_counter(game);
	}
	else if (game->map.tile[target] == DOOR)
	{
		if (nb_item <= 0)
		{
			player_move_counter(game);
			dadado(game);
			game->dir = 5;
		}
	}
	else if (game->map.tile[target] == ENEMY)
	{
		player_move_counter(game);
		dadadodi(game);
		exit_gameover(game);
	}
	return (0);
}
