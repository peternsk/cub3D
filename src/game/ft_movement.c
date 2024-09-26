/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/09/26 14:09:22 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	rotate_player(t_cube *game, double rot)
{
	printf("== DEBUG SEGGGGG ROTATE START*************************************** ==\n");
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	game->dir_x = game->dir_x * cos(rot) - game->dir_y * sin(rot);
	game->dir_y = old_dir_x * sin(rot) + game->dir_y * cos(rot);
	old_plane_x = game->plane_x;
	game->plane_x = game->plane_x * cos(rot) - game->plane_y * sin(rot);
	game->plane_y = old_plane_x * sin(rot) + game->plane_y * cos(rot);
	
	printf("== DEBUG SEGGGGG ROTATE END****************************************** ==\n");
}


bool	move_check(t_cube *game, int x, int y)
{
	if (game->map[(int)game->player_x][(int)game->player_y] == '0')
		return (true);
	return (false);
}

void	move_up(t_cube *game)
{
	// if(game->map[(int)game->player_y + 1][(int)game->player_x] == '0')
	// {
		game->playr->instances[0].y += 1;
	// }
	// else
	// 	printf("CAN'T MOVE UP\n");
}

void	move_down(t_cube *game)
{
	// if(game->map[(int)game->player_y - 1][(int)game->player_x] == '0')
		game->playr->instances[0].y -= 1;
	// else
	// 	printf("CAN'T MOVE DOWN\n");
}
