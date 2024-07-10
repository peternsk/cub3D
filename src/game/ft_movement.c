/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/07/09 23:40:16 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(t_cube *game, double rot)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player_x;
	game->player_x = game->player_x * cos(rot) - game->player_y * sin(rot);
	game->player_y = old_dir_x * sin(rot) + game->player_y * cos(rot);
	old_plane_x = game->cam_x;
	game->cam_x = game->cam_x * cos(rot) - game->cam_y
		* sin(rot);
	game->cam_y = old_plane_x * sin(rot) + game->cam_y * cos(rot);
}


bool	move_check(t_cube *game, int x, int y)
{
	// if (game->map[game->player_x][game->player_y] == '0')
	return (true);
	return (false);
}

void	move_up(t_cube *game)
{
	if(game->map[(int)game->player_y - 1][(int)game->player_x] == '0')
		game->playr->instances[0].y -= 1;
}

void	move_down(t_cube *game)
{
	if(game->map[(int)game->player_y + 1][(int)game->player_x] == '0')
		game->playr->instances[0].y += 1;
}
