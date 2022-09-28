/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:24:43 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:07 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	norm_kh(int kc, t_data *game)
{
	int	target;

	target = 0;
	if (kc == touch_right || kc == touch_d)
	{
		game->dir = 1;
		target = game->player.posi + 1;
	}
	else if (kc == touch_left || kc == touch_a)
	{
		game->dir = 2;
		target = game->player.posi - 1;
	}
	else if (kc == touch_o)
	{
		push_tile_to_win(game);
		game->st = 6;
	}
	return (target);
}

int	key_hook(int kc, t_data *game)
{
	int	target;

	target = 0;
	if (kc == touch_right || kc == touch_d || kc == touch_o
		|| kc == touch_left || kc == touch_a)
		target = norm_kh(kc, game);
	if (kc == touch_up || kc == touch_w)
		target = game->player.posi - game->map.lenx;
	else if (kc == touch_down || kc == touch_s)
		target = game->player.posi + game->map.lenx;
	else if (kc == touch_esc || kc == touch_f)
		exit_normal(game);
	if (game->st == 6)
		collision_management(game, target);
	return (0);
}
