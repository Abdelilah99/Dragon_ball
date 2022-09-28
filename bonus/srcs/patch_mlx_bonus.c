/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:25:35 by anoury            #+#    #+#             */
/*   Updated: 2022/09/16 13:34:29 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 *  path mlx for pixel line problem
 */
void	patch_mlx(t_data *game)
{
	game->sizetile = game->wall.h - 1;
}
