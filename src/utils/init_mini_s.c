/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/27 11:47:00 by peternsaka       ###   ########.fr       */
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

t_mini_map	ft_mini(t_info_file *info)
{
	t_mini_map	game;

	game.map = info->v_map;
	game.player_x = 0;
	game.player_y = 0;
	game.player_dx = 0;
	game.player_dy = 0;
	game.player_a = 0;
	game.height = map_height(info->v_map);
	game.width = max_len(game.height, game.map);
	game.wind_height = WINDOW_HEIGHT;
	game.wind_width = WINDOW_WIDTH;
	game.mlx = mlx_init(game.wind_width, game.wind_height, "cub3D", true);
	if (!game.mlx)
		printf("unable to initialize\n");
	return (game);
}
