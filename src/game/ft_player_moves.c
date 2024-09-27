/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:58:42 by peternsaka        #+#    #+#             */
/*   Updated: 2024/07/09 23:31:25 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_player_moves(void *param)
{
	mlx_key_data_t keydata;
	t_cube	*game;
	mlx_t *mlx;

	game = param;
	mlx = game->mlx;
	printf("== SEG 1 ==\n");
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotate_player(game, -0.05);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotate_player(game, 0.05);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		move_up(game);	
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		move_down(game);
}


