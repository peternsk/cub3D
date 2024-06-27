#ifndef CUBE_H
# define CUBE_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "struct.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*====================================================*/
/*=                      DEFINE                      =*/
/*====================================================*/

# define MAP_SIZE 10
# define PI 3.1415926535
# define BPP sizeof(int32_t)
# define WINDOW_HEIGHT 640
# define WINDOW_WIDTH 1056

typedef struct s_info_file	t_info_file;
typedef struct s_rgb		t_rgb;
typedef struct s_texture	t_texture;
typedef struct s_player		t_player;


/*====================================================*/
/*=                      SO_LONG                     =*/
/*====================================================*/

int							ft_count_line(char *file_path);

// utils
bool						ft_map_to_arr(t_mini_map *game, int fd);
int							ft_count_line(char *file_path);
void						ft_p_position(t_mini_map *game);
void						ft_ext_position(t_mini_map *game);
bool						ft_arr_cpy(t_mini_map *game);
void						ft_flood_fill(int x, int y, t_mini_map *game);

// mlx
void						ft_load_png(t_mini_map *game, t_load_pos *var);
void	ft_load_png_utlis(t_mini_map *game, int x, int y);
void						ft_arr_texture(t_mini_map *image);
void						ft_texture_to_image(t_mini_map *game);
void	ft_player_moves(mlx_key_data_t keydata, t_mini_map	*game);

// player move
bool						move_check(t_mini_map *game, int x, int y);
void						move_up(t_mini_map *game);
void						move_down(t_mini_map *game);
void						move_left(t_mini_map *game);
void						move_right(t_mini_map *game);

// assembled functions
t_mini_map					*ft_mini(char *file_path);

// //free
// void				ft_free_2d_map(char **map);
int							ft_free_f(t_mini_map *game, char *error_msg);
void						ft_delete_image(t_mini_map *game);
void						ft_delete_texture(t_mini_map *game);
int							max_len(t_mini_map *game);
void						ft_ext_prg(char *mess_out);


/*====================================================*/
/*=                      CUBE 3D                     =*/
/*====================================================*/

bool						filename(char *file);
t_info_file					*valide_map(char *file);
char						**getfile(char *file);
bool						pathtexture(char *data);
bool						wallscolors(char *data);
char						**getmap(char **files);
char						**removenewline(char **map);
bool						close_by_one(char **map);
bool						looking_for_six(char *s, char x);
int							size_len(char **map);
void						err(char *str);
bool						look_newline(char **map);
bool						six_char_invalide(char **map);
int							ft_isupper(int c);
char						*get_next_line(int fd);
bool						ft_strcmp(char *s1, char *s2);
void						free_sstr(char **str);
t_info_file					*init_info(void);
t_texture					*four_texture(char **file);
long long int				atoi_long(const char *str);
bool						is_int(long long int nb);
bool						is_all_nb_int(char **tab_nb);
int							type_texture(char *str);
t_rgb						*two_rgb(char **map);
t_player					*is_player(char **map);

// the real cub3D
void						minimap(t_mini_map *game, t_load_pos *var);
void						create_background_celling(t_mini_map *game);
void						color_background(t_mini_map *game);
void						put_player(t_mini_map *game, t_load_pos *var);
void						rotate_player(t_mini_map *game, double rot);

#endif
