
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


# define WIDTH 1080
# define HEIGHT 1080

//((int)((float)WIDTH / (4.0 / 3.0)))

typedef struct s_main
{
	struct s_math *math;
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	mlx_image_t	*dir_line;
	char		**map;
	char		*map_name;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			*ceiling_color;
	int			*floor_color;
	int			*player_pos;
	int			map_line;
	uint32_t	**image_buffer;

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
	int		hit_wall;
	int		side;
	
	int		lineHeight;
	int		startPixel;
	int		endPixel;

	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
    double	sideDistY;
	double	perpWallDist;


}			t_math;

// int	ft_check_map(char *argv);
int		ft_map_parsing(int argc, char **argv, t_main *main);
int		ft_check_map_name(char	*map_name);
int		ft_map_checking(char *map_name, t_main *main);
int		check_if_input_are_valid(char **map);
int		find_player_start(t_main *main);
int		create_map(t_main *main);

// free
void	ft_free_double(char	**double_arr);
void	ft_main_free(t_main *main);
void	free_static_char_buff(int fd);


//---------------RARES---------------//


void			renderer(void *param);
void			init_image_buffer(t_main *main);
void			move_hook_callback(mlx_key_data_t keydata, void *param);
void 			calculate_per_vertical_line(t_math *math, int x);
int 			render_blocks(t_main *main, char **map);
int				render_player(t_main *main, char **map);
int32_t			set_color(int r, int g, int b, int a);
void 			draw_single_vert_line(t_main *main);
void			fill_image_buffer(t_main *main, t_math *math, int x);



mlx_image_t 	*create_block_image(int block_type, t_main *main);
mlx_image_t 	*create_player_image(t_main *main);
mlx_image_t 	*create_line_image(t_main *main);







#endif