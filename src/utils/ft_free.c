/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:01:34 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/17 11:34:03 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_free_2d_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_delete_image(t_mini_map *game)
{
	int	i;

	i = 0;
	while (i < NUM_OF_IMAGE)
	{
		mlx_delete_image(game->mlx, game->arr_img[i]);
		i++;
	}
}

void	ft_delete_texture(t_mini_map *game)
{
	int	i;

	i = 0;
	while (i < NUM_OF_IMAGE)
	{
		mlx_delete_texture(game->arr_txtur[i]);
		i++;
	}
}

int	ft_free_f(t_mini_map *game, char *error_msg)
{
	if (game->mlx)
	{
		if (sizeof(game->arr_img) < 0)
			ft_delete_image(game);
		if (sizeof(game->arr_txtur) < 0)
			ft_delete_texture(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		free(game->mlx);
	}
	if (game->map)
		ft_free_2d_map(game->map);
	free(game);
	if (error_msg == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		ft_putendl_fd(error_msg, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
