/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:15:23 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/20 00:30:57 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	create_background_celling(t_mini_map *game)
{
	ft_memset(game->celling->pixels, 255, game->wind_width * game->wind_height
		/ 2 * BPP);
	mlx_image_to_window(game->mlx, game->celling, 0, 0);
}

void	create_background_floor(t_mini_map *game)
{
	ft_memset(game->floor->pixels, 255, game->wind_width * game->wind_height / 2
		* BPP);
	mlx_image_to_window(game->mlx, game->celling, 0, game->wind_height / 2);
}

void	color_background(t_mini_map *game)
{
	int	i;

	i = 0;
	create_background_celling(game);
	create_background_floor(game);
	while (i < game->wind_height / 2)
	{
		mlx_put_pixel(game->celling, 0, 0, get_rgba(135, 206, 235, 0));
		i++;
	}
	while (i >= game->wind_height / 2)
	{
		mlx_put_pixel(game->celling, 0, game->wind_height / 2, get_rgba(135,
				206, 235, 0));
		i++;
	}
}
