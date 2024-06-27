
#include "cube.h"

int		map_height(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		i++;
	}
	return(i);
}

void	game(t_info_file *info)
{
	t_mini_map	game;

	printf("=== TEST 1 ===\n");
	game = ft_mini(info);
	color_background(game);
	set_minimap(game);
	// recasting
	mlx_key_hook(game.mlx, &ft_player_moves, &game);
	mlx_loop(game.mlx);
	return ;
}

int	main(int ac, char **av)
{
	t_info_file *info;

	if (ac != 2)
		return(0);
	info = init_info();
	valide_map(av[1]);
	game(info);
}
