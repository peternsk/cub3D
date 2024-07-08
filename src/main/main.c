
#include "cube.h"

static int	map_ratio_x(double pos_x)
{
	t_cube	*game;
	int		ratio_x;

	ratio_x = ((int)pos_x * (game->mini_width / game->wind_width));
	return (ratio_x);
}

static int	map_ratio_y(double pos_y)
{
	t_cube	*game;
	int		ratio_y;

	ratio_y = ((int)pos_y * (game->wind_height / game->mini_height));
	return (ratio_y);
}

void	game(t_info_file *info)
{
	t_cube	*game;
	int		x;
	int		y;

	game = ft_mini(info);
	x = map_ratio_x(game->player_x);
	y = map_ratio_y(game->player_y);
	background(game);
	set_minimap_tile(game);
	put_player(game);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	mlx_image_to_window(game->mlx, game->minimap, 0, 0);
	mlx_image_to_window(game->mlx, game->playr, x, y);
	// // mlx_key_hook(game->mlx, &ft_player_moves, &game);
	mlx_loop(game->mlx);
	printf("???????\n");
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
