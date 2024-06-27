/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:58:27 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/27 10:36:32 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**ft_map_to_arr(t_mini_map game, int fd)
{
	int	i;

	i = -1;
	game.map = (char **)ft_calloc(game.height + 1, sizeof(char *));
	if (!game.map)
		return (0);
	while (++i < game.height)
	{
		game.map[i] = get_next_line(fd);
		if (ft_strlen(game.map[0]) == 0)
			return(0);
	}
	game.map[i] = NULL;
	if (ft_strlen(game.map[i - 1]) <= 1)
	{
		return (0);
	}
	return (game.map);
}
