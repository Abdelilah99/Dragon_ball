/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_png.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:51:51 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:51:51 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	if (game->error != NO_ERROR)
		write_error_type(game);
}

static void	filename_path(t_data *game)
{
	ft_strlcpy(game->ground.path, "./srcs/png/ground.png", 22);
	ft_strlcpy(game->wall.path, "./srcs/png/wall.png", 20);
	ft_strlcpy(game->wall_1.path, "./srcs/png/wall1.png", 21);
	ft_strlcpy(game->wall_2.path, "./srcs/png/wall2.png", 21);
	ft_strlcpy(game->wall_3.path, "./srcs/png/wall3.png", 21);
	ft_strlcpy(game->item.path, "./srcs/png/item.png", 20);
	ft_strlcpy(game->door.path, "./srcs/png/door.png", 20);
	ft_strlcpy(game->player.png.path, "./srcs/png/player.png", 22);
}

/**
 * @brief save all png file for project in mlx img
 * 
 * @param game 
 */
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
	patch_mlx(game);
}
