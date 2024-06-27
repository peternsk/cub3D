/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/26 22:16:42 by pnsaka           ###   ########.fr       */
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

t_mini_map	*ft_mini(char *file_path)
{
	t_mini_map	*game;

	game = malloc(1 * sizeof(t_mini_map));
	if (!game)
		return (NULL);
	game->map = 0;
	game->player_x = 20;
	game->player_y = 20;
	game->player_dx = 0;
	game->player_dy = 0;
	game->player_a = 0;
	game->height = ft_count_line(file_path);
	game->width = 0;
	game->wind_height = WINDOW_HEIGHT;
	game->wind_width = WINDOW_WIDTH;
	game->mlx = NULL;
	return (game);
}
