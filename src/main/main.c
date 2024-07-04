
#include "cube.h"

void	game(t_info_file *info)
{
	t_cube	*game;
	int x = 0;
	int y = 0;

	game = ft_mini(info);
	game->background = mlx_new_image(game->mlx, game->wind_width, game->wind_height);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	// background(game);
	// // mlx_key_hook(game->mlx, &ft_player_moves, &game);
	mlx_loop(game->mlx);
	return ;
}

int	main(int ac, char **av)
{
	t_info_file	*info;

	if (ac != 2)
		return (0);
	info = init_info();
	info = valide_map(av[1]);
	game(info);
}
