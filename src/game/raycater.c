/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:39:40 by peternsaka        #+#    #+#             */
/*   Updated: 2024/09/26 21:13:09 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
void stepPrintf(t_cube *game)
{	
	printf("=====================step function====================\n");
	printf("ray_dir_x	: %f\n", game->ray_dir_x);
	printf("ray_dir_y	: %f\n", game->ray_dir_y);
	printf("side_dist_x : %f\n", game->side_dist_x);
	printf("side_dist_y : %f\n", game->side_dist_y);
	printf("step_x		: %d\n", game->step_x);
	printf("step_y		: %d\n", game->step_y);
	printf("delta_x		: %f\n", game->delta_x);
	printf("delta_y		: %f\n", game->delta_y);
	printf("map_x		: %d\n", game->map_x);
	printf("map_y		: %d\n", game->map_y);
}

void 	step(t_cube *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->player_x - game->map_x) * game->delta_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->player_x) * game->delta_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->player_y - game->map_y) * game->delta_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->player_y) * game->delta_y;
	}
	stepPrintf(game);
}
void ddaPrintf(t_cube *game)
{	
	printf("=====================dda function====================\n");
	printf("side_dist_x		: %f\n", game->side_dist_x);
	printf("side_dist_y		: %f\n", game->side_dist_y);
	printf("map_x			: %d\n", game->map_x);
	printf("map_y			: %d\n", game->map_y);
	printf("side			: %d\n", game->side);
	printf("step_x			: %d\n", game->step_x);
	printf("step_y			: %d\n", game->step_y);
	printf("delta_x			: %f\n", game->delta_x);
	printf("delta_y			: %f\n", game->delta_y);
	printf("=====================dda end====================\n");
}


void	dda(t_cube *game)
{
	while (1)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_x;
			game->map_x += game->step_x;
			game->side = 0;
			// printf("== DDA WHILE->IF ==\n");
		}
		else
		{
			game->side_dist_y += game->delta_y;
			game->map_y += game->step_y;
			game->side = 1;
			// printf("== DDA WHILE->ELSE ==\n");
		}
		if (game->map[game->map_y][game->map_x] == 'X'){
			// printf("== DDA WHILE->BREAK ==\n");
			break ;
		}
	}
	// printf("== DDA OUT WHILE ==\n");
	if (game->side == 0)
		game->perp_dist = (game->side_dist_x - game->delta_x);
	else
		game->perp_dist = (game->side_dist_y - game->delta_y);
		ddaPrintf(game);
}
void dist_calcPrintf(t_cube *game)
{	
	printf("=====================dist_calc function====================\n");
	printf("delta_x		: %f\n", game->delta_x);
	printf("delta_y		: %f\n", game->delta_y);
	printf("ray_dx		: %f\n", game->ray_dx);
	printf("ray_dy		: %f\n", game->ray_dy);
	printf("=====================dist_calc end====================\n");
}

void	dist_calc(t_cube *game)
{
	if (game->ray_dx == 0)
		game->delta_x = 1e30;
	else
		game->delta_x = fabs(1 / game->ray_dir_x);
	if (game->ray_dy == 0)
		game->delta_y = 1e30;
	else
		game->delta_y = fabs(1 / game->ray_dir_y);
		dist_calcPrintf(game);
}

void wall_heightPrintf(t_cube *game){
	printf("===================== wall_height function====================\n");
	printf("game side	: %d\n", game->side);
	printf("wall_dist	: %f\n", game->wall_dist);
	printf("map_x		: %d\n", game->map_x);
	printf("map_y		: %d\n", game->map_y);
	printf("player_x	: %f\n" , game->player_x);
	printf("player_y	: %f\n", game->player_y);
	printf("draw_start	: %d\n", game->draw_start);
	printf("draw_end	: %d\n", game->draw_end);
	printf("ray_dy		: %f\n", game->ray_dy);
	printf("wall_x		: %f\n", game->wall_x);
	printf("===================== wall_height end====================\n");
}

void	wall_height(t_cube *game)
{
	if (game->side == 0)
		game->wall_dist = (game->map_x - game->player_x + (1 - game->step_x) / 2) / game->ray_dir_x;
	else
		game->wall_dist = (game->map_y - game->player_y + (1 - game->step_y) / 2) / game->ray_dir_y;

	game->line_height = (int)(WINDOW_HEIGHT / game->wall_dist);

	game->draw_start = -game->line_height / 2 + WINDOW_HEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;

	game->draw_end = game->line_height / 2 + WINDOW_HEIGHT / 2;
	if (game->draw_end >= WINDOW_HEIGHT)
		game->draw_end = WINDOW_HEIGHT - 1;

	if (game->side == 0)
		game->wall_x = game->player_y + game->wall_dist * game->ray_dy;
	else
		game->wall_x = game->player_x + game->wall_dist * game->ray_dx;
	game->wall_x -= floor(game->wall_x);
	wall_heightPrintf(game);
}
void castingPrintf(t_cube *game){
	printf("===================== wall_height function====================\n");
	printf("fov_ratio	: %f\n", game->fov_ratio);
	printf("dir_x	: %f\n", game->dir_x);
	printf("dir_y		: %f\n", game->dir_y);
	printf("map_y		: %d\n", game->map_y);
	printf("player_x	: %f\n" , game->player_x);
	printf("player_y	: %f\n", game->player_y);
	printf("cam_x	: %f\n", game->cam_x);
	printf("cam_y	: %f\n", game->cam_y);
	printf("===================== wall_height end====================\n");
}

void	casting(t_cube *game)
{
	castingPrintf(game);
	game->fov_ratio = 2 * game->x / (double)game->wind_width;
	game->ray_dx = game->dir_x + game->cam_x * game->fov_ratio;
	game->ray_dy = game->dir_y + game->cam_y * game->fov_ratio;
	game->map_x = (int)game->player_x;
	game->map_y = (int)game->player_y;
	dist_calc(game);
	step(game);
	dda(game);
	prepare_for_drawing(game);
	prepare_for_texture(game);
	// printf("== DEBUG SEGGGGG RAYCAST->CASTING 1.0 ==\n");
	draw_textured_walls(game);
	// printf("== DEBUG SEGGGGG RAYCAST->CASTING 1.1 ==\n");

}


