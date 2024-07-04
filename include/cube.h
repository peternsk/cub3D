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
int							ft_count_line(char *file_path);

// mlx
void	ft_player_moves(mlx_key_data_t keydata, void *param);

// player move
bool						move_check(t_cube *game, int x, int y);
void						move_up(t_cube *game);
void						move_down(t_cube *game);
void						move_left(t_cube *game);
void						move_right(t_cube *game);

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
t_info_file					 *init_info(void);
t_texture					*four_texture(char **file);
long long int				atoi_long(const char *str);
bool						is_int(long long int nb);
bool						is_all_nb_int(char **tab_nb);
int							type_texture(char *str);
t_rgb						*two_rgb(char **map);
t_player					*is_player(char **map);
char    					**square_map(t_info_file *info);

void						create_background_celling(t_cube *game);
void						background(t_cube *game);
void						rotate_player(t_cube *game, double rot);
t_cube					*ft_mini(t_info_file *info);
int							get_rgba(int r, int g, int b, int a);
int							max_len(int height, char **map);
void						set_minimap(t_cube *game);
void						minimap_tile(t_cube *game, int x, int y);

int							map_height(char **map);

t_rect_data					init_rect(int x, int y, int w, int h);
void						set_rectangle(mlx_image_t *image, t_rect_data rect, int color);

#endif
