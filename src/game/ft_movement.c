/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/18 22:04:59 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	move_check(t_mini_map *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (true);
	return (false);
}

void	move_up(t_mini_map *game)
{
	if (move_check(game, game->player_x - 1, game->player_y) == false)
		game->playr->instances[0].y -= 5;
}

void	move_down(t_mini_map *game)
{
	if (move_check(game, game->player_x + 1, game->player_y) == false)
		game->playr->instances[0].y += 5;
}

void	move_left(t_mini_map *game)
{
	if (move_check(game, game->player_x, game->player_y - 1)  == false)
		game->playr->instances[0].x -= 5;
}

void	move_right(t_mini_map *game)
{
	if (move_check(game, game->player_x, game->player_y + 1) == false)
		game->playr->instances[0].x += 5;
}
