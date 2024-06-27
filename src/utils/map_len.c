/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:19:47 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/27 11:45:33 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	max_len(int height, char **map)
{
	int max_len;
	int max_tmp;
	int i;
	int j;

	max_len = 0;
	max_tmp = 0;
	i = 0;
	j = 0;
	while (i < height)
	{
		max_tmp = ft_strlen(map[i]);
		if (max_tmp > max_len)
			max_len = max_tmp;
		i++;
	}
	return (max_len - 1);
}
