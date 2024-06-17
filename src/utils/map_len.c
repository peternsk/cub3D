/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:19:47 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/17 16:36:20 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	max_len(t_mini_map *game)
{
	int max_len;
	int max_tmp;
	int i;
	int j;

	max_len = 0;
	max_tmp = 0;
	i = 0;
	j = 0;
	while (i < game->height)
	{
		max_tmp = ft_strlen(game->map[i]);
		if (max_tmp > max_len)
			max_len = max_tmp;
		i++;
	}
	return (max_len);
}
