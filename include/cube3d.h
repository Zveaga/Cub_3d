
#ifndef CUBE_H
# define CUBE_H

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
	int				*ceiling_color;
	int				*floor_color;
	int				*player_pos;
	int				map_line;
	char			direction;

	struct s_math *math;

}	t_main ;

typedef struct s_math
{
	struct	s_main	*main;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;

	double	cameraX;
	double	rayDirX;
	double	rayDirY;

	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		side;
	
	int		lineHeight;
	int		startPixel;
	int		endPixel;

	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
    double	sideDistY;
	double	perpWallDist;

	int		texNum;			// value of current map square - 1
	int		texX;  			// x coordinate of the texture 
	int		texY;  			// y coordinate of the texture 
	double	wallX; 			// exact value where the wall was hit
	double	step;
	double	texPos;




}			t_math;

// int	ft_check_map(char *argv);
int		ft_map_parsing(int argc, char **argv, t_main *main);
int		ft_check_map_name(char	*map_name);
int		ft_map_checking(char *map_name, t_main *main);
int		check_if_input_are_valid(char **map);
int		find_player_start(t_main *main);
int		create_map(t_main *main);
int		ft_isspace(char *s);
int		put_texture(t_main *main);
int		add_texture(t_main *main);

// free
void	ft_free_double(char	**double_arr);
void	ft_main_free(t_main *main);
void	free_static_char_buff(int fd);


//---------------RARES---------------//


void			renderer(void *param);
int				init_image_buffer(t_main *main);
void			move_hook_callback(mlx_key_data_t keydata, void *param);
void 			calculate_per_vertical_line(t_math *math, int x);
int 			render_blocks(t_main *main, char **map);
int				render_player(t_main *main, char **map);
int32_t			set_color(int r, int g, int b, int a);
void 			draw_single_vert_line(t_main *main);
void			fill_image_buffer(t_main *main, t_math *math, int x);

void			move_right(t_main *main, t_math *math);
void			move_left(t_main *main, t_math *math);
void			move_up(t_main *main, t_math *math);
void			move_back(t_main *main, t_math *math);
void			turn_right(t_math *math);
void			turn_left(t_math *math);
void 			clear_image_buffer(t_main *main);
void 			fill_ceiling_floor(t_main *main);
void			set_player_direction(t_math *math);
int 			load_wall_textures(t_main *main);
void 			print_map(char **map);
void			print_pixel_grid(int32_t **pixel_grid);

void			revert_map_to_original_symbols(char **map);
void			texture_calculations(t_main *main, t_math *math, int x, int32_t **texture);
int 			init_pixel_grids(t_main *main);
void			convert_pixels_to_grids(t_main *main);



mlx_image_t 	*create_block_image(int block_type, t_main *main);
mlx_image_t 	*create_player_image(t_main *main);
mlx_image_t 	*create_line_image(t_main *main);







#endif