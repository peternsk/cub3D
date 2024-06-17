/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/17 16:31:42 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#define MAP_SIZE 10

typedef enum s_mm_images
{
	PLAYER,
	FLOOR,
	WALL,
	NUM_OF_IMAGE
}					t_mm_images;


typedef struct s_load_pos
{
	int				i;
	int				j;
	int				x;
	int				y;
}					t_load_pos;

typedef struct s_mini_map
{
	char			**map;
	int				player_x;
	int				player_y;
	int				height;
	int				width;
	mlx_texture_t	*arr_txtur[NUM_OF_IMAGE];
	mlx_image_t		*arr_img[NUM_OF_IMAGE];
	mlx_image_t		*playr;
	mlx_t			*mlx;
	mlx_key_data_t	keydata;
}					t_mini_map;

typedef struct s_game
{
	char			**map;
}					t_game;

/*====================================================*/
/*=                     mini_map                     =*/
/*====================================================*/

int					ft_count_line(char *file_path);

//utils
bool				ft_map_to_arr(t_mini_map *game, int fd);
int					ft_count_line(char *file_path);
void				ft_p_position(t_mini_map *game);
void				ft_ext_position(t_mini_map *game);
bool				ft_arr_cpy(t_mini_map *game);
void				ft_flood_fill(int x, int y, t_mini_map *game);

//mlx
void				ft_load_png(t_mini_map *game, t_load_pos *var);
void				ft_load_png_utlis(t_mini_map *game, t_load_pos *var);
void				ft_arr_texture(t_mini_map *image);
void				ft_texture_to_image(t_mini_map *game);
void				ft_player_moves(mlx_key_data_t keydata, void *param);

//player move
bool				move_check(t_mini_map *game, int x, int y);
void				move_up(t_mini_map *game);
void				move_down(t_mini_map *game);
void				move_left(t_mini_map *game);
void				move_right(t_mini_map *game);

//assembled functions
t_mini_map			*ft_mini(char *file_path);

// //free
// void				ft_free_2d_map(char **map);
int					ft_free_f(t_mini_map *game, char *error_msg);
void				ft_delete_image(t_mini_map *game);
void				ft_delete_texture(t_mini_map *game);
int					max_len(t_mini_map *game);
void				ft_ext_prg(char *mess_out);

#endif
