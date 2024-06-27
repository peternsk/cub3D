#ifndef STRUCT_H
# define STRUCT_H

# include "cube.h"

typedef struct s_info_file	t_info_file;
typedef struct s_rgb		t_rgb;
typedef struct s_texture	t_texture;
typedef struct s_player		t_player;

/*====================================================*/
/*=                 STRUCT && ENUM                   =*/
/*====================================================*/

typedef enum s_mm_images
{
	PLAYER,
	FLOOR,
	WALL,
	NUM_OF_IMAGE
}							t_mm_images;

enum						direction
{
	nord,
	south,
	west,
	east,
	_floor,
	ceiling,
};

typedef struct s_load_pos
{
	int						i;
	int						j;
	int						x;
	int						y;
}							t_load_pos;


typedef struct s_mini_map
{
	char					**map;

	int						height;
	int						width;
	int						wind_height;
	int						wind_width;
	int						playing;
	int						game_over;
	double					player_x;
	double					player_dx;
	double					player_y;
	double					player_dy;
	double					player_a;
	double					ray_dir_x;
	double					ray_dir_y;
	double					cam_plane_x;
	double					cam_plane_y;
	double					mov_speed;
	double					rot_speed;
	mlx_texture_t			*arr_txtur[NUM_OF_IMAGE];
	mlx_image_t				*arr_img[NUM_OF_IMAGE];
	mlx_image_t				*playr;
	mlx_image_t				*background;
	mlx_image_t				*line;
	mlx_t					*mlx;
	mlx_key_data_t			keydata;
}							t_mini_map;

typedef struct s_texture
{
	int						side;
	char					*path;
	struct s_texture		*next;
}							t_texture;

typedef struct s_rgb
{
	int						side;
	char					*path;
	int						one;
	int						two;
	int						three;
	struct s_rgb			*next;
}							t_rgb;

typedef struct s_info_file
{
	char					**v_map;
	t_texture				*v_texture;
	t_rgb					*v_rgb;
	char					**load_files;
	char					**fake_maps;
	int						height;
	int						width;
	t_player				*push_p;
}							t_info_file;

typedef struct s_player
{
	int						pos_x;
	int						pos_y;
	int						side;
}							t_player;

#endif