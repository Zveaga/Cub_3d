
#include "cube3d.h"


static void init_math(t_main *main, t_math *math)
{
	math->posX = main->player_pos[0] * BLOCK_SIZE;
	math->posY = main->player_pos[1] * BLOCK_SIZE;
	math->dirX = -1;
	math->dirY = 0;
	math->planeX = 0;
	math->planeY = 0.66;
}

void ft_hook(void* param)
{
	t_main	*main;

	main = param;

	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(main->mlx);
		exit(EXIT_SUCCESS);
	}
	mlx_resize_image(main->floor, main->mlx->width, main->mlx->height);
	mlx_resize_image(main->ceiling, main->mlx->width, main->mlx->height / 2.5);
	// if (mlx_is_key_down(main->mlx, MLX_KEY_W))
	// 	main->player->instances[0].y -= 5;
	// if (mlx_is_key_down(main->mlx, MLX_KEY_S))
	// 	main->player->instances[0].y += 5;
	// if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	// 	main->player->instances[0].x -= 5;
	// if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	// 	main->player->instances[0].x += 5;
}


int ft_pixel(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_color_ceiling(void *param)
{
	t_main		*main;
	uint32_t	color;
	uint32_t	i;
	uint32_t	y;

	main = param;
	i = 0;
	if (!main)
		return ;
	while (i < main->ceiling->width)
	{
		y = 0;
		while (y < main->ceiling->height)
		{
			color = ft_pixel(main->ceiling_color[0], main->ceiling_color[1], main->ceiling_color[2], 255);
			mlx_put_pixel(main->ceiling, i, y, color);
			y++;
		}
		i++;
	}
}
void	ft_color_floor(void *param)
{
	t_main *main;
	uint32_t color;
	uint32_t i;
	uint32_t y;

	main = param;
	if (!main)
		return ;
	i = 0;
	while (i < main->floor->width)
	{
		y = 0;
		while (y < main->floor->height)
		{
			color = ft_pixel(main->floor_color[0], main->floor_color[1], main->floor_color[2], 255);
			mlx_put_pixel(main->floor, i, y, color);
			y++;
		}
		i++;
	}
}

mlx_image_t *create_wall(t_main *main)
{
	uint32_t	i;
	uint32_t	j;
	int	color;
	mlx_image_t	*block_image;

	i = 0;
	block_image = mlx_new_image(main->mlx, 100, 100);
	if (!block_image)
		return (mlx_close_window(main->mlx), NULL);
	while (i < block_image->height)
	{
		j = 0;
		while (j < block_image->width)
		{
			color = ft_pixel(0, 0, 0, 255);
			mlx_put_pixel(block_image, i + block_image->height / 2, j + block_image->height / 2, color);
			j++;
		}
		i++;
	}
	return (block_image);
}
void	init_main(t_main *main)
{
	main->ceiling = NULL;
	main->floor = NULL;
	main->map = NULL;
	main->map_name = NULL;
	main->north_texture = NULL;
	main->south_texture = NULL;
	main->west_texture = NULL;
	main->east_texture = NULL;
	main->ceiling_color = NULL;
	main->floor_color = NULL;
	main->player_pos = NULL;
	main->map_line = -1;
}

int main(int argc, char **argv)
{
	t_main	main;
	t_math	math;

	init_main(&main);
	if (ft_map_parsing(argc, argv, &main))
		return (ft_main_free(&main), EXIT_FAILURE);
	init_math(&main, &math);
	// int i = 0;
	// while (main.map && main.map[i])
	// 	printf("%s", main.map[i++]);
	main.mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", true);
	if (main.mlx == NULL)
		return (EXIT_FAILURE);
	// main.floor = mlx_new_image(main.mlx, main.mlx->width, main.mlx->height);
	// if (!main.floor)
	// 	return (mlx_close_window(main.mlx), exit(EXIT_FAILURE), EXIT_FAILURE);
	// if (mlx_image_to_window(main.mlx, main.floor, 0, 0) == -1)
	// 	return (mlx_close_window(main.mlx), exit(EXIT_FAILURE), EXIT_FAILURE);
	// main.ceiling = mlx_new_image(main.mlx, main.mlx->width, main.mlx->height);
	// if (!main.ceiling)
	// 	return (mlx_close_window(main.mlx), exit(EXIT_FAILURE), EXIT_FAILURE);
	// if (mlx_image_to_window(main.mlx, main.ceiling, 0, 0) == -1)
	// 	return (mlx_close_window(main.mlx), exit(EXIT_FAILURE), EXIT_FAILURE);
	// main.wall = create_wall(&main);
	// mlx_image_to_window(main.mlx, main.wall, 20 * BLOCK_SIZE, 20 * BLOCK_SIZE);
	// // mlx_loop_hook(main.mlx, &render, &main);
	// // render_blocks(&main, main.map);
	// mlx_loop_hook(main.mlx, ft_hook, &main);
	// mlx_loop_hook(main.mlx, ft_color_floor, &main);
	// mlx_loop_hook(main.mlx, ft_color_ceiling, &main);
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ft_main_free(&main);
	return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
