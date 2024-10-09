/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/10/09 14:15:28 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(t_cube *game, double rot)
{
	
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(rot) - game->dir_y * sin(rot);
	game->dir_y = old_dir_x * sin(rot) + game->dir_y * cos(rot);
	
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(rot) - game->plane_y * sin(rot);
	game->plane_y = old_plane_x * sin(rot) + game->plane_y * cos(rot);
}


bool	move_check(t_cube *game, int x, int y)
{
	if (game->map[(int)game->player_x][(int)game->player_y] == '0')
		return (true);
	return (false);
}

