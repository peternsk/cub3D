/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 10:08:03 by pnsaka            #+#    #+#             */
/*   Updated: 2024/07/04 10:48:47 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_rect_data	init_rect(int x, int y, int w, int h)
{
	t_rect_data	rectangle;

	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	return (rectangle);
}

void	set_rectangle(mlx_image_t *image, t_rect_data rect, int color)
{
	int	i;
	int	j;

	i = rect.x;
	while (i < rect.w + rect.x)
	{
		j = rect.y;
		while (j < rect.h + rect.y)
		{
			mlx_put_pixel(image, i, j, color);
			j++;
		}
		i++;
	}
}

