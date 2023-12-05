
#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"

# define WIDTH 2048
# define HEIGHT 2048
# define BLOCK_SIZE 64
# define PI 3.1415926535


typedef struct s_main
{
	struct s_math *math;
	mlx_t		*mlx;
	mlx_image_t	*image;
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*player;
	char		**map;
	char		*map_name;
	int			*player_pos;
	int			map_line;
	
}	t_main ;

typedef struct s_math
{
	t_main	*main;
	float	pX;
	float	pY;
	float	pdX;
	float	pdY;
	float	pa;

	
}			t_math;

// typedef struct s_math
// {
// 	double	posX;
// 	double	posY;
// 	double	dirX;
// 	double	dirY;
// 	double	planeX;
// 	double	planeY;
// 	double	time;
// 	double	oldTime;;
// }			t_math;

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

void 			ft_hook(void* param);
//void 			init_math_data(t_main *main);
void			move_hook_callback(mlx_key_data_t keydata, void *param);
int 			render_blocks(t_main *main, char **map);
int				render_player(t_main *main, char **map);

mlx_image_t 	*create_block_image(int block_type, t_main *main);
mlx_image_t 	*create_player_image(t_main *main);







#endif