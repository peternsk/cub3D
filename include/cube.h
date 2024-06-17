/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peternsaka <peternsaka@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:21:42 by peternsaka        #+#    #+#             */
/*   Updated: 2024/06/16 22:17:37 by peternsaka       ###   ########.fr       */
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
	int				player_x;
	int				player_y;

	mlx_texture_t	*arr_txtur[NUM_OF_IMAGE];
	mlx_image_t		*arr_img[NUM_OF_IMAGE];
	mlx_t			*mlx;
	mlx_key_data_t	keydata;

}					t_game;

/*====================================================*/
/*=                     mini_map                     =*/
/*====================================================*/

t_game	*init_game(char *file_path);
int		ft_count_line(char *file_path);



#endif
