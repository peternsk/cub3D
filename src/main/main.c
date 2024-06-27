
#include "cube.h"

void	game_on(void *param)
{
	t_load_pos		var;
	mlx_key_data_t	keydata;
	t_mini_map		*game;

	game = param;
	var.i = 0;
	var.j = 0;
	var.x = 0;
	var.y = 0;
	ft_load_png(game, &var);
	printf("=== SEGFAULT 132 ===\n");
	ft_player_moves(keydata, game);
}

int	main(int ac, char **av)
{
	t_mini_map	*game;
	int			fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (EXIT_FAILURE);
		game = ft_mini(av[1]);
		ft_map_to_arr(game, fd);
		game->width = max_len(game);
		game->mlx = mlx_init(game->wind_width, game->wind_height, "CUBE 3D",
				true);
		if (!game->mlx)
		{
			puts(mlx_strerror(mlx_errno));
			return (EXIT_FAILURE);
		}
		game->minimap = mlx_new_image(game->mlx, game->width * 8, game->height * 8);
		mlx_image_to_window(game->mlx, game->minimap, 0 , 0);
		color_background(game);
		mlx_loop_hook(game->mlx, game_on, game);
		mlx_loop(game->mlx);
		return (EXIT_SUCCESS);
	}
}
