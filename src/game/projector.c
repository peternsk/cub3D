/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:53:11 by peternsaka        #+#    #+#             */
/*   Updated: 2024/09/25 12:49:11 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycast(t_cube *game)
{
	game->x = 0;
	// printf("== DEBUG SEGGGGG RAYCAST 1.1 ==\n");
	while (game->x < game->wind_width)
	{
		// printf("== DEBUG SEGGGGG RAYCAST 1.%d ==\n", game->x);
		casting(game);
		// printf("== DEBUG SEGGGGG RAYCAST 1.2 ==\n");
		game->x++;
	}
}
