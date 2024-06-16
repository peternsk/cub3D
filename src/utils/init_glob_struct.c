/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_glob_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/16 00:49:45 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_game	*init_game(char *file_path)
{
	t_game	*game;

	game = malloc(1 * sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = 0;
	game->height = ft_count_line(file_path);
	game->width = 0;
	game->map = 0;
	game->mlx = NULL;
	return (game);
}
