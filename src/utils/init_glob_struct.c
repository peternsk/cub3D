/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_glob_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:44:22 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/16 22:17:09 by peternsaka       ###   ########.fr       */
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

t_game	*init_game(char *file_path)
{
	t_game	*game;

	game = malloc(1 * sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = 0;
	game->height = ft_count_line(file_path);
	game->width = 0;
	game->player_x = 0;
	game->player_x = 0;
	game->map = 0;
	game->mlx = NULL;
	return (game);
}
