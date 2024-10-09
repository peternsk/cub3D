
#include "cube.h"

static void	move_player(t_cube *rc, double move_x, double move_y)
{
	if (rc->map[(int)rc->player_y][(int)(rc->player_x + move_x)] == '0')
		rc->player_x += move_x;
	if (rc->map[(int)(rc->player_y + move_y)][(int)rc->player_x] == '0')
		rc->player_y += move_y;
}

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
		move_player(game, move_x, -move_y);
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		move_player(game, -move_x, move_y);
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		rotate_player(game, -0.05);
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		rotate_player(game, 0.05);
}

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
		key_hook(game);
		set_minimap(game);
		raycast(game);
		draw_player(game);
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
	load_textures(game);
	background(game);
	set_minimap_tile(game);
	// put_player(game);
	draw_player(game);
	raycast(game);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	mlx_image_to_window(game->mlx, game->rayc_screen, 0, 0);
	mlx_image_to_window(game->mlx, game->minimap, 0, 0);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
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
