/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:17:38 by peternsaka        #+#    #+#             */
/*   Updated: 2024/09/30 14:48:08 by pnsaka           ###   ########.fr       */
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
	
	// printf("old_dir_x : %f\n", old_dir_x);
	// printf("old_plane_x : %f\n", old_plane_x);
	// printf("game->dir_x : %f\n", game->dir_x);
	// printf("game->dir_y : %f\n",  game->dir_y);
	// printf("game->plane_y  : %f\n",  game->plane_y);
	// printf("game->plane_x  : %f\n",  game->plane_x);
	
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
		game->playr->instances[0].y += 1;
		// printf("game step %f\n", game->player_y);
	// }
	// else
	// 	printf("CAN'T MOVE UP\n");
}

void	move_down(t_cube *game)
{
	// if(game->map[(int)game->player_y - 1][(int)game->player_x] == '0')
		game->playr->instances[0].y -= 1;
		game->plane_y -= 1;
		// printf("game step %f\n", game->player_y);
	// else
	// 	printf("CAN'T MOVE DOWN\n");
}
