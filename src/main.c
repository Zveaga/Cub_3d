
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
	if (!main)
		return ;
	y = 0;
	while (y < main->ceiling->height / 2)
	{
		i = 0;
		while (i < main->ceiling->width)
		{
			color = ft_pixel(main->ceiling_color[0], main->ceiling_color[1], main->ceiling_color[2], 255);
			mlx_put_pixel(main->ceiling, i, y, color);
			i++;
		}
		y++;
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
	y = 0;
	while (y < main->floor->height / 2)
	{
		i = 0;
		while (i < main->floor->width / 2)
		{
			color = ft_pixel(main->floor_color[0], main->floor_color[1], main->floor_color[2], 255);
			mlx_put_pixel(main->floor, i, y, color);
			i++;
		}
		y++;
	}
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
	ft_color_floor(main);
	ft_color_ceiling(main);
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
	mlx_loop(main.mlx);
	mlx_terminate(main.mlx);
	ft_main_free(&main);
	return (exit(EXIT_SUCCESS), EXIT_SUCCESS);
}
