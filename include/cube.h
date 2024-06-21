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
#define PI 3.1415926535

typedef struct s_info_file t_info_file;
typedef struct s_rgb t_rgb;
typedef struct s_texture t_texture;

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
	int				player_dx;
	int				player_y;
	int				player_dy;
	int				player_a;
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

// pars_map
// pourrait etre la struct

bool    		filename(char *file);
t_info_file 	*valide_map(char *file);
char    		**getfile(char *file);
bool    		pathtexture(char *data);
bool    		wallscolors(char *data);
char    		**getmap(char **files);
char    		**removenewline(char **map);
bool    		close_by_one(char **map);
bool    		looking_for_six(char *s, char x);
int     		size_len(char **map);
void    		err(char *str);
bool    		look_space(char **map);
bool    		six_char_invalide(char  **map);
int				ft_isupper(int c);
char			*get_next_line(int fd);
bool    		ft_strcmp(char *s1, char *s2);
void			free_sstr(char **str);
t_info_file 	*init_info();
t_texture		*four_texture(char   **file);
long long int	atoi_long(const char *str);
bool			is_int(long long int nb);
bool			is_all_nb_int(char **tab_nb);
int				type_texture(char   *str);
t_rgb			*two_rgb(char **map);

enum direction
{
	nord,
	south,
	west,
	east,
	_floor,
	ceiling,
};

typedef struct s_texture
{
	int	side;
	char *path;
	struct	s_texture *next;
}	t_texture;

typedef struct s_rgb
{
	int	side;
	char *path;
	int	one;
	int	two;
	int	three;
	struct	s_rgb *next;
}	t_rgb;


typedef struct s_info_file
{
	char		**v_map;
	t_texture	*v_texture;
	t_rgb		*v_rgb;
}	t_info_file;

#endif
