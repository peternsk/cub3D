/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:37:20 by peternsaka        #+#    #+#             */
/*   Updated: 2024/09/26 12:47:58 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	prepare_for_drawing(t_cube *game)
{
	// printf("== DEBUG SEGGGGG PREP DRAW start ==\n");
	game->line_height = (int)(game->wind_height / game->perp_dist);
	game->draw_start = -game->line_height / 2 + game->wind_height / 2
		+ game->vert_view;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->wind_height / 2
		+ game->vert_view;
	if (game->draw_end >= game->wind_height)
		game->draw_end = game->wind_height - 1;
	if (game->side == 0)
		game->wall_x = game->player_y + game->perp_dist * game->ray_dy;
	else
		game->wall_x = game->player_x + game->perp_dist * game->ray_dx;
	game->wall_x -= floor((game->wall_x));
	// printf("== DEBUG SEGGGGG PREP DRAW end ==\n");
}

void	prepare_for_texture(t_cube *game)
{
	if (game->side == 0 && game->ray_dx < 0)
		game->tex_num = 0;
	if (game->side == 0 && game->ray_dx > 0)
		game->tex_num = 1;
	if (game->side == 1 && game->ray_dy < 0)
		game->tex_num = 2;
	if (game->side == 1 && game->ray_dy > 0)
		game->tex_num = 3;
	game->tex = game->textures[game->tex_num];
	game->tex_x = (int)(game->wall_x * (double)(game->tex->width));
	if (game->side == 0 && game->ray_dx > 0)
		game->tex_x = game->tex->width - game->tex_x - 1;
	if (game->side == 1 && game->ray_dy < 0)
		game->tex_x = game->tex->width - game->tex_x - 1;
	game->tex_step = (double)game->tex->height / (double)game->line_height;
	game->tex_pos = (game->draw_start - game->vert_view - game->wind_height / 2
			+ game->line_height / 2) * game->tex_step;
}

int32_t	get_texture_color(u_int8_t *pixel)
{
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

void	draw_textured_walls(t_cube *game)
{
	// printf("== DEBUG SEGGGGG PREP DRAW start ==\n");
	game->y = 0;
	while (game->y < game->draw_start)
	{
		// printf("== DEBUG SEGGGGG PREP DRAW mid 1 ==\n");
		mlx_put_pixel(game->background, game->x, game->y, 0);
		// printf("== DEBUG SEGGGGG PREP DRAW mid 2 ==\n");
		game->y++;
	}
	while (game->y < game->draw_end)
	{
		game->tex_y = (int)game->tex_pos;
		game->tex_pos += game->tex_step;
		game->color = get_texture_color(&game->tex->pixels[(game->tex->width
					* game->tex_y + (game->tex->width - game->tex_x - 1)) * 4]);
		mlx_put_pixel(game->background, game->x, game->y, game->color);
		game->y++;
	}
	while (game->y < game->wind_height)
	{
		mlx_put_pixel(game->background, game->x, game->y, 255);
		game->y++;
	}
	// printf("== DEBUG SEGGGGG PREP DRAW end ==\n");
}

//set texture
void	load_textures(t_cube *game)
{
	// game->textures[0] = load_png(game->info->w_tex);
	// game->textures[1] = load_png(game->info->e_tex);
	// game->textures[2] = load_png(game->info->n_tex);
	// game->textures[3] = load_png(game->info->s_tex);

	game->textures[0] = load_png("./texture/Wall1.png");
	game->textures[1] = load_png("./texture/Wall2.png");
	game->textures[2] = load_png("./texture/Wall3.png");
	game->textures[3] = load_png("./texture/Wall4.png");
}
static int	throw_error_detail(char *error, char *msg, int exit_code)
{
	printf("Error\n%s\n", error);
	if (msg)
		printf("-> [%s]\n", msg);
	if (exit_code >= 0)
		exit(exit_code);
	return (1);
}

mlx_texture_t	*load_png(char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		throw_error_detail("Failed to load texture", path, 1);
	return (texture);
}
