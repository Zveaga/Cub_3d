/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cube3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: raanghel <raanghel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 18:18:16 by raanghel      #+#    #+#                 */
/*   Updated: 2024/01/25 14:56:36 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# define WIDTH 1700
# define HEIGHT 1400
# define ROT_SPEED 0.03
# define MOV_SPEED 0.06

//((int)((float)WIDTH / (4.0 / 3.0)))

typedef struct s_main
{
	mlx_t			*mlx;
	uint32_t		**image_buffer;
	mlx_image_t		*image;
	mlx_image_t		*north_texture_img;
	mlx_image_t		*south_texture_img;
	mlx_image_t		*west_texture_img;
	mlx_image_t		*east_texture_img;
	int32_t			**north_tex_pixel_grid;
	int32_t			**south_tex_pixel_grid;
	int32_t			**west_tex_pixel_grid;
	int32_t			**east_tex_pixel_grid;
	char			**map;
	char			*map_name;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				*ceiling_c;
	int				*floor_c;
	int				*player_pos;
	int				map_line;
	char			direction;
	struct s_math	*math;
}					t_main;

typedef struct s_math
{
	struct s_main	*main;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
	int				line_height;
	int				line_start;
	int				line_end;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	double			step;
	double			tex_pos;
}					t_math;

// int	ft_check_map(char *argv);
int			ft_map_parsing(int argc, char **argv, t_main *main);
int			ft_check_map_name(char	*map_name);
int			ft_map_checking(char *map_name, t_main *main);
int			fill_map(t_main *main, int fd);
int			check_credentials_value(t_main *main, char *s);
int			check_commas(char *s);
int			flood_fill(t_main *main, int x, int y, char find);
int			path_check(t_main *main, char	*s, char face);
void		assign_color(t_main *main, char **spl_col, char f_or_c);
int			ft_check_map_name(char	*map_name);
int			ft_all_number(char *s);
int			check_credentials(t_main *main);
int			check_if_input_are_valid(char **map);
int			find_player_start(t_main *main);
int			create_map(t_main *main);
int			ft_isspace(char *s);
int			put_texture(t_main *main);
int			add_texture(t_main *main);

// free
void		ft_free_double(char		**double_arr);
void		ft_main_free(t_main *main);
void		free_static_char_buff(int fd);
void		free_pixel_grids(t_main *main);
void		free_image_buffer(uint32_t **img_buf);
//---------------RARES---------------//

void		renderer(void *param);
int			init_image_buffer(t_main *main);
void		move_hook_callback(mlx_key_data_t keydata, void *param);
void		calculate_per_vertical_line(t_math *math, int x);

int			render_blocks(t_main *main, char **map);
int			render_player(t_main *main, char **map);
int32_t		set_color(int r, int g, int b, int a);
void		draw_single_vert_line(t_main *main);
void		fill_image_buffer(t_main *main, t_math *math, int x);
void		move_right(t_main *main, t_math *math);
void		move_left(t_main *main, t_math *math);
void		move_up(t_main *main, t_math *math);
void		move_back(t_main *main, t_math *math);
void		turn_right(t_math *math);
void		turn_left(t_math *math);
void		clear_image_buffer(t_main *main);
void		fill_ceiling_floor(t_main *main);
void		set_player_direction(t_math *math);
int			load_wall_textures(t_main *main);
void		print_map(char **map);
void		print_pixel_grid(int32_t **pixel_grid);
void		revert_map_to_original_symbols(char **map);
void		calculate_tex(t_main *main, t_math *math);
int			init_pixel_grids(t_main *main);
void		convert_pixels_to_grids(t_main *main);
void		fill_img_buffer(t_main *main, t_math *math, \
					int x, int32_t **texture);
mlx_image_t	*create_block_image(int block_type, t_main *main);
mlx_image_t	*create_player_image(t_main *main);
mlx_image_t	*create_line_image(t_main *main);

#endif