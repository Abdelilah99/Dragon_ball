/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:52:10 by anoury            #+#    #+#             */
/*   Updated: 2022/09/06 17:52:10 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_data_map(t_data *game, int fd)
{
	static int		lentmp = 0;
	char			*tmp;

	game->line = get_next_line(fd);
	if (!game->line)
		return (0);
	game->map.lenx = ft_strlen(game->line);
	if (game->line[game->map.lenx - 1] == '\n')
	{
		game->line[game->map.lenx - 1] = '\0';
		game->map.lenx--;
	}
	if (lentmp != game->map.lenx && game->map.bool == 1)
	{
		game->error = ERROR_MAP_NO_RECT;
		write_error_type(game);
	}
	lentmp = game->map.lenx;
	tmp = ft_strdup(game->map.tile);
	free(game->map.tile);
	game->map.tile = ft_strjoin(tmp, game->line);
	free(tmp);
	free(game->line);
	game->map.bool = 1;
	return (0);
}

int	parsing_map(t_data	*game, char *pathfile)
{
	int		fd;

	game->map.bool = 0;
	fd = ft_open_file(pathfile, game);
	game->map.tile = ft_strdup("");
	if (!game->map.tile)
		return (0);
	game->map.leny = 1;
	while (1)
	{
		if (fill_data_map(game, fd))
			write_error_type(game);
		if (game->line == NULL)
			break ;
	}
	if (check_chars_is_valid(game) && game->line)
		write_error_type(game);
	if (check_minimum_required(game))
		write_error_type(game);
	if (check_wall_close_map(game, 0))
		write_error_type(game);
	return (0);
}
