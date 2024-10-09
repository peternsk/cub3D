/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/10/09 14:35:52 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

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
	printf(" pos x: %f, pos y: %f \n", game->player_x, game->player_y);
	game->player_x = (double)info->push_p->pos_x;
	game->player_y = (double)info->push_p->pos_y;
	printf(" pos x: %d, pos y: %d \n",  info->push_p->pos_x, info->push_p->pos_y);
	printf(" pos x: %f, pos y: %f \n", game->player_x, game->player_y);
	game->delta_x = 0;
	game->delta_y = 0;
	game->dir_x = 1;
	game->dir_y = 0;
	game->mspeed = 0.05;
	game->plane_x = 0;
	game->wind_height = WINDOW_HEIGHT;
	game->wind_width = WINDOW_WIDTH;
	game->plane_y = 0.5 * ((double)game->wind_width / (double)game->wind_height);
	game->player_a = 0;
	game->mini_height = info->height;
	game->mini_width = info->width;
	printf(" BEFORE SEGG !!\n");
	load_textures(game);
	printf(" AFTER SEGG !!\n");
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
