/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:52:36 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:52:37 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

/**
 * @brief  Return the position of the map in the file_data
 * @note   TODO: make sure this function is valid and don't need more...
 * @param  file_data:
 * @retval
 */
int	ft_find_map_position(char **file_data)
{
	int	i;

	i = 0;
	while (file_data[i])
	{
		if (file_data[i][0] && ft_str_made_of_set(file_data[i], "\t 1"))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	map_in_bounds(int **map, int x, int y)
{
	if (x >= 0 && y >= 0 && map[y][x])
		return (1);
	return (-1);
}
