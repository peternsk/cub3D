/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:52:44 by peternsaka        #+#    #+#             */
/*   Updated: 2024/12/30 14:52:45 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// Redifinition of mlx functions with error catching

#include "../../includes/cub3d.h"

mlx_image_t	*new_image(mlx_t *mlx, int width, int height)
{
	mlx_image_t	*image;

	image = mlx_new_image(mlx, width, height);
	if (!image)
		throw_error("Failed to initialize image", 1);
	return (image);
}

void	image_to_window(mlx_t *mlx, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
		throw_error("Failed to put image to window", 1);
}

void	put_pixel(mlx_image_t *image, int x, int y, uint32_t color)
{
	if (x < 0 || x >= (int)image->width || y < 0 || y >= (int)image->height)
		return ;
	mlx_put_pixel(image, x, y, color);
}

mlx_texture_t	*load_png(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		throw_error_detail("Failed to load texture", path, 1);
	return (texture);
}
