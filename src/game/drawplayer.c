/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:21:34 by pnsaka            #+#    #+#             */
/*   Updated: 2024/10/24 14:15:31 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_point     init_point(int x, int y)
{
    t_point out;
    
    out.x = x;    
    out.y = y;
    return (out);    
}


void    init_lh_point(t_lh_point *line_data, t_point *p1, t_point *p2)
{
    line_data->dx = abs(p2->x - p1->x);
	if (p1->x < p2->x)
		line_data->sx = 1;
	else
		line_data->sx = -1;
	line_data->dy = -abs(p2->y - p1->y);
	if (p1->y < p2->y)
		line_data->sy = 1;
	else
		line_data->sy = -1;
	line_data->err = line_data->dx + line_data->dy;
	line_data->x = p1->x;
	line_data->y = p1->y;
}

void	draw_line(mlx_image_t *img, t_point p1, t_point p2, int color)
{
	t_lh_point	line_data;

	 init_lh_point(&line_data, &p1, &p2);
	while (1)
	{
		mlx_put_pixel(img, line_data.x, line_data.y, color);
		if ((line_data.x == p2.x) && (line_data.y == p2.y))
			break ;
		line_data.e2 = 2 * line_data.err;
		if (line_data.e2 >= line_data.dy)
		{
			line_data.err += line_data.dy;
			line_data.x += line_data.sx;
		}
		if (line_data.e2 <= line_data.dx)
		{
			line_data.err += line_data.dx;
			line_data.y += line_data.sy;
		}
	}
}

void set_tile_size(t_cube *rc)
{
    int tile_size_x;
    int tile_size_y;
    tile_size_x = (WINDOW_HEIGHT / 2) / rc->mini_width;
    tile_size_y = (WINDOW_WIDTH / 2) / rc->mini_height;
    if (tile_size_x < tile_size_y)
        rc->tile_size = tile_size_x;
    else
        rc->tile_size = tile_size_y;
    if (rc->tile_size < 3)
        rc->tile_size = -1;
}

void	draw_triangle(mlx_image_t *image, t_point points[3], uint32_t color)
{
	draw_line(image, points[0], points[1], color);
	draw_line(image, points[1], points[2], color);
	draw_line(image, points[2], points[0], color);

}

// Draws a triangle as the player on the minimap.
void	draw_player_triangle(t_cube *game, int color)
{
	t_point	points[3];

	points[0] = init_point(game->player_x * game->tile_size - game->dir_y * (game->tile_size / 4),
			game->player_y * game->tile_size + game->dir_x * (game->tile_size / 4));
	points[1] = init_point(game->player_x * game->tile_size + game->dir_x * (game->tile_size / 2),
			game->player_y * game->tile_size + game->dir_y * (game->tile_size / 2));
	points[2] = init_point(game->player_x * game->tile_size + game->dir_y * (game->tile_size / 4),
			game->player_y * game->tile_size - game->dir_x * (game->tile_size / 4));
	
	draw_triangle(game->minimap, points, color);
}

// Draws the player on the minimap with a direction vector.
void	draw_player(t_cube *game)
{
	// printf("DRAW PLAYER\n");
	draw_player_triangle(game,YELLOW);
	// printf("DRAW PLAYER 1\n");
	draw_line(game->minimap, init_point(game->player_x * game->tile_size, game->player_y
			* game->tile_size), init_point(game->player_x * game->tile_size + game->dir_x
			* (game->tile_size), game->player_y * game->tile_size + game->dir_y * (game->tile_size)), RED);
	draw_line(game->minimap, init_point(game->player_x * game->tile_size,
			game->player_y * game->tile_size), 
			init_point((game->map_x + game->player_x) * game->tile_size, 
			(game->map_y + game->player_y) * game->tile_size), 
			LIGHT_ORANGE);
}






