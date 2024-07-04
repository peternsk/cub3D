/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:13:49 by pnsaka            #+#    #+#             */
/*   Updated: 2024/07/04 09:21:26 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	ft_arr_cpy(t_cube *game)
{
	int	i;

	i = 0;
	game->map = (char **)calloc(game->mini_height + 1, sizeof(char *));
	if (!game->map)
		return (false);
	while (i < game->mini_height)
	{
		game->map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
	return (true);
}
