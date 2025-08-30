/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:20:54 by ybounite          #+#    #+#             */
/*   Updated: 2025/08/30 11:25:50 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libraries/getline/get_next_line.h"
# include "../../libraries/libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define CLEAR 0
# define ALLOC 1
# define STDERR 2

# define WINDOW_WIDTH 1280 // cols
# define WINDOW_HEIGHT 736 // rows
# define TILE_SIZE 64
# define PI 3.141592653589793
# define FOV 1.0471975511965976
# define MOVE_SPEED 5
# define ROTATION_SPEED 0.2618
# define NUM_RAYS 200

# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define GRAY 0x808080
# define DARK_GRAY 0x404040

# define NONE 0
# define HORIZONTAL 1
# define VERTICAL 2

typedef enum s_texture_type
{
	NO_TEXTURE,
	SO_TEXTURE,
	WE_TEXTURE,
	EA_TEXTURE,
	C_COLOR,
	F_COLOR,
	IDNTIFIER_TEXTURE,
	TEXTURE_COUNT
}			t_texture_type;

typedef enum s_keycodes
{
	W_KEY = 'w',
	A_KEY = 'a',
	S_KEY = 's',
	D_KEY = 'd',
	ESCAPE = 65307,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363
}		t_keycodes;

typedef enum s_spawm_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}			t_spawm_dir;

typedef struct s_config
{
	char		*textures[TEXTURE_COUNT];
	int			floor_color;
	int			ceiling_color;
}			t_config;

typedef struct s_player
{
	double		_x;
	double		_y;
	double		angle;
}			t_player;

typedef struct s_point
{
	double		x;
	double		y;
}			t_point;

typedef struct s_imag
{
	void		*img;
	char		*addr;
	int			bit_per_pixel;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
}			t_imag;

typedef struct s_ray
{
	double		ray_angle;
	double		step_angle;
	double		distance;
	double		h_distance;
	double		v_distance;
	int			was_hit_vertical;
	double		dist_proj_plane;
	int			wall_type;
	t_point		ray_dir;
	t_point		player;
	t_point		first_inters_h;
	t_point		first_inters_v;
	t_point		step_h;
	t_point		step_v;
	t_point		hit;
	t_point		v_inters;
	t_point		h_inters;
}			t_ray;

typedef struct s_texture
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_imag		*no_img;
	t_imag		*so_img;
	t_imag		*we_img;
	t_imag		*ea_img;
}			t_texture;

typedef struct s_wall_slice
{
	bool		is_door;
	double		perp_dist;
	double		wall_height;
	double		alpha;
	int			wall_top;
	short		i;
	int			wall_bottome;
	int			tex_x;
	int			tex_y;
}			t_data_slice;

typedef struct s_vars
{
	int				x;
	int				y;
	int				center_x;
	int				center_y;
	int				radius;
}					t_vars;

typedef struct s_game
{
	bool			is_door;
	bool			is_door_h;
	bool			is_door_v;
	bool			h_found;
	bool			v_found;
	bool			clos_win;
	short			fd;
	short			size;
	char			**map;
	void			*_mlx;
	void			*_win_mlx;
	char			spawm_dir;
	t_imag			*_img;
	t_list			*list;
	t_list			*map_start;
	t_config		*config;
	t_player		*player;
	t_ray			ray;
	t_texture		*texture;
	int				map_width;
	int				map_height;
}					t_data_game;

/* -------------------------------------------------------------------------- */
/*                             check_file_name.c                              */
/* -------------------------------------------------------------------------- */
bool			check_filename(char *file_name, char *str);
void			check_file_name(char *file_name);

/* -------------------------------------------------------------------------- */
/*                             syntax_error.c                                 */
/* -------------------------------------------------------------------------- */
void			syntax_error(short option);

