/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:39:40 by peternsaka        #+#    #+#             */
/*   Updated: 2024/10/24 14:43:45 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void 	step(t_cube *game)
{
	if (game->ray_dx < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->player_x - game->map_x) * game->delta_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->player_x) * game->delta_x;
	}
	if (game->ray_dy < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->player_y - game->map_y) * game->delta_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->player_y) * game->delta_y;
	}
	// stepPrintf(game);
}

void	dda(t_cube *game)
{
	int hit;
	
	hit = 0;
	while (hit == 0)
    {
        if (game->side_dist_x < game->side_dist_y)
        {
			// printf("**** HERE 1 ****\n");
          	game->side_dist_x += game->delta_x;
          	game->map_x += game->step_x;
          	game->side = 0;
        }
        else
        {
          	game->side_dist_y += game->delta_y;
          	game->map_y += game->step_y;
          	game->side = 1;
        }
        if (game->map[(int)game->map_y][(int)game->map_x] == '1') hit = 1;
    }
	if(game->side == 0)
		game->perp_dist = (game->side_dist_x - game->delta_x);
	else
		game->perp_dist = (game->side_dist_y - game->delta_y);
	draw_player(game);

}

void	dist_calc(t_cube *game)
{
	// printf("****************************\n");
	// printf("ray_dx : %f\n", game->ray_dx);
	// printf("ray_dy : %f\n", game->ray_dy);
	// printf("****************************\n");
	
	if (game->ray_dx == 0){
		// printf("ray dx if\n");
		game->delta_x = 1e30;
	}
	else{
		// printf("ray dx else\n");
		game->delta_x = fabs(1 / game->ray_dx);
	}
	if (game->ray_dy == 0){
		// printf("ray dy if\n");
		game->delta_y = 1e30;
	}
	else{
		// printf("ray dy if\n");
		game->delta_y = fabs(1 / game->ray_dy);
	}
	// printf("game->delta_x : %f\n", game->delta_x);
	// printf("game->delta_y : %f\n", game->delta_y);
	// printf("end\n");
}

void	wall_height(t_cube *game)
{
	if (game->side == 0)
		game->wall_dist = (game->map_x - game->player_x + (1 - (double)game->step_x) / 2) / game->ray_dx;
	else
		game->wall_dist = (game->map_y - game->player_y + (1 - (double)game->step_y) / 2) / game->ray_dy;

	game->line_height = (int)(WINDOW_HEIGHT / (int)game->wall_dist);

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
}

void	casting(t_cube *game)
{
	// printf("casting loop\n");
	game->cam_x = 2 * game->x / (double)game->wind_width - 1;
	game->ray_dx = game->dir_x + game->plane_x * game->cam_x;
	game->ray_dy = game->dir_y + game->plane_y * game->cam_x;
	game->map_x = game->player_x + 0.5;
	game->map_y = game->player_y + 0.5;
	// castingPrintf(game);
	dist_calc(game);
	// printf("SEG 1\n");
	step(game);
	// printf("SEG 2\n");
	dda(game);
	// printf("SEG 3\n");
	wall_height(game);
	// printf("SEG 4\n");
	prepare_for_texture(game);
	// printf("SEG 5\n");
	prepare_for_drawing(game);
	// printf("SEG 6\n");
	draw_textured_walls(game);
	// printf("SEG 7\n");
}


