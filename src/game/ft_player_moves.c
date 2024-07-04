/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:58:42 by peternsaka        #+#    #+#             */
/*   Updated: 2024/07/04 09:21:26 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_player_moves(mlx_key_data_t keydata, void *param)
{
	t_cube	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		move_left(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		move_right(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_up(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_down(game);
}
