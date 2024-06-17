/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 00:42:07 by pnsaka            #+#    #+#             */
/*   Updated: 2024/06/16 22:25:38 by peternsaka       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int argc, char **argv)
{
	t_game		*game;
	int			fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (EXIT_FAILURE);
		game = init_game(argv[1]);
		game->mlx = mlx_init((game->width * 64), (game->height * 64), "CUBE 3D", false);
		if (!game->mlx)
		{
			puts(mlx_strerror(mlx_errno));
			return (EXIT_FAILURE);
		}
	}
}
