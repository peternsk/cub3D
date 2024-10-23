/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/10/22 09:33:25 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static double	degree_to_radian(int a)
{
	return (a * M_PI / 180.0);
}

static void	init_player_position(t_cube *rc, t_info_file *game_info)
{
	rc->player_x = (double)game_info->push_p->pos_x + 0.5;
	rc->player_y = (double)game_info->push_p->pos_y + 0.5;
	rc->dir_x = 1;
	rc->dir_y = 0;
	if (game_info->push_p->side == nord)
		rotate_player(rc, degree_to_radian(-90));
	else if (game_info->push_p->side == east)
		rotate_player(rc, degree_to_radian(0));
	else if (game_info->push_p->side == south)
		rotate_player(rc, degree_to_radian(90));
	else if (game_info->push_p->side == west)
		rotate_player(rc, degree_to_radian(180));
}

int	ft_count_line(char *file_path)
{
	int		read_byte;
	char	c;
	int		line_num;
	int		fd;

	line_num = 1;
	read_byte = 1;
	fd = open(file_path, O_RDONLY);
	while (1)
	{
		read_byte = read(fd, &c, 1);
		if (read_byte <= 0)
			break ;
		if (c == '\n')
			line_num++;
	}
	close(fd);
	return (line_num);
}

t_cube	*ft_mini(t_info_file *info)
{
	t_cube	*game;

	game = malloc(sizeof(t_cube));
	if (!game)
		return (NULL);
	game->map = info->v_map;
	game->player_x = (double)info->push_p->pos_x + 0.5;
	game->player_y = (double)info->push_p->pos_y + 0.5;
	game->wind_height = WINDOW_HEIGHT;
	game->wind_width = WINDOW_WIDTH;
	game->mini_height = info->height;
	game->mini_width = info->width;
	set_tile_size(game);
	init_player_position(game, info);
	game->delta_x = 0;
	game->delta_y = 0;
	game->dir_x = 1;
	game->dir_y = 0;
	game->mspeed = 0.05;
	game->plane_x = 0;
	game->plane_y = 0.5 * ((double)game->wind_width / (double)game->wind_height);
	game->player_a = 0;
	load_textures(game);
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", true);
	if (!game->mlx)
	{
		printf("unable to initialize\n");
		return (NULL);
	}
	game->background = mlx_new_image(game->mlx, game->wind_width,
			game->wind_height);
	game->rayc_screen = mlx_new_image(game->mlx, game->wind_width,
			game->wind_height);
	game->minimap = mlx_new_image(game->mlx , game->mini_width * 10,
			game->mini_height * 10);
	return (game);
}
