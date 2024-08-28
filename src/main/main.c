
#include "cube.h"

void	game(t_info_file *info)
{
	t_cube	*game;
	int		x;
	int		y;

	x = 0;
	y = 0;
	game = ft_mini(info);
	background(game);
	printf("\n------The seg is in the function set_minimap_title i think----\n");
	set_minimap_tile(game);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	mlx_image_to_window(game->mlx, game->minimap, 0, 0);
	// // mlx_key_hook(game->mlx, &ft_player_moves, &game);
	mlx_loop(game->mlx);
	printf("???????\n");
	return ;
}

int	main(int ac, char **av)
{
	t_info_file	*info;

	if (ac != 2)
		return (err("Error\ncub3d has no arguments\n"), 0);
	info = init_info();
	info = valide_map(av[1]);
	game(info);
}
