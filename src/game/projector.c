/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:53:11 by peternsaka        #+#    #+#             */
/*   Updated: 2024/09/28 17:38:36 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	raycast(t_cube *game)
{
	game->x = 0;
	while (game->x < game->wind_width)
	{
	// 	// printf("== DEBUG SEGGGGG RAYCAST 1.%d ==\n", game->x);
		casting(game);
	// 	// printf("== DEBUG SEGGGGG RAYCAST 1.2 ==\n");
		game->x++;
	}
	
}
