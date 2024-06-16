/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnsaka <pnsaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/16 00:49:56 by pnsaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum s_mm_mlx_images
{
	WALL,
	FLOOR,
	NUM_OF_IMAGE
}					t_mm_mlx_images;

typedef struct s_load_pos
{
	int				i;
	int				j;
	int				x;
	int				y;
}					t_load_pos;


typedef struct s_game
{
	char			**map;
	int				height;
	int				width;

	mlx_texture_t	*arr_txtur[NUM_OF_IMAGE];
	mlx_image_t		*arr_img[NUM_OF_IMAGE];
	mlx_t			*mlx;
	mlx_key_data_t	keydata;

}					t_game;

/*====================================================*/
/*=                     mini_map                     =*/
/*====================================================*/

void	ft_arr_texture(t_game *game);
void	ft_texture_to_image(t_game *game);
void	ft_load_png_utlis(t_game *game, t_load_pos *var);
void	ft_load_png(t_game *game, t_load_pos *var);
void	ft_player_moves(mlx_key_data_t keydata, void *param);
int		ft_init(t_game *game);
t_game	*init_game(char *file_path);



#endif