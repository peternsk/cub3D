/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/17 10:48:34 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	move_check(t_mini_map *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (1);
	return (0);
}

void	move_up(t_mini_map *game)
{
	if (move_check(game, game->player_x - 1, game->player_y))
	{
		game->arr_img[PLAYER]->instances[0].y -= 2;
		game->player_x--;
	}
}

void	move_down(t_mini_map *game)
{
	if (move_check(game, game->player_x + 1, game->player_y))
	{
		game->arr_img[PLAYER]->instances[0].y += 2;
		game->player_x++;
	}
}

void	move_left(t_mini_map *game)
{
	if (move_check(game, game->player_x, game->player_y - 1))
	{
		game->arr_img[PLAYER]->instances[0].x -= 2;
		game->player_y--;
	}
}

void	move_right(t_mini_map *game)
{
	if (move_check(game, game->player_x, game->player_y + 1))
	{
		game->arr_img[PLAYER]->instances[0].x += 2;
		game->player_y++;
	}
}
