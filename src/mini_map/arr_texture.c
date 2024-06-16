/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:17:38 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/16 00:31:19 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_arr_texture(t_game *game)
{
	game->arr_txtur[WALL] = mlx_load_png("./images/mini_map_wall.png");
	game->arr_txtur[FLOOR] = mlx_load_png("./images/mini_map_floor.png");
	if (!game->arr_txtur[WALL] || !game->arr_txtur[FLOOR])
		ft_free_f(game, "error");
}

void	ft_texture_to_image(t_game *game)
{
	game->arr_img[WALL] = mlx_texture_to_image(game->mlx,
			game->arr_txtur[WALL]);
	game->arr_img[FLOOR] = mlx_texture_to_image(game->mlx,
			game->arr_txtur[FLOOR]);
	if (!game->arr_img[WALL] || !game->arr_img[FLOOR])
		ft_free_f(game, "error");
}

void	ft_load_png_utlis(t_game *game, t_load_pos *var)
{
	if (game->map[var->i][var->j] == '1')
		mlx_image_to_window(game->mlx, game->arr_img[WALL], var->x, var->y);
	else if (game->map[var->i][var->j] == '0')
		mlx_image_to_window(game->mlx, game->arr_img[FLOOR], var->x, var->y);
}

void	ft_load_png(t_game *game, t_load_pos *var)
{
	int	p_x;
	int	p_y;

	var->i = -1;
	var->j = -1;
	while (++var->i < game->height)
	{
		while (++var->j < game->width)
		{
			ft_load_png_utlis(game, var);
			if (game->map[var->i][var->j] == 'P')
			{
				mlx_image_to_window(game->mlx, game->arr_img[FLOOR], var->x,
					var->y);
				p_x = var->x;
				p_y = var->y;
			}
			var->x = var->x + 64;
		}
		var->j = -1;
		var->x = 0;
		var->y = var->y + 64;
	}
	// mlx_image_to_window(game->mlx, game->arr_img[PLAYER], p_x, p_y);
}

void	ft_player_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up(game);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_down(game);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_right(game);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left(game);
}
