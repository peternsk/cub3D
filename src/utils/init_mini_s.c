/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/07/04 09:21:26 by peternsaka       ###   ########.fr       */
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

  	game = malloc(sizeof(t_info_file));
    if (!game)
        return (NULL);
	game->map = info->v_map;
	game->player_x = info->push_p->pos_x;
	game->player_y = info->push_p->pos_x;
	game->delta_x = 0;
	game->delta_y = 0;
	game->player_a = 0;
	game->mini_height = info->height;
	game->mini_width = info->width;
	game->wind_height = WINDOW_HEIGHT;
	game->wind_width = WINDOW_WIDTH;
	game->mlx = mlx_init(game->wind_width, game->wind_height, "cub3D", true);;
	if (!game->mlx)
		printf("unable to initialize\n");
	return (game);
}
