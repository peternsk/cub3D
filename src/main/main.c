
#include "cube.h"

void	key_hook(t_cube *game)
{
	mlx_t	*mlx;
	double	move_x;
	double	move_y;

	mlx = game->mlx;
	move_x = game->mspeed * game->player_x;
	move_y = game->mspeed * game->player_y;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		move_up(game);

	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		move_down(game);
		// move_player(game, -move_x, -move_y);

	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotate_player(game, -1.05);
		// move_left(game);

	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotate_player(game, 1.05);
		// move_right(game);
		// move_player(game, -move_y, move_x);
}

// void 	key_hook(t_cube *game)
// {
// 	mlx_t *mlx;

// 	mlx = game->mlx;
// 	// printf("== SEG 1 ==\n");
// 	// printf("== MLX EXIST?: %s==\n", game->mlx?"yes":"no");
// 	// printf("== MLX width: %d==\n", mlx->width);
// 	// printf("== MLX height: %d==\n", mlx->height);
// 	// printf("== MLX delta_time: %f==\n", mlx->delta_time);
// 	// printf("== MLX VALUE: %s==\n", mlx_is_key_down(mlx, MLX_KEY_ESCAPE)?"true":"false");
// 	// printf("== SEG 1.1.1 ==\n");

// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 	{
// 		mlx_close_window(mlx);
// 	}
// 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// 		rotate_player(game, -0.05);
// 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// 		rotate_player(game, 0.05);
// 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// 		move_up(game);
// 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// 		move_down(game);
// }
void	ft_print_array(char **arr)
{
	int	i;

	i = 0;
	write(1, "[\n", 2);
	while (arr[i])
	{
		write(1, "\t", 1);
		ft_putnbr_fd(i, 2);
		write(1, " [", 2);
		write(1, arr[i], ft_strlen(arr[i]));
		write(1, "]\n", 2);
		i++;
	}
	write(1, "]\n", 2);
}
// void castingPrintf(t_cube *game){
// 	printf("===================== casting function====================\n");
// 	printf("fov_ratio	: %f\n", game->fov_ratio);
// 	printf("dir_x		: %f\n", game->dir_x);
// 	printf("dir_y		: %f\n", game->dir_y);
// 	printf("map_y		: %d\n", game->map_y);
// 	printf("player_x	: %f\n" , game->player_x);
// 	printf("player_y	: %f\n", game->player_y);
// 	printf("cam_x		: %f\n", game->cam_x);
// 	printf("cam_y		: %f\n", game->cam_y);
// 	printf("game->x		: %d\n", game->x);
// 	printf("===================== casting end====================\n");
// }

void	game_loop(void *param)
{
	t_cube *game;

	game = param;
	if (game)
	{
		// printf("Game loop\n");
		raycast(game);
		// castingPrintf(game);
		key_hook(game);
	}else
		printf("NULL as hell\n");
	// set_minimap_tile(game);
}
void	game(t_info_file *info)
{
	t_cube	*game;
	int		x;
	int		y;

	game = ft_mini(info);
	// printf("== DEBUG SEGGGGG ok ft_mini ==\n");
	// printf(" BEFORE SEGG !!\n");
	load_textures(game);
	// printf(" AFTER SEGG !\n");
	background(game);
	// printf("== DEBUG SEGGGGG ok background ==\n");
	set_minimap_tile(game);
	// printf("== DEBUG SEGGGGG ok set_minimap ==\n");
	put_player(game);
	// printf("== DEBUG SEGGGGG ok putplayer ==\n");
	raycast(game);
	// printf("== DEBUG SEGGGGG ok raycast ==\n");
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	// printf("== DEBUG SEGGGGG ok background mlx ==\n");
	mlx_image_to_window(game->mlx, game->rayc_screen, 0, 0);
	// printf("== DEBUG SEGGGGG ok ray mlx ==\n");
	mlx_image_to_window(game->mlx, game->minimap, 0, 0);
	// printf("== DEBUG SEGGGGG ok minimap mlx ==\n");
	mlx_image_to_window(game->mlx, game->playr, game->player_x * 10, game->player_y * 10);
	// printf("== DEBUG SEGGGGG ok player mlx ==\n");
	mlx_loop_hook(game->mlx, game_loop, game);
	// void *param = (void *)game;
	// mlx_loop_hook(game->mlx, game_loop(game), game);
	// printf("== DEBUG SEGGGGG ok game loop mlx ==\n");
	if (game->mlx)
		mlx_loop(game->mlx);
	else
		printf("is not good\n");
	mlx_terminate(game->mlx);
	// printf("== DEBUG SEGGGGG ok mlx loop mlx ==\n");
	return ;
}

int	main(int ac, char **av)
{
	t_info_file	*info;

	if (ac != 2)
		return (err("Error\ncub3d has no arguments\n"), 2);
	// info = init_info(); // on pas vraiment besion
	info = valide_map(av[1]);
	if(!info)
		return(printf("WRONG MAP INIT\n"), 0);
	game(info);
	printf("== DEBUG SEGGGGG ==\n");
}
