/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:51:56 by anoury            #+#    #+#             */
/*   Updated: 2022/09/19 22:06:47 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	dada(t_data *game)
{
	int		w;
	int		h;
	char	*relative_path;
	t_data2	img;

	img.lx = (game->map.lenx * 64 - 1024) / 2;
	img.ly = (game->map.leny * 64 - 631) / 2;
	relative_path = "./srcs/png/main.png";
	img.img = mlx_png_file_to_image(game->mlx, relative_path, &w, &h);
	mlx_put_image_to_window(game->mlx, game->windows, img.img, img.lx, img.ly);
}

void sucalaminchia ()
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_data	game;

	atexit(sucalaminchia);
	if (check_norm_arg_is_ok(ac, av[1], &game) == 0)
		write_error_type(&game);
	game.mlx = mlx_init();
	define_all_png_to_image(&game);
	game.error = NO_ERROR;
	game.player.countmove = 0;
	parsing_map(&game, av[1]);
	game.map.leny = (ft_strlen(game.map.tile) / game.map.lenx);
	game.img_width = game.sizetile * game.map.lenx;
	game.img_height = game.sizetile * game.map.leny;
	game.windows = mlx_new_window(game.mlx, game.img_width,
			game.img_height, "so_long");
	game.img = mlx_new_image(game.mlx, game.img_width, game.img_height);
	dada(&game);
	mlx_hook(game.windows, X_EVENT_KEY_PRESS, 0, key_hook, &game);
	mlx_hook(game.windows, X_EVENT_KEY_EXIT, 0, exit_normal, &game);
	mlx_loop (game.mlx);
	free(game.map.tile);
	return (0);
}
