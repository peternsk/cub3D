/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:13:49 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/17 10:58:30 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

bool	ft_arr_cpy(t_mini_map *game)
{
	int	i;

	i = 0;
	game->map = (char **)calloc(game->height + 1, sizeof(char *));
	if (!game->map)
		return (false);
	while (i < game->height)
	{
		game->map[i] = ft_strdup(game->map[i]);
		i++;
	}
	game->map[i] = NULL;
	return (true);
}
