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

typedef enum e_color
{
	TRANSPARENT = 0x00000000,
	TRANSLUCENT = 0x0000007F,
	WHITE = 0xFFFFFFFF,
	BLACK = 0x000000FF,
	RED = 0xFF0000FF,
	GREEN = 0x00FF00FF,
	BLUE = 0x0000FFFF,
	YELLOW = 0xFFFF00FF,
	GRAY = 0x808080FF,
	ORANGE = 0xFFA500FF,
	PURPLE = 0xFF00FFFF,
	CYAN = 0x00FFFFFF,
	PINK = 0xFFC0CBFF,
	BROWN = 0xA52A2AFF,
	SKYBLUE = 0x87CEEBFF,
	LIGHT_GRAY = 0xBBBBBBFF,
	LIGHT_BLUE = 0xADD8E6FF,
	LIGHT_GREEN = 0x90EE90FF,
	LIGHT_YELLOW = 0xFFFFE0FF,
	LIGHT_ORANGE = 0xFFDAB9FF,
	LIGHT_PURPLE = 0xE6E6FAFF,
	LIGHT_SKYBLUE = 0x87CEFAFF,
	DARK_GRAY = 0x404040FF,
	DARK_BLUE = 0x00008BFF,
	DARK_GREEN = 0x006400FF,
	DARK_RED = 0x8B0000FF,
	DARK_ORANGE = 0xFF8C00FF,
	DARK_PURPLE = 0x800080FF,
	DARK_PINK = 0xFF1493FF,
	DARK_YELLOW = 0xBDB76BFF,
	DARK_SKYBLUE = 0x00BFFFFF,
}					t_color;

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

typedef struct s_point
{
	int x;
	int y;
} 				t_point;


typedef struct s_lh_point
{
	int	sx;
	int	sy;
	int dx;
	int dy;
	int x;
	int y;
	int err;
	int e2;
}			t_lh_point;

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

	int					tile_size_x;
	int					tile_size_y;
	int					tile_size;

	double				player_x;
	double				player_y;
	double				delta_x;
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
	double					map_x;
	double					map_y;
	double				perp_dist;
	int					side;
	double				wall_dist;
	int					line_height;
	int					vert_view;
	int					draw_start;
	int					draw_end;
	double				wall_x;
	double				ray_dx;
	double				ray_dy;
	double				fov_ratio;

	int					tex_x;
	int					tex_y;
	double				tex_pos;
	double				tex_step;
	int					tex_num;
	mlx_texture_t		*tex;
	mlx_texture_t		*textures[4];
	int					color;

	double				mspeed;

	double				mov_speed;
	double				rot_speed;
	mlx_image_t			*background;
	mlx_image_t			*rayc_screen;
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
	// char					*n_tex;
	// char					*e_tex;
	// char					*s_tex;
	// char					*w_tex;
}							t_texture;

typedef struct s_rgb
{
	int						side;
	char					*path;
	int						red;
	int						green;
	int						blue;
	struct s_rgb			*next;
}							t_rgb;

typedef struct s_info_file
{
	char					**v_map;
	t_texture				*v_texture;
	char					*n_tex;
	char					*e_tex;
	char					*s_tex;
	char					*w_tex;
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
