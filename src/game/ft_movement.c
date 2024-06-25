/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/25 13:01:13 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(t_mini_map *game, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player_dx;
	game->player_dx = game->player_dx * cos(rot) - game->player_dy * sin(rot);
	game->player_dy = old_dir_x * sin(rot) + game->player_dy * cos(rot);
	old_plane_x = game->cam_plane_x;
	game->cam_plane_x = game->cam_plane_x * cos(rot) - game->cam_plane_y * sin(rot);
	game->cam_plane_y = old_plane_x * sin(rot) + game->cam_plane_y * cos(rot);
}

bool	move_check(t_mini_map *game, int x, int y)
{
	// if (game->map[game->player_x][game->player_y] == '0')
	return (true);
	return (false);
}

void	move_up(t_mini_map *game)
{
	// if (move_check(game, game->player_x - 1, game->player_y) == false)
	game->playr->instances[0].y -= 1;
	game->line->instances[0].y -= 1;
}

void	move_down(t_mini_map *game)
{
	// if (move_check(game, game->player_x + 1, game->player_y) == false)
	game->playr->instances[0].y += 1;
	game->line->instances[0].y += 1;
}

void	move_left(t_mini_map *game)
{
	// if (move_check(game, game->player_x, game->player_y - 1)  == false)
	game->playr->instances[0].x -= 1;
	game->line->instances[0].x -= 1;
}

void	move_right(t_mini_map *game)
{
	// if (move_check(game, game->player_x, game->player_y + 1) == false)
	game->playr->instances[0].x += 1;
	game->line->instances[0].x += 1;
}
