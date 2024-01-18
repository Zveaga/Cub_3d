
#include "cube3d.h"

static void init_math(t_main *main, t_math *math)
{
	math->posX = (double)main->player_pos[0] + 0.5;
	math->posY = (double)main->player_pos[1] + 0.5;
	main->math = math;
	math->main = main;
	set_player_direction(math);
}

void	init_main(t_main *main)
{
	main->map = NULL;
	main->map_name = NULL;
	main->north_texture = NULL;
	main->south_texture = NULL;
	main->west_texture = NULL;
	main->east_texture = NULL;
	main->ceiling_color = NULL;
	main->floor_color = NULL;
	main->player_pos = NULL;
	main->image = NULL;
	main->image_buffer = NULL;
	main->mlx = NULL;
	main->pixel_grid_north_tex = NULL;
	main->pixel_grid_south_tex = NULL;
	main->pixel_grid_west_tex = NULL;
	main->pixel_grid_east_tex = NULL;
	main->map_line = -1;
}

int	init_images(t_main *main)
{
	main->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!main->mlx)
		return (1);
	main->image = mlx_new_image(main->mlx, WIDTH, HEIGHT);
	if (!main->image)
		return (1);
	if (mlx_image_to_window(main->mlx, main->image, 0, 0) == -1)
		return (1);
	if (init_image_buffer(main) == 1)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_main	main;
	t_math	math;

	init_main(&main);
	if (ft_map_parsing(argc, argv, &main))
		return (ft_main_free(&main), EXIT_FAILURE);
	init_math(&main, &math);
	if (init_images(&main) == 1 || load_wall_textures(&main) == 1)
		return (ft_main_free(&main), EXIT_FAILURE);
	mlx_loop_hook(main.mlx, &renderer, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ft_main_free(&main);
	return (EXIT_SUCCESS);
}


//printf("HEIGHT: %d\n", HEIGHT);
// printf("posX: %.0f | %.f px \n", main.math->posX, WIDTH / main.math->posX);
// printf("posY: %.0f | %.f px\n", main.math->posY, HEIGHT / main.math->posY);
// printf("wallX: %d | %d px \n", 3, WIDTH / 3);
// printf("wallY: %d | %d px\n\n", 2, HEIGHT / 2);



// int ft_pixel(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void	ft_color_ceiling(void *param)
// {
// 	t_main		*main;
// 	uint32_t	color;
// 	uint32_t	i;
// 	uint32_t	y;

// 	main = param;
// 	if (!main)
// 		return ;
// 	y = 0;
// 	while (y < main->ceiling->height / 2)
// 	{
// 		i = 0;
// 		while (i < main->ceiling->width)
// 		{
// 			color = ft_pixel(main->ceiling_color[0], main->ceiling_color[1], main->ceiling_color[2], 255);
// 			mlx_put_pixel(main->ceiling, i, y, color);
// 			i++;
// 		}
// 		y++;
// 	}
// }
// void	ft_color_floor(void *param)
// {
// 	t_main *main;
// 	uint32_t color;
// 	uint32_t i;
// 	uint32_t y;

// 	main = param;
// 	if (!main)
// 		return ;
// 	y = 0;
// 	while (y < main->floor->height / 2)
// 	{
// 		i = 0;
// 		while (i < main->floor->width / 2)
// 		{
// 			color = ft_pixel(main->floor_color[0], main->floor_color[1], main->floor_color[2], 255);
// 			mlx_put_pixel(main->floor, i, y, color);
// 			i++;
// 		}
// 		y++;
// 	}
// }
