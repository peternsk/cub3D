/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:08:03 by pnsaka            #+#    #+#             */
/*   Updated: 2024/07/06 03:19:24 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rect_data	init_rect(int x, int y, int w, int h)
{
	t_rect_data	rectangle;

	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	return (rectangle);
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

void	minimap_tile(t_cube *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		set_rectangle(game->minimap, init_rect(x * 10 + 1, y * 10 + 1, 10 - 2,
				10 - 2), get_rgba(255, 255, 255, 255));
		printf("1");
	}
	else if (game->map[y][x] == '0')
	{
		set_rectangle(game->minimap, init_rect(x * 10 + 1, y * 10 + 1, 10 - 2,
				10 - 2), get_rgba(0, 0, 0, 255));
		printf("0");
	}
	else
	{
		set_rectangle(game->minimap, init_rect(x * 10 + 1, y * 10 + 1, 10 - 2,
				10 - 2), get_rgba(100, 100, 100, 255));
		printf("X");
	}
}

void	put_player(t_cube *game)
{
	set_rectangle(game->playr, init_rect(game->plane_x * 10 + 1, game->plane_y * 10 + 1, 10 - 2,
				10 - 2), get_rgba(281, 0, 0, 255));
}

void	set_minimap_tile(t_cube *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->mini_height)
	{
		x = 0;
		while (x < game->mini_width)
		{
			minimap_tile(game, x, y);
			x++;
		}
		printf("\n");
		y++;
	}
	put_player(game);
}
