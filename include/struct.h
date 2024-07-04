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


typedef struct s_cube
{
	t_info_file			 *info;
	char				**map;
	int					mini_height;
	int					mini_width;
	int					wind_height;
	int					wind_width;

	int					playing;
	int					game_over;

	int					x;
	int					y;

	double				player_x;
	double				delta_x;
	double				player_y;
	double				delta_y;
	double				player_a;
	double				ray_dir_x;
	double				ray_dir_y;
	double				dir_x;
	double				dir_y;
	double				cam_x;
	double				cam_y;
	double				plane_x;
	double				plane_y;

	int					step_x;
	int					step_y;
	double 				side_dist_x;
	double 				side_dist_y;
	int					map_x;
	int					map_y;
	double				perp_dist;
	int					side;
	double				wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	double				ray_dx;
	double				ray_dy;
	double				fov_ratio;

	double				mov_speed;
	double				rot_speed;
	mlx_image_t			*playr;
	mlx_image_t			*background;
	mlx_image_t			*minimap;
	mlx_image_t			*screen;
	mlx_image_t			*line;
	mlx_t				*mlx;
	mlx_key_data_t		keydata;
}						t_cube;

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

typedef struct s_rect_data
{
	int						x;
	int						y;
	int						w;
	int						h;

}							t_rect_data;

#endif
