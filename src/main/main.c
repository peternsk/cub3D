/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:42:07 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/17 11:48:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_mini_map	*game;
	t_load_pos	var;

	var.i = 0;
	var.j = 0;
	var.x = 0;
	var.y = 0;

	
	
	game = NULL;
	game = ft_mini();
	game->mlx = mlx_init(game->height, game->width, "CUBE 3D", true);
	if (!game->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	ft_arr_texture(game);
	ft_texture_to_image(game);
	ft_load_png(game, &var);
	mlx_key_hook(game->mlx, &ft_player_moves, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

