/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:08:03 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/27 10:11:21 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rect_data		init_rect(int x, int y, int w, int h)
{
	t_rect_data rectangle;

	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	return(rectangle);
}


void	set_rectangle(mlx_image_t *image, t_rect_data rect, int color)
	{
	int	i;
	int	j;

	i = rect.x;
	while (i < rect.w + rect.x)
	{
		j = rect.y;
		while (j < rect.h + rect.y)
		{
			mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

void	minimap_tile(t_mini_map game, int x, int y)
{
	if (game.map[y][x] == 1)
	{
		set_rectangle(game.minimap, init_rect(x * 8 + 1, y
				* 8 + 1, 8 - 2, 8 - 2), get_rgba(255, 255, 255, 255));
	}
	else if (game.map[y][x] == 0)
	{
		set_rectangle(game.minimap, init_rect(x * 8 + 1, y
				* 8 + 1, 8 - 2, 8 - 2), get_rgba(0, 0, 0, 255));
	}
	// else
	// {
	// 	draw_rectangle(game.minimap, init_rectangle(x * game.tile_size, y
	// 			* game.tile_size, game.tile_size, game.tile_size), TRANSLUCENT);
	// }
}



void	set_minimap(t_mini_map game)
{
	int	x;
	int	y;

	// if (rc.tile_size == -1)
	// {
	// 	draw_rectangle(rc.minimap, init_rectangle(0, 0, rc.map_width
	// 			* rc.tile_size, rc.map_height * rc.tile_size), TRANSPARENT);
	// 	return ;
	// }
	set_rectangle(game.minimap, init_rect(0, 0, game.width * 8,
			game.height * 8), get_rgba(0, 0, 0, 255));
	x = 0;
	while (x < game.width)
	{
		y = 0;
		while (y < game.height)
		{
			minimap_tile(game, x, y);
			y++;
		}
		x++;
	}
	// draw_player(game);
}
