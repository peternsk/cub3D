/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:08:03 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/26 23:57:27 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rectangle	init_rectangle(int x, int y, int width, int height)
{
	t_rectangle	rec;

	rec.x = x;
	rec.y = y;
	rec.height = height;
	rec.width = width;
	return (rec);
}

void	draw_rectangle(mlx_image_t *image, t_rectangle rec, uint32_t color)
{
	int32_t	i;
	int32_t	j;

	i = rec.x;
	while (i < rec.width + rec.x)
	{
		j = rec.y;
		while (j < rec.height + rec.y)
		{
			mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

void	ft_load_png_utlis(t_mini_map *game, int x, int y)
{
	if (game->map[x][y] == '1')
	{
		draw_rectangle(game->background, init_rectangle(x, y, 8, 8),
			0x0000FFFF);
	}
	else if (game->map[x][y] == '0')
	{
		draw_rectangle(game->background, init_rectangle(x, y, 8, 8),
			0x00FF00FF);
	}
	else
	{
		draw_rectangle(game->background, init_rectangle(x, y, 8, 8),
			0x808080FF);
	}
}

void	ft_load_png(t_mini_map *game, t_load_pos *var)
{
	int	x;
	int	y;

	(void)var;
	y = 0;
	while (y < game->width)
	{
		x = 0;
		while (x < game->height)
		{
			printf("=== SEGFAULT %c ===\n", game->map[x][y]);
			ft_load_png_utlis(game, x, y);
			x++;
		}
		y++;
	}
	// put_player(game, var);
}

void	put_player(t_mini_map *game, t_load_pos *var)
{
	game->playr = mlx_new_image(game->mlx, 8, 8);
	ft_memset(game->playr->pixels, 255, 256);
	mlx_image_to_window(game->mlx, game->playr, game->player_x, game->player_y);
	game->line = mlx_new_image(game->mlx, 16, 6);
	ft_memset(game->line->pixels, 255, 128);
	mlx_image_to_window(game->mlx, game->line, game->player_x, game->player_y
		+ 3);
}
