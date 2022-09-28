/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_png_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:25:03 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:24 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_if_file_enemy_player_exist(t_data *game)
{
	int	fd;

	fd = open(game->player.png.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
		fd = open(game->enemy.png.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
}

void	norm_cife(t_data *game)
{
	int	fd;

	fd = open(game->wall.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->wall_1.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->wall_2.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->wall_3.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
}

void	check_if_file_exist(t_data *game)
{
	int	fd;

	fd = open(game->ground.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	norm_cife(game);
	fd = open(game->door.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->player.png.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->item.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	check_if_file_enemy_player_exist(game);
	if (game->error != NO_ERROR)
		write_error_type(game);
}

static void	filename_path(t_data *game)
{
	ft_strlcpy(game->ground.path, "./srcs/png/ground.png", 28);
	ft_strlcpy(game->wall.path, "./srcs/png/wall.png", 26);
	ft_strlcpy(game->wall_1.path, "./srcs/png/wall2.png", 27);
	ft_strlcpy(game->wall_2.path, "./srcs/png/wall3.png", 27);
	ft_strlcpy(game->wall_3.path, "./srcs/png/wall4.png", 27);
	ft_strlcpy(game->item.path, "./srcs/png/item.png", 26);
	ft_strlcpy(game->door.path, "./srcs/png/door.png", 26);
	ft_strlcpy(game->player.png.path, "./srcs/png/player.png", 28);
	ft_strlcpy(game->player2.png.path, "./srcs/png/player_opo.png", 32);
	ft_strlcpy(game->enemy.png.path, "./srcs/png/enemy.png", 27);
}

void	define_all_png_to_image(t_data *game)
{
	game->error = NO_ERROR;
	filename_path(game);
	check_if_file_exist(game);
	game->ground.img = mlx_png_file_to_image(game->mlx, game->ground.path,
			&game->ground.w, &game->ground.h);
	game->wall.img = mlx_png_file_to_image(game->mlx, game->wall.path,
			&game->wall.w, &game->wall.h);
	game->wall_1.img = mlx_png_file_to_image(game->mlx, game->wall_1.path,
			&game->wall_1.w, &game->wall_1.h);
	game->wall_2.img = mlx_png_file_to_image(game->mlx, game->wall_2.path,
			&game->wall_2.w, &game->wall_2.h);
	game->wall_3.img = mlx_png_file_to_image(game->mlx, game->wall_3.path,
			&game->wall_3.w, &game->wall_3.h);
	game->item.img = mlx_png_file_to_image(game->mlx, game->item.path,
			&game->item.w, &game->item.h);
	game->door.img = mlx_png_file_to_image(game->mlx, game->door.path,
			&game->door.w, &game->door.h);
	game->player.png.img = mlx_png_file_to_image(game->mlx,
			game->player.png.path, &game->player.png.w, &game->player.png.h);
	game->enemy.png.img = mlx_png_file_to_image(game->mlx,
			game->enemy.png.path, &game->enemy.png.w, &game->enemy.png.h);
	game->player2.png.img = mlx_png_file_to_image(game->mlx,
			game->player2.png.path, &game->player2.png.w, &game->player2.png.h);
	patch_mlx(game);
}