/* -------------------------------------------------------------------------- */
/*                             config_parser.c                                */
/* -------------------------------------------------------------------------- */
bool			parse_config(t_data_game *_game);
char			**parse_map(t_data_game *_game);
bool			parsing(char *filename, t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             parse_maps.c                                   */
/* -------------------------------------------------------------------------- */
t_list			*listnew(void *content);
t_list			*file_reading(short fd);
t_texture_type	get_texturs_type(char *line);

/* -------------------------------------------------------------------------- */
/*                             mlx_utils.c                                    */
/* -------------------------------------------------------------------------- */
void			my_mlx_pixel_put(t_imag *_img, int x, int y, int color);
void			clear_image(t_imag *img, int color);
/* -------------------------------------------------------------------------- */
/*                             render_background.c                            */
/* -------------------------------------------------------------------------- */
void			draw_sky_and_floor(t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             angle_direction.c                              */
/* -------------------------------------------------------------------------- */
void			normalize_angle(double *angle);
bool			is_facing_down(double angle);
bool			is_facing_up(double angle);
bool			is_facing_right(double angle);
bool			is_facing_left(double angle);

/* -------------------------------------------------------------------------- */
/*                            horizontal_intersection.c                       */
/* -------------------------------------------------------------------------- */
bool			cast_horizontal(t_data_game *g, t_ray *ray, t_point *hit,
					double *dist);
bool			is_within_map_bounds(t_data_game *_game, t_point next);
t_point			get_horizontal_ray_step(t_ray *ray);
t_point			get_first_horizontal_intercept(t_ray *ray);

/* -------------------------------------------------------------------------- */
/*                            vertical_intersection.c                         */
/* -------------------------------------------------------------------------- */
bool			cast_vertical(t_data_game *g, t_ray *ray, t_point *hit,
					double *dist);	
t_point			get_vertical_ray_step(t_ray *ray);
t_point			get_first_vertical_intercept(t_ray *ray);

/* -------------------------------------------------------------------------- */
/*                          collision_check.c 				      */
/* -------------------------------------------------------------------------- */
bool			_hase_wall(t_data_game *_game, double dx, double dy);
bool			is_wall(t_data_game *_game, double x, double y);

/* -------------------------------------------------------------------------- */
/*                          wall_renderer.c 				      */
/* -------------------------------------------------------------------------- */
void			_render_wall_slice(t_data_game *g, t_ray *ray, int i);
int				get_tex_x(t_ray *ray, t_imag *textuer);
void			draw_wall_strip(t_data_game *_g, t_ray *ray, t_imag *tex,
					t_data_slice sd);

/* -------------------------------------------------------------------------- */
/*                          ptexture_management.c			      */
/* -------------------------------------------------------------------------- */
unsigned int	get_pixel(t_imag *tex, int x, int y);
t_imag			*choose_texture(t_data_game *g, t_ray *ray);
unsigned int	blend_color(unsigned int src, unsigned int bg,
					double alpha);

/* -------------------------------------------------------------------------- */
/*                          player_control.c 		    		      */
/* -------------------------------------------------------------------------- */
int				control_key_(int keycode, t_data_game *_game);
void			_player_move(int key, t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                          ray_casting.c 				      */
/* -------------------------------------------------------------------------- */
void			_cast_all_rays(t_data_game *g);
void			cast_ray(t_data_game *g, t_ray *ray);

/* -------------------------------------------------------------------------- */
/*                           init player 			  	      */
/* -------------------------------------------------------------------------- */
void			player_position(t_data_game *_game);
void			init_player_direction(t_data_game *_game, char spawn_dir);
void			player_init(t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                              check_allowed_characters.c	  	      */
/* -------------------------------------------------------------------------- */
bool			check_allowed_characters(t_data_game *_game);
bool			isplayer_position(char c);

bool			parse_texture_line(t_data_game *_game, char *line);
t_texture_type	get_texturs_type(char *line);

/* -------------------------------------------------------------------------- */
/*                             control keypriss                               */
/* -------------------------------------------------------------------------- */
int				_destory_window(t_data_game *_game);
int				control_key_(int keycode, t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             validate_textures.c                            */
/* -------------------------------------------------------------------------- */
void			validate_textures(t_config *_config);
bool			check_filename_xpm(char *file_name, char *str);
int				shift_color(int r, int g, int b);
bool			validate_colors(t_config *_config, t_data_game *_game);
void			check_spaces(t_config *_config);

/* -------------------------------------------------------------------------- */
/*                             _mlx_init  			              */
/* -------------------------------------------------------------------------- */
bool			_mlx_init_data(t_data_game *_game);
bool			start_simulation(t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             validate_textures.c                            */
/* -------------------------------------------------------------------------- */
void			map_is_closed(char **map, short size);
bool			is_valid_map(t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             casr_all_rays.c                                */
/* -------------------------------------------------------------------------- */
void			cast_all_rays(t_data_game *_game);
void			raycasting(t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             init_textures.c                                */
/* -------------------------------------------------------------------------- */
bool			init_textures_data(t_data_game *_game);
bool			init_textures_address(t_texture *texture);
void			init_textures(t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             destroy_image.c                                */
/* -------------------------------------------------------------------------- */
bool			close_window(t_data_game *game);
void			destroys_images(t_data_game *_g);
void			_exit_with_error(void);

void			validate_textures_and_colors(t_config *_config,
					t_data_game *_game);

/* -------------------------------------------------------------------------- */
/*                             validate_map_utils.c                           */
/* -------------------------------------------------------------------------- */
bool			is_valid_cell(char c);
bool			check_map_if_closed(t_data_game *_game);
bool			check_top_and_bottum(t_data_game *_game);
bool			check_right_and_left(t_data_game *_game);
int				ft_count(const char *str);
char			*remove_space(char *str);

void			check_colors(t_config *config, int i);

struct s_game	*data_struc(void);
#endif
