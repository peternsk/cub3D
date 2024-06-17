/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:08:03 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/17 16:37:49 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_arr_texture(t_mini_map *game)
{
	game->arr_txtur[WALL] = mlx_load_png("./images/mini_map_wall.png");
	game->arr_txtur[FLOOR] = mlx_load_png("./images/mini_map_floor.png");
	game->arr_txtur[PLAYER] = mlx_load_png("./images/mini_map_player.png");
	if (!game->arr_txtur[WALL] || !game->arr_txtur[FLOOR]
		|| !game->arr_txtur[PLAYER])
		ft_free_f(game, "error");
}

void	ft_texture_to_image(t_mini_map *game)
{
	game->arr_img[WALL] = mlx_texture_to_image(game->mlx,
			game->arr_txtur[WALL]);
	game->arr_img[FLOOR] = mlx_texture_to_image(game->mlx,
			game->arr_txtur[FLOOR]);
	game->arr_img[PLAYER] = mlx_texture_to_image(game->mlx,
			game->arr_txtur[PLAYER]);
	if (!game->arr_img[WALL] || !game->arr_img[FLOOR] || !game->arr_img[PLAYER])
		ft_free_f(game, "error");
}

void	ft_load_png_utlis(t_mini_map *game, t_load_pos *var)
{
	if (game->map[var->i][var->j] == '1')
		mlx_image_to_window(game->mlx, game->arr_img[WALL], var->x, var->y);
	else if (game->map[var->i][var->j] == '0')
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], var->x, var->y);
}

void	ft_load_png(t_mini_map *game, t_load_pos *var)
{
	int	p_x;
	int	p_y;

	var->i = -1;
	var->j = -1;
	while (++var->i < game->height)
	{
		printf("=== [width %d] ===\n", game->width);
		while (++var->j < game->width)
		{
			printf("=== [ var j ] ===\n");
			ft_load_png_utlis(game, var);
			var->x = var->x + 16;
		}
		var->j = -1;
		var->x = 0;
		var->y = var->y + 16;
	}
	printf("=== [ ft_texture_to_image ] ===\n");
	game->playr = mlx_new_image(game->mlx, 8, 8);
	ft_memset(game->playr->pixels, 255, 128);
	mlx_image_to_window(game->mlx, game->playr, 20, 20);
}
