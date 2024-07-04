/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:15:23 by pnsaka            #+#    #+#             */
/*   Updated: 2024/07/04 09:21:26 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	create_background_celling(t_cube *game)
{
	game->background = mlx_new_image(game->mlx, game->wind_width, game->wind_height);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
}

void	background(t_cube *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < game->wind_height / 2)
	{
		while (++j < game->wind_width)
			mlx_put_pixel(game->background, j, i, get_rgba(14, 19, 50, 255));
		j = -1;
	}
	while (++i < game->wind_height)
	{
		j = -1;
		while (++j < game->wind_width)
			mlx_put_pixel(game->background, j, i, get_rgba(7, 49, 35, 255));
	}
	printf("== [HERE 1] ==\n");
}
